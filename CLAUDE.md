# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 项目概述

这是一个个人的 C++ 算法竞赛训练仓库，包含大量 OJ 题目（洛谷 ~119 道、CSP-J/S、LeetCode、LibreOJ、YACS 等）的解题代码、竞赛模板和训练资料。

### 交互风格

本项目采用 **Learning（学习型）** 输出风格（已在 `.claude/settings.local.json` 中配置），应通过提问/提示引导用户思考，鼓励自主推导。

## 快速参考

### 单文件编译

```bash
g++ -O2 -std=c++14 -Wall -Wextra -o main.exe main.cpp
```

### 调试编译（含 sanitizer）

```bash
g++ -O0 -g -std=c++14 -fsanitize=address,undefined,leak -o main.exe main.cpp
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

```cpp
#include "../oi-templates/include/dsu.hpp"   // 用 .hpp 头文件
// 或直接复制 oi-templates/ 下的 .cpp 模板
```

### 新建题目

1. 在对应 OJ 目录下创建文件夹
2. 从 `oi-templates/Cpp_template.cpp` 复制快速 IO 模板
3. 编写解题代码
4. 编译测试

## 代码规范

- **标准**：C++14，`#include <bits/stdc++.h>` + `using namespace std;` + `typedef long long ll;`
- **快速 IO**：`ios::sync_with_stdio(false); cin.tie(nullptr);`
- **码风**：LLVM 风格 + Allman 大括号（函数/类/命名空间后换行），Tab 缩进 4 格，snake_case 命名
- **clang-format**：`.clang-format` 已配置（Custom BraceWrapping，ColumnLimit: 0，UseTab: Always）
- **无指针**：优先用 C 风格 + C++14 语法特性，避免指针
- **代码简洁**：只保留行首 `Problem URL` / `Start Time` / `Finish Time` / `Category` 注释，无多余注释和 AI 味

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
│   ├── Cpp_template.cpp        # 快速 IO 起点模板
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
├── AC MX/                      # ACMX（洛谷团队赛）
├── Houston/                    # Houston 题目
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
│   ├── tasks.json              # 编译任务（调试/非调试/sanitizer）
│   ├── launch.json             # 调试配置（gdb）
│   ├── settings.json           # C++ 插件设置、文件关联
│   └── testSets.json           # 测试集配置
│
├── .claude/                    # Claude Code 配置
├── .agent.md                   # OI 助手 persona 定义
├── AGENTS.md                   # 工作区代理指令
├── CLAUDE.md                   # 本文件（仓库规范）
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
- **不**在代码中添加题解或算法解释；代码即答案
- 洛谷题目运行于标准输入/输出，用 `.in` / `.out` 文件重定向测试
- CSP 赛场答案按选手编号组织在 `answers/` 下，目录名如 `SH-J00001`、`SH-S00001`
