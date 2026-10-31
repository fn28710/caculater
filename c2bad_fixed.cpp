// ============================================================================
//  c2bad_fixed.cpp —— 「计算器 + Bad Apple!! 字符画」修复版
//
//  原始作业稿见同目录的 c2bad.cpp（保留原样，不做修改）。
//  本文件仅修复运行缺陷，界面与功能风格保持一致，新增 q 退出与除零保护。
//
//  修复清单：
//    1. 原版 switch 里写的是 case 'ba':，多字符常量永远不可能匹配，
//       彩蛋无法触发；改为字符串比较 "ba"。
//    2. 原版 scanf("%c") 会把上一轮的换行符吃进 ch，第二轮起必进 default；
//       改为按行读取（fgets）再解析。
//    3. 原版 char buf[1920] 却写 buf[1920] = '\0'，数组越界一位
//       （帧文件实际 1944 字节：80x24 字符 + 24 个 LF）；按实际长度读入并补 0。
//    4. 原版 fopen 之后不做空指针检查，缺帧文件会直接崩溃；补上错误提示。
//    5. 原版四个分支都打印「加法的结果是」，且除以 0 无保护；修正文案与除零。
//    6. 原版用 clock()（CPU 时间）掐帧，且 while(1) 永不退出；改用
//       GetTickCount64() 绝对时间轴 + Sleep()，不再占满一个 CPU 核心。
//
//  编译（MinGW-w64 / Dev-C++ / MSYS2）：
//      g++ -std=c++17 -O2 -Wall -o c2bad.exe c2bad_fixed.cpp
//  或者直接双击 build.bat。
//
//  运行要求：当前工作目录下必须有 out\BA (0).txt ... out\BA (6570).txt
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define FRAME_DIR   "out\\"   /* 帧数据目录（相对当前工作目录） */
#define FRAME_COUNT 6571       /* out\BA (0).txt ~ out\BA (6570).txt */
#define FRAME_BYTES 1944       /* 80 列 x 24 行 = 1920 字符 + 24 个 LF */
#define FRAME_MS    33         /* 每帧 33 ms，约 30 fps（6571 帧 ≈ 3 分 37 秒） */

static int  read_line(char *dst, int size);
static void trim(char *s);
static void move_cursor_to_origin(void);
static void run_bad_apple(void);

/* ---------------------------------------------------------------- 主函数 */
int main(void)
{
    /* 本文件以 UTF-8 保存；把控制台输出代码页切到 UTF-8，避免中文在 936 代码页下乱码 */
    SetConsoleOutputCP(CP_UTF8);

    char line[64];
    float a = 0.0f, b = 0.0f;
    char op = 0;

    for (;;) {
        printf("请输入你想要的计算方式（+ - * / ，输入 ba 播放彩蛋，输入 q 退出）\n");
        if (!read_line(line, (int)sizeof(line))) break;
        trim(line);
        if (line[0] == '\0') continue;
        if (line[0] == 'q' || line[0] == 'Q') break;

        if (strcmp(line, "ba") == 0 || strcmp(line, "BA") == 0) {
            run_bad_apple();
            continue;
        }

        if (strlen(line) != 1 || strchr("+-*/", line[0]) == NULL) {
            printf("错啦错啦，灵梦要来锤你啦：（\n");
            continue;
        }
        op = line[0];

        printf("请输入第一个数字\n");
        if (!read_line(line, (int)sizeof(line))) break;
        if (sscanf(line, "%f", &a) != 1) { printf("这不是一个数字。\n"); continue; }

        printf("请输入第二个数字\n");
        if (!read_line(line, (int)sizeof(line))) break;
        if (sscanf(line, "%f", &b) != 1) { printf("这不是一个数字。\n"); continue; }

        switch (op) {
        case '+': printf("加法的结果是%f\n", a + b); break;
        case '-': printf("减法的结果是%f\n", a - b); break;
        case '*': printf("乘法的结果是%f\n", a * b); break;
        case '/':
            if (b == 0.0f) printf("除数不能为 0。\n");
            else           printf("除法的结果是%f\n", a / b);
            break;
        default: break;
        }
    }

    Sleep(1000);
    return 0;
}

/* --------------------------------------------------------- 读一行并去掉换行 */
static int read_line(char *dst, int size)
{
    if (dst == NULL || size <= 0) return 0;
    if (fgets(dst, size, stdin) == NULL) { dst[0] = '\0'; return 0; }  /* EOF */
    dst[strcspn(dst, "\r\n")] = '\0';
    return 1;
}

/* ------------------------------------------------------------- 去掉首尾空白 */
static void trim(char *s)
{
    char *p = s;
    size_t n;

    while (*p == ' ' || *p == '\t') p++;
    if (p != s) memmove(s, p, strlen(p) + 1);

    n = strlen(s);
    while (n > 0 && (s[n - 1] == ' ' || s[n - 1] == '\t')) s[--n] = '\0';
}

/* --------------------------------------------------- 把光标挪回左上角（原地重绘） */
static void move_cursor_to_origin(void)
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD  coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(hout, coord);
}

/* ------------------------------------------------------------- Bad Apple 播放 */
static void run_bad_apple(void)
{
    char  frame[FRAME_BYTES + 2];
    char  path[64];
    FILE *fp;
    int   i;
    ULONGLONG start;

    printf("-----Bad Apple ASCII art player-----\nPress Enter to play.\n");
    if (!read_line(frame, (int)sizeof(frame))) return;   /* 等一个回车 */

    system("cls");
    start = GetTickCount64();

    for (i = 0; i < FRAME_COUNT; i++) {
        sprintf(path, FRAME_DIR "BA (%d).txt", i);

        fp = fopen(path, "rb");
        if (fp == NULL) {
            printf("\n[错误] 打不开帧文件：%s\n（请确认在含 out\\ 的目录下运行）\n", path);
            return;
        }
        {
            size_t got = fread(frame, 1, FRAME_BYTES, fp);
            frame[got] = '\0';
        }
        fclose(fp);

        printf("%s", frame);
        printf("Frame:%d", i + 1);
        move_cursor_to_origin();

        /* 绝对时间轴：到点再出下一帧，Sleep 让出 CPU */
        {
            ULONGLONG now    = GetTickCount64();
            ULONGLONG target = start + (ULONGLONG)(i + 1) * FRAME_MS;
            if (now < target) Sleep((DWORD)(target - now));
        }
    }

    system("cls");
    printf("-----Bad Apple ASCII art player-----\nThanks for watching!\nMade by chuan.\n\n");
    printf("Press Enter to Exit.\n");
    read_line(frame, (int)sizeof(frame));
}
