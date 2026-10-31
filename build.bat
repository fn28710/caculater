@echo off
chcp 65001 >nul
setlocal
rem ============================================================
rem  编译 c2bad_fixed.cpp -> c2bad.exe
rem  需要 MinGW-w64（或 Dev-C++ 自带的 g++）在 PATH 中
rem ============================================================

where g++ >nul 2>nul
if errorlevel 1 (
    echo [x] 找不到 g++。请安装 MinGW-w64，或使用 Dev-C++ 打开 c2bad_fixed.cpp 直接编译。
    exit /b 1
)

g++ -std=c++17 -O2 -Wall -o c2bad.exe c2bad_fixed.cpp
if errorlevel 1 (
    echo [x] 编译失败。
    exit /b 1
)

echo [ok] 已生成 c2bad.exe
echo      请在当前目录（含 out\ 帧数据）下运行它。
