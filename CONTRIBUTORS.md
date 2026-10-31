# 贡献名单 / Contributors

本仓库的代码由两个人合作完成，素材另有来源。分工如下（也同步写在 [NOTICE.md](NOTICE.md) 里）：

## 代码

| 贡献者 | 负责部分 | 对应位置 |
| --- | --- | --- |
| **P.enHanceYu**（GitHub: [@fn28710](https://github.com/fn28710)） | **计算器主体**：主循环、菜单、输入处理、四则运算；把彩蛋接进 Calculator 的触发逻辑；修复版 `c2bad_fixed.cpp` 的缺陷修复与重写；构建 / 上传脚本与全部文档 | `main()`、`switch(op)` 四则运算分支、输入处理；`build.bat`、`push-to-github.bat`、`README.md`、`LICENSE`、`NOTICE.md`、`docs/` |
| **chuan** | **Bad Apple 字符画动画函数**：逐帧读文件、按 33 ms 时间轴推进、光标归位后原地重绘 | `c1.cpp` / `c2bad.cpp` 中的 `runbadapple()` 与 `recursur()`（修复版对应的 `run_bad_apple()` / `move_cursor_to_origin()`） |

> 原稿源码结尾打印的 `Made by chuan.` 指的是动画部分的作者。**计算器部分原先没有署名**，
> 本文件与 [NOTICE.md](NOTICE.md) 就是对它的补充署名。若上述分工与实际有出入，欢迎提 Issue 更正。

## 素材与衍生作品

| 内容 | 来源 | 说明 |
| --- | --- | --- |
| `out/` 下 6571 帧 80×24 字符画 | 2014 年的字符画数据集，随 chuan 的动画实现一同使用 | 由《Bad Apple!!》影绘版 PV 逐帧转换而来，**非本仓库原创**，不适用 MIT；权属与使用限制见 [NOTICE.md](NOTICE.md) 第 2 节 |

## 不做署名主张的部分

- 《Bad Apple!!》原曲（ZUN / 上海アリス幻樂団）、同人改编（Masayoshi Minoshima / Alstroemeria Records）、
  影绘 PV（あにら）的著作权均归各自权利人；
- 本仓库仅作课程作业、学习交流用途，非商业、非官方。
