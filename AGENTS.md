# AGENTS.md

This file provides guidance to agents when working with code in this repository.

## 项目概述

这是一个个人的 C++ 算法竞赛训练仓库，包含大量 OJ 题目（洛谷 ~119 道、CSP-J/S、LeetCode、LibreOJ、YACS 等）的解题代码、竞赛模板和训练资料。

### 交互风格

本项目采用 **Learning（学习型）** 输出风格，应通过提问/提示引导用户思考，鼓励自主推导。

## 快速参考

### 单文件编译

```bash
g++ -O2 -std=c++14 -Wall -Wextra -o main.exe main.cpp
```

### 调试编译）

```bash
g++ -O0 -g -std=c++14 -Wall -Wextra -o main.exe main.cpp
```

### VS Code 快捷键

- `F5`：调试运行（使用 tasks.json 中的带调试编译任务）
- `Ctrl+F5`：非调试运行
- 编译器路径：`D:\C++\RedPanda.C++\mingw64\bin\g++.exe`

### 用测试数据验证

洛谷部分题目文件夹内包含 `.in` / `.out` 测试数据（如 `P1941 飞扬的小鸟/`），可用重定向运行：

```bash
g++ -O2 -std=c++14 "P1941 [NOIP 2014 提高组] 飞扬的小鸟.cpp" -o "P1941.exe"
./P1941.exe < "P1941_16.in"
```

### 使用模板

直接复制 oi-templates/ 下的 .cpp 模板

### 新建题目

1. 在对应 OJ 目录下创建文件夹
2. 从 `oi-templates/Cpp_template.cpp` 复制快速 IO 模板
3. 编写解题代码
4. 编译测试

## 代码规范

- **标准**：C++14，`#include <bits/stdc++.h>` + `#define int int` + `#define endl '\n'` + `using namespace std;` + `typedef long long ll;` + `signed main()`
- **快速 IO**：`ios::sync_with_stdio(false); cin.tie(nullptr);`
- **码风**：LLVM 风格 + Allman 大括号（函数/类/命名空间后换行），Tab 缩进 4 格，snake_case 命名，1-based
- **clang-format**：`.clang-format` 已配置（UseTab: Always）
- **无指针**：优先用 C 风格 + C++14 语法特性，避免指针
- **代码简洁**：只保留行首 `Problem URL` / `Start Time` / `Finish Time` / `Category` 注释，无 AI 味，可以有适当注释

## 目录结构

```
/
├── 洛谷/                       # ~119 道洛谷题目
│   ├── P1525 [NOIP 2010 提高组] 关押罪犯/
│   ├── P1941 [NOIP 2014 提高组] 飞扬的小鸟/   # 包含 .in/.out 测试数据
│   └── 比赛/                    # 洛谷比赛题目
│
├── CSPJS/                      # CSP 竞赛（含真题、模拟题）
│   ├── 2024/
│   │   ├── 2024CSPJ/           # J 组真题
│   │   ├── 2024CSPS/           # S 组真题
│   │   └── 信息邹老师发布的/    # 培训资料 + answers/
│   └── 2025/
│       ├── J/                  # J 组（含 9_CSP-J 真题 + answers/ 各选手解答）
│       └── S/                  # S 组（含 SH-Senior/answers/ 各选手解答）
│
├── oi-templates/               # 常用算法模板
│   ├── dsu.cpp                 # 并查集
│   ├── bit.cpp                 # 树状数组
│   ├── segtree_lazy.cpp        # 线段树（懒惰标记）
│   ├── monotonic_queue.cpp     # 单调队列
│   ├── lca_binary_lifting.cpp  # LCA 倍增
│   ├── cht.cpp                 # 斜率优化
│   ├── include/                # .hpp 头文件版本，可 #include 使用
│   └── tests/                  # 各模板的单元测试
│
├── yacs/                       # 上海市青少年算法竞赛
│   ├── 2026年4月月赛/
│   ├── 2026年5月月赛/
│   └── 第六届.../
│
├── LeetCode/                   # LeetCode 题解
├── LibreOJ/                    # LibreOJ 题目
├── 乐动创想/                   # 培训机构课程资料
│   └── 课程回放/               # 课程回放资料
│
├── 错题本/                      # 错题复盘记录
│   ├── 客观题/                  # GESP 等选择/判断题错题
│   └── 主观题/                  # 算法编程题错题（Markdown，含算法标签+题号）
│
├── .vscode/                    # VS Code 工程配置
│   ├── tasks.json              # 编译任务（调试/非调试）
│   ├── launch.json             # 调试配置（gdb）
│   ├── settings.json           # C++ 插件设置、文件关联
│   └── testSets.json           # 测试集配置
│
├── .claude/                    # Claude Code 配置
├── .agent.md                   # OI 助手 persona 定义
├── AGENTS.md                   # 本文件（仓库规范）
├── CLAUDE.md                   # Claude用（仓库规范）
├── .clang-format               # 格式化配置（LLVM Allman 变体）
└── Cpp_template.cpp            # 根目录的快速 IO 模板
```

## 模板体系

`oi-templates/` 下有双版本模板（`.cpp` 可直接复制提交，`.hpp` 可用 `#include` 引用）：

| 模板 | 说明 |
|------|------|
| `Cpp_template` | 快速 IO + main 骨架 |
| `dsu` | 并查集，路径压缩 + 按秩合并 |
| `bit` | 树状数组，点加 + 前缀/区间和 |
| `segtree_lazy` | 线段树，区间加 + 区间求和 |
| `monotonic_queue` | 单调队列，滑动窗口最值 |
| `lca_binary_lifting` | LCA 二进制倍增 |
| `cht` | 斜率优化，单调插入/查询 |

## 错题复盘

每道题 AC 后，在代码末尾追加块注释总结经验，同时在 `错题本/主观题/` 下写入对应的 Markdown 复盘记录。

### 代码末尾块注释格式

```cpp
/*
 * 经验总结：
 * - 容易错的地方：
 * - 关键结论/技巧：
 * - 复杂度：
 */
```

### 错题本 Markdown 命名规范

```
错题本/主观题/<算法标签> <题号> <题目名>.md
```

内容应包含：题目链接、算法思路、踩坑点、关键结论，方便复习检索。

- Allman 大括号（函数/类/命名空间/控制语句全换行），**但 `else`/`catch`/`while`（do-while 的）不换行**
- 竞赛代码优先考虑时间/空间效率和边界情况
- 可以在代码中**适当**添加题解或算法解释,不要过多
- 洛谷题目运行于标准输入/输出，用 `.in` / `.out` 文件重定向测试
- CSP 赛场答案按选手编号组织在 `answers/` 下，目录名如 `SH-J00001`、`SH-S00001`
---

## 实战经验记忆（迁移自 Claude，2026-09-12）

### 编译输出位置
编译本仓库单文件 OJ 题解时，可执行文件输出到**题目所在文件夹**（与 .cpp 同目录），不要输出到 build/。用 `./xxx.exe` 运行测试。

### 逐题分开提交
每一道题目（连同其对应的错题本复盘记录）单独作为一个 commit；非题目类改动（配置、工具、训练资料等）按主题分组提交。提交前先识别"新增/修改题目"类与"配置/工具/资料"类，题目逐题 `git add <题目文件夹>`（含错题本 md），其余按主题提交。

### 陈振训练目录
`陈振/` 目录是教练**陈振**的教学训练资料（CSP 初赛选择题、阅读程序 PDF，按日期如 2026-8-17/2026-8-19 分目录），是**人名**不是"陈列"，与题目/错题本分开处理。

### GitHub 推送（大陆网络）
- remote 是 `https://github.com/dawoli/Chatty.git`（仓库名是 Chatty 不是 C++）。大陆直连 push 极不稳定（HTTP 408 / Connection reset）。
- 判断 push 是否真成功必须 `git ls-remote origin C++` 确认远端 ref == 本地 HEAD；`git send-pack` 断开时的 `Everything up-to-date` 是误报。
- 已做仓库级加固（勿重复）：`http.postBuffer 524288000`、`http.version HTTP/1.1`。
- 本机无 GitHub SSH 密钥，不要尝试 SSH 推送。必要时开代理（7890/10809）配 `git config http.proxy` 一次推完；深夜/清晨通常更通。

### 环 DP：倍长 vs 断环（典例 P6064）
- 倍长数组只在**最优解天然落在长度 ≤ N 的连续窗口内**时安全（环形最大子段和、固定长度窗口最值）。
- 对"任意选点 + 可多段、段首收益打折"的环 DP（如洛谷 P6064 Naptime G），倍长会让同一位置 i 与 i+N 被重复选中、答案偏大。标准做法：在 1 号处**断环**，跑两遍 DP 分类讨论（① 1 号不睡→线性 DP；② 1 号睡→当入睡起点收益 0，末若 N 睡补 +u[1]），取最大值，O(N·B)。
- 速记：解能否塞进长度 ≤ N 的连续窗口？能→倍长；不能→断环分类。

---

## Evolver 记忆系统（2026-10-03）

本仓库接入了 Evolver 自进化记忆，把 `错题本/` 里沉淀的经验变成解题时可用的提示。

> Claude Code 侧由 skill `oi-mistake-recall` 和 hook **自动触发**；Codex 侧没有 hook，
> 所以下面两步**必须主动执行**——这是本节的唯一目的。

### 第一步：检索错题本（动手解题之前）

`错题本/主观题/` 的**文件名就是索引**：

```
<算法标签> <题号> <题目名>.md
环形DP P6064 [USACO05JAN] Naptime G.md
数论 P1069 [NOIP 2009 普及组] 细胞分裂.md
背包DP 差值背包 P4832 珈百璃堕落的开始.md
```

流程：

1. 从题目提取**题号**（`P\d+` / `B\d+` / `SP\d+`）和**算法关键词**
2. `ls 错题本/主观题/` 列出索引 —— **先看文件名，不要一上来就读文件内容**
3. 匹配优先级：**题号完全一致 > 算法子特征命中 > 算法大类命中**
4. 只读命中的那几篇，重点看 `**错点**` / `**关键结论**` / `## 踩坑点` 小节
5. 用**一两句话**提相关经验，**不要整篇复述**

**新题没有题号可对**，此时从题面推断算法大类（DP / 图论 / 数论 / 字符串 / 数据结构 / 模拟），
再落到**子特征**（线性/区间/环形/背包/差值/分组/恰好k步…）去匹配标签。
子特征命中优先于大类命中——例如判定为「环形+背包」时读 `环形DP` 和 `背包DP`，不读泛泛的 `线性DP`。

`错题本/客观题/` 是初赛知识点（欧拉回路、树状数组、格雷码…），**只在问概念时查**。
若模型自身具备知识，**直接作答而不搜索**。

### 第二步：拉取基因库经验

**优先用 MCP 工具**（已实测可用；`evolver` CLI 会被 Codex 的 shell policy 拦截）：

- `evolver_recall` —— 拉取已审核的算法判别准则（最多 8 条），**开始解题前调用一次**
- `evolver_asset_search` —— 按文本搜基因/胶囊（如 `{"text": "环形DP"}`）

CLI 形式（本机终端可用）：

```bash
evolver inject session-start      # 最多 8 条已批准判别准则（手工审核过）
evolver review                    # 查看基因池状态（哪些 approved / quarantined）
```

### 不要做的事

- ❌ 没有匹配时报告"错题本里没有" —— **直接开始解题**
- ❌ 把整个错题本读进上下文
- ❌ 复述题目内容，只提炼**经验**
- ❌ 在解题中途才想起来查（必须在**动手前**）

> 搭建原理与完整踩坑记录：`~/.claude/scripts/EVOLVER_SETUP.md`
