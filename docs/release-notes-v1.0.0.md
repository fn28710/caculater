## Bad Apple!! 字符画计算器 —— 课程作业提交版

提供两种下载，任选其一：

| 资产 | 说明 |
| --- | --- |
| **`caculater-v1.0.0-win64.zip`**（约 2.38 MB） | **下载即玩**：解压后双击 `caculater-v1.0.0\c2bad.exe` 即可，已包含 `out/` 6571 帧数据 |
| `c2bad.exe`（138788 字节） | 只要可执行文件；需放到仓库根目录（与 `out/` 同级）才能播放彩蛋 |

### 怎么用

1. 下载 **zip 完整包** 并解压（不要只把 exe 单独拿出来）；
2. 双击 `caculater-v1.0.0\c2bad.exe`；
3. 输入 `+ - * /` 做四则运算，输入 `ba` 播放《Bad Apple!!》字符画彩蛋，`q` 退出。

> ⚠️ 单文件 exe 不能单独运行：程序用相对路径读取 `out/BA (n).txt` 的 6571 帧数据，缺了 `out/` 会提示“打不开帧文件”。zip 包已带好帧数据，所以「下载即玩」。

### 产物校验

| 文件 | 大小 | SHA-256 |
| --- | --- | --- |
| `caculater-v1.0.0-win64.zip` | 2,493,864 字节 | `477DD96532C754E8E89D3D6DC3BE5E20815652B32E14B7061546A8DEAB4D328E` |
| `c2bad.exe` | 138788 字节 | `9535D55C8ADC3523A98349F23A92E5DD571CAAAFCACAE2C241AB933A423F93AE` |

编译环境：MinGW-w64 GCC 16.2.0，`-std=c++17 -O2 -Wall -Wextra`，控制台程序，仅依赖系统自带的 msvcrt。

### 本版包含的修复

- 彩蛋触发：`case 'ba'` 是多字符常量、永远不匹配 → 改为字符串比较 `"ba"`；
- 输入：`scanf("%c")` 残留换行导致第二轮必进 default → 改为按行读取；
- 帧缓冲：`buf[1920]` 越界写入 → 按真实 1944 字节读入并正确补 0；
- `fopen` 空指针判空；四则运算文案修正与除零判断；
- 计时：`clock()` 忙等 → `GetTickCount64()` 绝对时间轴 + `Sleep`，CPU 占用从 100% 降到接近 0；
- 源码 UTF-8 + `SetConsoleOutputCP(CP_UTF8)`，中文提示不乱码。

### 版权与使用声明（★重要★）

**本压缩包与可执行文件仅供学习参考，非商业用途。**

- **代码**：MIT 许可（见 [LICENSE](https://github.com/fn28710/caculater/blob/main/LICENSE)）。
- **贡献者**：计算器 P.enHanceYu（[@fn28710](https://github.com/fn28710)），Bad Apple 动画函数 chuan —— 见 [CONTRIBUTORS.md](https://github.com/fn28710/caculater/blob/main/CONTRIBUTORS.md)。
- **`out/` 6571 帧字符画数据**：非本项目原创，源自《Bad Apple!!》影绘 PV 的 2014 年字符画数据集。
  其版权归 ZUN / 上海アリス幻樂団（原曲）、Masayoshi Minoshima / Alstroemeria Records（同人改编）、
  あにら（影绘 PV）等各自权利人所有。本包按东方Project 二次创作规约作**非商业同人分享**，
  **不适用 MIT**，禁止商用、禁止二次打包售卖、禁止当作自由素材（CC0/公有领域）使用。
- 若权利人认为本包有不当之处，请到 [Issues](https://github.com/fn28710/caculater/issues) 联系我们，
  会立即移除相关内容。
