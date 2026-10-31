# Bad Apple!! 字符画计算器

> 一个 C/C++ 控制台课程作业：**四则运算计算器** + **用 6571 帧 ASCII 字符画播放《Bad Apple!!》** 的隐藏彩蛋。
>
> 作者：**P.enHanceYu**（GitHub: [@fn28710](https://github.com/fn28710)）· 代码以 MIT 许可发布
> 彩蛋素材：字符画帧来自外部 2014 数据集，**非本项目原创**（详见 [NOTICE.md](NOTICE.md)）

```
                                                 iMMMMMMMMMM
                                                  SMMMMMMMMMM;:;,
                                             ;aBMM@MMMMMMMMMMMMMMMMr
                                         .aMMMMMMMMMMMMMMMMMMMMMMMMM@
                                        0MMMMMMMMMMMMMMMMMMMMMMMMMMMMZ
                                       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM7
                                     :MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMi
                                     ;MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
                                      0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0
                                        7a@MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
                                         ,MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMr
                                         7MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0
                                 ,ZW00B87  ;MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
                              SMMMMMMMMMMM   0MMMMMMMMMMMMMMMMMMMMMMMMMMMM
                             ;MMMMMMMMMMMM:   WMMMM@MMMMMMMMMMMMMMMMMMMMMM
                             .MMMMMMMMMMMM,    MMMMMMMMMMMMMMMMMMMMMMaMMMM
                              7MMMMMMMMMMMMS   aMMMMMMMMMMMMMMMMMMMMM;,MZM2
                                2MMMMMMMMMMMW  SMMMMMMMMMMMMMMMMMMMMMM Sa,@
                                  XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMi@Ma  ;
                                 ;MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMZ rM
                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM7 i
                                SMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
                                MMMMMMMMMMM0ZMMMMMMMMMMMMMMMMMMMMMMM@      ,
                                MMMMMMMMMM. XMMMMMMMMMMMMMMMMMMMMMMMMi XBMMa
```

<sub>上图为 `out/BA (300).txt` 的真实内容（80 列 × 24 行），程序把光标移回左上角后逐帧覆盖重绘。</sub>

---

## ✨ 这是什么

一个 2024 年的 C 语言期末大作业。主体是一个最朴素的命令行四则运算计算器；额外埋了一个彩蛋：把《Bad Apple!!》影绘版 PV 转成 6571 帧字符画，以 30 fps 在控制台里"原地播放"。

| 项目 | 说明 |
| --- | --- |
| 语言 | C / C++（`.cpp`，代码主体是 C 风格） |
| 平台 | Windows（依赖 `windows.h` 控制台 API） |
| 帧数据 | `out/` 下 6571 个 `.txt`，每个 1944 字节（80×24 字符 + 24 个 LF） |
| 帧率 | 33 ms/帧 ≈ 30 fps，全片约 3 分 37 秒 |
| 依赖 | 无第三方库（仅 Windows 自带 API） |

## 🎮 功能

- **四则运算**：`+` `-` `*` `/`，浮点数输入，循环计算直到退出
- **彩蛋**：输入 `ba` → 播放《Bad Apple!!》字符画，播放结束回到菜单
- **退出**：输入 `q`（仅修复版支持）

## 🚀 快速开始

### 1. 克隆

```bash
git clone https://github.com/fn28710/caculater.git
cd caculater
```

### 2. 编译（Windows）

**方式 A：一键脚本（推荐，需要 MinGW-w64 的 `g++` 在 PATH 中）**

```bat
build.bat
```

**方式 B：手动 g++ / MSYS2**

```bash
g++ -std=c++17 -O2 -Wall -o c2bad.exe c2bad_fixed.cpp
```

**方式 C：Dev-C++** —— 打开 `c2bad_fixed.cpp`，直接"编译并运行"。

**方式 D：Visual Studio** —— 新建控制台项目，加入 `c2bad_fixed.cpp`，`x64` 编译即可（原文件里的
`#pragma comment(lib, "WINMM.LIB")` 是给 MSVC 用的，MinGW 会忽略）。

> **编码说明**：`c2bad_fixed.cpp` 以 **UTF-8（带 BOM）** 保存，并在启动时调用
> `SetConsoleOutputCP(CP_UTF8)`，所以中文提示在任何代码页下都不会乱码；Dev-C++ / VS Code
> 编辑器如果显示乱码，把文件编码切到 UTF-8 即可。`c2bad.cpp` 是课程提交时的 **GBK** 原件，
> 在 GitHub 网页上中文会显示为乱码，属正常现象（用中文 Windows 的 Dev-C++ 编译运行仍正常）。

### 3. 运行

必须在**项目根目录**运行（程序用相对路径 `out\\BA (n).txt` 读取帧数据）：

```bat
cd caculater
c2bad.exe
```

> 双击 `out` 里的文件或把 exe 拖到别处都会提示"打不开帧文件"，这不是 bug，是帧数据用相对路径。

## 🕹️ 使用说明

```
请输入你想要的计算方式（+ - * / ，输入 ba 播放彩蛋，输入 q 退出）
+                     ← 输入运算符
请输入第一个数字
1.5
请输入第二个数字
2.25
加法的结果是3.750000
```

想看彩蛋：

```
ba                    ← 回车
-----Bad Apple ASCII art player-----
Press Enter to play.  ← 再按一次回车开始
```

## 📁 项目结构

```
caculater/
├── c2bad.cpp            # 原始作业稿（课程提交版，保持原样；GBK 编码）
├── c2bad_fixed.cpp      # 修复版（推荐：彩蛋真正可触发，除零/越界/输入问题已修）
├── c1 - 副本.cpp         # 最早期只有计算器的备份版本
├── mainn.txt            # 早期草稿（纯计算器，含 % 取余，未编译）
├── build.bat            # MinGW 一键编译脚本
├── push-to-github.bat   # 一键上传 GitHub（建库 → push → 打 tag）
├── LICENSE              # 代码许可（MIT）
├── NOTICE.md            # 素材版权与二次创作声明（务必阅读）
├── README.md
├── docs/
│   ├── license-research.md    # ZUN 规约与许可选型调研
│   └── github-submission.md   # 上传 GitHub / 提交到 Project 的步骤
└── out/
    ├── BA (0).txt       # 第 1 帧
    ├── BA (1).txt
    ├── ...
    └── BA (6570).txt    # 第 6571 帧（共 6571 个文件，约 12 MB）
```

## 🔧 技术实现

**帧数据格式** —— 每个 `.txt` 是 24 行 × 80 列的纯字符画，行尾 `\n`，共 1944 字节。字符按灰度从密到疏取
`M @ W B S 0 8 Z a r X : ; ,` 等，因此"用字符画出来的影绘"在控制台里也能看出轮廓。

**原地重绘** —— 每帧输出后调用 `SetConsoleCursorPosition(0, 0)` 把光标移回左上角，下一帧直接覆盖，
不 `cls`，所以没有闪烁。

**帧率控制** —— 修复版用 `GetTickCount64()` 建立绝对时间轴（`start + (i+1)*33ms`），
到点再 `Sleep()` 补差；原版用的是 `clock()`（CPU 时间）+ 忙等，会占满一个核心。

**为什么没有声音** —— 原版 `#include <mmsystem.h>` 并链接了 `WINMM.LIB`，但从未调用任何音频函数。
想加 BGM 可以 `PlaySound("bad_apple.wav", NULL, SND_FILENAME | SND_ASYNC)`，注意音频本身同样有版权问题。

## 🐞 已知问题（原版 `c2bad.cpp`）

原稿作为课程提交版保留原样，以下问题均在 `c2bad_fixed.cpp` 中修复：

| # | 位置 | 问题 | 后果 |
| --- | --- | --- | --- |
| 1 | `switch(ch)` | `case 'ba':` 是多字符常量（值 `0x6261`），`ch` 是单个 `char`，**永远不可能相等** | 彩蛋根本进不去 |
| 2 | `scanf("%c", &ch)` | 上一轮残留的换行符被读进 `ch` | 第二次循环必进 `default` |
| 3 | `char buf[1920]` + `buf[1920]='\0'` | 数组越界写一位；且帧文件实际 1944 字节 | 未定义行为 |
| 4 | `fopen` 后未判空 | 缺帧文件时 `fread` 空指针崩溃 | 直接闪退 |
| 5 | 四个 `case` | 都打印"**加法**的结果"；`/` 不判除零 | 文案错误 / 输出 `inf` |
| 6 | `while(1)` + `clock()` | 永不退出；忙等占满 CPU；`Sleep(1000); return 0;` 是死代码 | 只能强杀进程 |

> 顺带一提：`-Wall` 下第 3 条会直接报警
> `warning: array subscript 1920 is above array bounds of 'char [1920]'`。

## 🧩 修复版改了什么

`c2bad_fixed.cpp` 与 `c2bad.cpp` 的功能、菜单、提示语完全一致，只做最小改动：

1. 输入改为按行读取（`fgets` + `strcspn` 去换行），彻底避开 `%c` 残留换行问题；
2. 彩蛋触发改为字符串比较 `"ba"`；
3. 帧缓冲按真实长度 `1944` 字节读入并正确补 `'\0'`；
4. `fopen` 判空并给出可读错误提示；
5. 修正四个运算的文案，除法补零判断；
6. 主循环支持 `q` 退出；计时改为绝对时间轴 + `Sleep`，CPU 占用从 100% 降到接近 0。

## 📜 版权与许可（务必阅读）

本项目**不是单一许可**的仓库，代码与素材的授权状态完全不同：

| 内容 | 许可 | 说明 |
| --- | --- | --- |
| **源代码**（`*.cpp`、`build.bat`、文档） | **MIT**（见 [LICENSE](LICENSE)） | 可自由使用、修改、再分发，保留版权声明即可 |
| **字符画帧数据**（`out/` 共 6571 个 `.txt`） | **不适用开源许可**，为非商业同人二次创作 | 版权归东方Project 及各层原作者，遵循 ZUN 二次创作规约，**禁止商业使用**，本项目不授予再分发许可 |

### 关于 ZUN 与东方Project

ZUN（上海アリス幻樂団）**没有**给东方Project 采用任何开源许可证 —— 它不是开源软件，也不存在
"ZUN 的开源协议"这回事。它采取的是**官方二次创作规约**：在不违反规约的前提下，允许任何人无需授权
创作并发布同人作品；规约要求正确署名、不得冒充官方、**禁止未经许可的商业分发**，并明确请求不要为
同人项目众筹（2016 年修订后允许上传游戏实况 / Let's Play 视频）。

### 关于《Bad Apple!!》的版权链

这个彩蛋踩在**多层版权**上，任何一层都不属于"可以随意开源"的素材：

1. **原曲**：《Bad Apple!!》，收录于《東方幻想郷 ～ Lotus Land Story》（1998），作曲 ZUN；
2. **同人改编**：《Bad Apple!! feat. nomico》，编曲 Masayoshi Minoshima / Alstroemeria Records（2007）；
3. **影绘 PV**：2009 年投稿于 NicoNico 的剪影动画，作者 あにら（Anira），是绝大多数"字符画复刻"的源头。

`out/` 中的 6571 帧即由该 PV 逐帧转换而来，属于上述作品的**演绎作品**。因此：

- ✅ 个人学习、课程作业、非商业分享：符合二次创作规约的通常范围；
- ⚠️ 公开仓库：建议保留 `NOTICE.md` 的非商业声明与署名，且不要商用、不要放进 Release 售卖；
- ❌ 把帧数据当作 MIT / CC0 素材再分发、商用、或用于 AI 训练集：明确不建议。

如果你希望仓库**零版权风险**，可以把 `out/` 加入 `.gitignore`、只提交代码与"如何生成帧数据"的说明，
README 里对应用一句"帧数据请自行生成"。详见 [NOTICE.md](NOTICE.md) 与
[docs/license-research.md](docs/license-research.md)。

## 🙏 致谢

- **ZUN / 上海アリス幻樂団** —— 东方Project 系列与《Bad Apple!!》原曲
- **Masayoshi Minoshima / Alstroemeria Records / nomico** —— 《Bad Apple!! feat. nomico》
- **あにら（Anira）** —— 广为流传的影绘版 PV
- 所有把《Bad Apple!!》搬进终端、计算器、示波器、智能冰箱的前辈们

## 📚 参考

- 东方Project 官方站点（上海アリス幻樂団）：<http://www16.big.or.jp/~zun/>
- ZUN 二次创作规约的通行描述与修订情况：<https://en.wikipedia.org/wiki/Touhou_Project_fandom>
- 《Bad Apple!!》作品条目：<https://en.wikipedia.org/wiki/Bad_Apple!!>
- 本仓库的许可选型调研：[docs/license-research.md](docs/license-research.md)

---

<details>
<summary>English (short)</summary>

A 2024 C/C++ console-course assignment: a plain four-function calculator with a hidden Easter egg that
plays 《Bad Apple!!》 as 6571 frames of 80×24 ASCII art at ~30 fps using Win32 cursor repositioning.

- **Code**: MIT (see [LICENSE](LICENSE)).
- **ASCII frames** (`out/`): *not* open-licensed — they are non-commercial fan art derived from the
  Touhou Project / Bad Apple!! shadow-art PV; all rights belong to ZUN (Team Shanghai Alice),
  Masayoshi Minoshima / Alstroemeria Records, and あにら (Anira). No redistribution license is granted.
- The Touhou Project has **no OSS license**; ZUN publishes a derivative-works guideline instead
  (attribution required, no unauthorized commercial use, no crowdfunding).

Build: `build.bat` (MinGW-w64) or `g++ -std=c++17 -O2 -o c2bad.exe c2bad_fixed.cpp`; run from the repo root.
</details>
