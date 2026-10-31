@echo off
chcp 65001 >nul
setlocal

echo ============================================================
echo   GitHub 上传助手  (caculater)
echo ============================================================
echo.
echo  [1/3] 正在打开"新建仓库"页面...
echo        仓库名：caculater       可见性：Public
echo        不要勾选 Add a README / .gitignore / license
echo.
start "" "https://github.com/new?name=caculater"
echo  在网页上点 Create repository 之后，回到本窗口按任意键继续
echo  （按 Ctrl+C 可随时取消）
pause >nul

echo.
echo  [2/3] 推送 main 分支（首次会弹出浏览器让你登录 GitHub）...
git push -u origin main
if errorlevel 1 goto fail

echo.
echo  [3/3] 打 tag v1.0.0 并推送...
git tag -a v1.0.0 -m "课程作业提交版" 2>nul
git push origin v1.0.0

echo.
echo  ============================================================
echo   完成！最后一步：把仓库加进 Project 看板
echo   https://github.com/users/fn28710/projects/1
echo   （Add item - 选择 caculater 仓库，或新建一条 release item）
echo  ============================================================
pause
exit /b 0

:fail
echo.
echo  [x] 推送失败。常见原因：
echo      1. 仓库还没创建，或者仓库名不是 caculater
echo      2. 国内访问 GitHub 不稳定，连接被重置 —— 重新运行本脚本再试
echo      3. 浏览器登录没完成 —— 重跑脚本，或运行 git push -u origin main
echo.
echo  也可以手动执行：
echo      git push -u origin main
exit /b 1
