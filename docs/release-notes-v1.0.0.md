## Bad Apple!! 字符画计算器 —— 课程作业提交版

本 Release 提供 **c2bad.exe**（由 `c2bad_fixed.cpp` 编译，Windows x64）。

### 怎么用

1. 下载 `c2bad.exe`，或直接 `git clone` 本仓库；
2. **把 exe 放在仓库根目录**（必须和 `out/` 文件夹同级），双击运行；
3. 输入 `+ - * /` 做四则运算，输入 `ba` 播放《Bad Apple!!》字符画彩蛋，`q` 退出。

> ⚠️ exe 不能单独运行：程序用相对路径读取 `out/BA (n).txt` 的 6571 帧数据，缺了 `out/` 会提示“打不开帧文件”。

### 产物校验

| 文件 | 大小 | SHA-256 |
| --- | --- | --- |
| `c2bad.exe` | 138788 字节 | `9535D55C8ADC3523A98349F23A92E5DD571CAAAFCACAE2C241AB933A423F93AE` |

编译环境：MinGW-w64 GCC 16.2.0，`-std=c++17 -O2 -Wall -Wextra`，控制台程序，仅依赖系统自带的 msvcrt。

### 本版包含的修复

- 彩蛋触发：`case 'ba'` 是多字符常量、永远不匹配 → 改为字符串比较 `"ba"`；
- 输入：`scanf("%c")` 残留换行导致第二轮必进 default → 改为按行读取；
- 帧缓冲：`buf[1920]` 越界写入 → 按真实 1944 字节读入并正确补 0；
- `fopen` 空指针判空；四则运算文案修正与除零判断；
- 计时：`clock()` 忙等 → `GetTickCount64()` 绝对时间轴 + `Sleep`，CPU 占用从 100% 降到接近 0；
- 源码 UTF-8 + `SetConsoleOutputCP(CP_UTF8)`，中文提示不乱码。

### 版权与许可

- **代码**：MIT（见 [LICENSE](https://github.com/fn28710/caculater/blob/main/LICENSE)）；
- **贡献者**：计算器 P.enHanceYu（[@fn28710](https://github.com/fn28710)），Bad Apple 动画函数 chuan —— 见 [CONTRIBUTORS.md](https://github.com/fn28710/caculater/blob/main/CONTRIBUTORS.md)；
- **`out/` 字符画帧数据**：非本项目原创，源自《Bad Apple!!》影绘 PV 的 2014 年字符画数据集，按东方Project 二次创作规约作非商业同人使用，**不适用 MIT**，详见 [NOTICE.md](https://github.com/fn28710/caculater/blob/main/NOTICE.md)。

本 Release 只提供自行编译的 `c2bad.exe`，不打包帧数据；请克隆仓库获取 `out/`。
