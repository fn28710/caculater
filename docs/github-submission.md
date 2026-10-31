# 上传 GitHub 与提交到 Project 的步骤

## 0. 先搞清楚“提交地址”是什么

你给的地址：

```
https://github.com/users/fn28710/projects/1/views/1?system_template=feature_release
```

这是 **GitHub Projects（新版项目看板）** 的一个视图，模板是 `feature_release`。
它**不是** Git 仓库地址，`git push` 不能推到这里 —— 代码要推到你自己的**仓库（Repository）**，
然后再把“这个仓库 / 这次发布”作为一个 **item** 加进那个 Project 看板。

## 1. 创建仓库（网页端）

1. 打开 <https://github.com/new>
2. **Repository name**：`caculater`（或 `badapple-ascii-calculator`，随便，能看出内容即可）
3. **Visibility**：Public（作业展示）/ Private（只想给老师看、规避素材版权风险时选这个）
4. **不要**勾选 "Add a README file"（本地已经有 README，避免冲突）
5. 点 **Create repository**

## 2. 本地初始化并推送

在项目根目录（`C:\Users\75938\Desktop\caculater`）执行：

```bash
git init
git add .
git commit -m "feat: 四则运算计算器 + Bad Apple!! 字符画彩蛋"
git branch -M main
git remote add origin https://github.com/fn28710/caculater.git
git push -u origin main
```

> 首次推送需要认证：用 **Personal Access Token**（GitHub → Settings → Developer settings →
> Personal access tokens → Fine-grained tokens，勾选该仓库的 Contents: Read and write）作为密码，
> 或用 GitHub Desktop / VS Code 的账号登录方式推送。

推送前建议确认：

```bash
git status                 # 应该没有 c2bad.exe（已被 .gitignore 忽略）
git ls-files out | wc -l   # 应该是 6571（PowerShell: (git ls-files out).Count）
```

## 3. 把仓库加进 Project 看板

1. 打开 <https://github.com/users/fn28710/projects/1>
2. 右上角 **+ / Add item**（或视图里的 **Add item from repository**）
3. 选择刚推送的仓库 —— 若你的 `feature_release` 模板期望的是“发布/版本”，
   可以再建一条 **Draft issue** 或 **Release item**，标题写 `v1.0.0 · 课程作业提交`，
   并关联到该仓库。
4. 如果模板里有 **Status / Track** 之类的字段，把 item 拖到 `Shipped` / `Done` 之类的列。

## 4. 打一个 tag / Release（可选但推荐）

```bash
git tag -a v1.0.0 -m "课程作业提交版"
git push origin v1.0.0
```

然后在 GitHub 仓库页 → **Releases** → **Draft a new release** → 选择 `v1.0.0` →
标题写“Bad Apple!! 字符画计算器 v1.0.0”，正文可直接复制 README 的“功能”段落。

> ⚠️ 发布 Release 时**不要**把 `out/` 的帧数据单独做成压缩包提供下载，也不要标价 ——
> 那属于“未经许可的商业/再分发”，会越过东方二创规约的边界。详见 `NOTICE.md`。

## 5. 常见坑

| 现象 | 原因 | 处理 |
| --- | --- | --- |
| `git push` 报 403 | 没有权限 / token 过期 | 重新生成 PAT，或换用 GitHub Desktop 登录 |
| 仓库里看不到 `c2bad.exe` | `.gitignore` 忽略了编译产物 | 正常，编译产物不该进仓库 |
| clone 后双击 exe 提示打不开帧文件 | 工作目录没有 `out/` | 在仓库根目录运行；或先检查 `git ls-files out` 是否为 6571 |
| 帧文件行尾变成 CRLF、画面错位 | Git 自动换行转换 | 仓库已包含 `.gitattributes`（`out/*.txt -text`），不要再改动它 |
