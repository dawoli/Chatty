# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 项目概述

这是一个个人的 C++ 算法竞赛训练仓库，包含大量 OJ 题目的解题代码和训练资料。

### 交互风格

本项目采用 **Learning（学习型）** 输出风格。当你需要帮助时，我会：
- 用 **提问的方式** 引导你思考问题，而不是直接给出答案
- 在你卡住时提供 **提示和线索**，鼓励你自行推导出解法
- 在你做对时给予确认，并追问更深层的理解
- 优先帮你理清思路，再辅助实现代码

## 构建和运行

### 单个文件编译

项目使用 Red Panda C++（MinGW64）作为编译器。

**快速编译**（在 VS Code 中）:
- 按 `Ctrl + F5` 运行默认的 C/C++: g++ 任务
- 或在终端中使用：
  ```bash
  g++ -O2 -std=c++14 -Wall -Wextra -o main.exe main.cpp
  ```

**带调试信息的编译**:
```bash
g++ -g -std=c++14 -o debug.exe main.cpp
```

**编译时加地址/未定义行为检测**（tasks.json 中已配置）:
```bash
g++ -g -std=c++14 -fsanitize=address,undefined,leak -o main.exe main.cpp
```

### 运行程序

```bash
./main.exe
# 或在 Windows 下
main.exe
```

### 洛谷题目本地测试

洛谷题目目录结构示例：
```
洛谷/B3631 单向链表/
  ├── B3631 单向链表.cpp
  └── B3631 单向链表.exe
```

编译并运行特定洛谷题目：
```bash
cd "洛谷/B3631 单向链表/"
g++ -O2 -std=c++14 B3631 单向链表.cpp -o B3631 单向链表.exe
./B3631 单向链表.exe
```

## 编码规范

### 代码格式

项目使用 `.clang-format` 配置文件（基于 LLVM 风格）：
- 缩进：4 个空格
- 使用 Tab 进行缩进
- 行宽：0（不限制）
- 大括号风格：Custom（类、命名空间、函数等后换行）

### 代码风格

- 使用 `#include <bits/stdc++.h>` 作为通用头文件
- 使用 `using namespace std;`
- C++ 标准使用 C++14
- 编译时开启 `-O2` 优化
- 启用 `-Wall -Wextra -pedantic` 警告

### 快速 IO

所有竞赛题目代码应包含快速 IO 模板：
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 你的代码
    return 0;
}
```

## 代码库结构

### 题目仓库

- **洛谷 (`/洛谷/`)** - 约 102 道洛谷题目，按题目编号或标签组织
  - 结构：`洛谷/{题目编号或名称}/{题目编号}.cpp`
  - 通常包含多个版本的实现（不同算法思路、不同语言生成等）

- **CSPJS (`/CSPJS/`)** - CSP 竞赛题目
  - 结构：`CSPJS/{年份}/{组别}/answers/{题号}/题目名/题目名.cpp`
  - 组别：`J` (Junior, 初级), `S` (Senior, 高级)

- **LeetCode (`/LeetCode/`)** - LeetCode 题目
  - 目录结构按题号或分类组织

- **LibreOJ (`/LibreOJ/`)** - LibreOJ 题目
  - 示例：`LibreOJ/#5514 「PA 2019 Final」Floyd-Warshall/`

- **YACS (`/yacs/`)** - 青少年算法竞赛题目
  - 包含上海市青少年算法竞赛的网络赛和现场赛

### 主题训练 (`/各类竞赛题目/` 和 `/oi-templates/`)

- **按主题分类**：`深搜/`、`排序/`、`数组/`、`字符串/`、`指针/`、`函数/`、`二维数组/` 等
- **算法模板** (`/oi-templates/`)：
  - `Cpp_template.cpp` - 基础单文件模板（快速 IO）
  - `dsu.cpp` - 并查集（带路径压缩与按秩合并）
  - `bit.cpp` - 树状数组（Fenwick Tree）
  - `segtree_lazy.cpp` - 线段树（懒惰标记）
  - `monotonic_queue.cpp` - 单调队列
  - `lca_binary_lifting.cpp` - 二进制倍增 LCA
  - `cht.cpp` - 斜率优化（Convex Hull Trick）

### VS Code 配置

- **tasks.json** - 定义了多个编译任务（单文件调试、非调试、带检测等）
- **settings.json** - 配置了 C/C++ 自动补全、文件关联等
- **launch.json** - 调试配置
- **c_cpp_properties.json** - IntelliSense 配置

## 开发工作流

### 添加新题目

1. 在对应 OJ 目录下创建题目文件夹
2. 添加 `题目名.cpp` 源文件
3. 编译并测试：`g++ -O2 -std=c++14 题目名.cpp -o 题目名.exe`
4. 运行测试：`./题目名.exe`

### 使用模板

- 直接在题目文件中 `#include "../oi-templates/模板.cpp"`（如从 `洛谷/` 目录）
- 或复制模板内容到题目文件中
- 模板包含详细的使用说明和复杂度注释

### 调试

使用 VS Code 的调试功能：
- F5 启动调试（会使用 tasks.json 中带 `-g` 的任务）
- 设置断点后逐步执行
- 可使用性能分析工具（`-pg` 标志）

## 关键注意事项

- 所有代码使用 C++14 标准
- 竞赛代码优先考虑时间/空间效率和边界情况
- 代码风格简洁、易于调试且易于粘贴到评测系统，除了了开头的Problem URL,Start Time,Finish Time,Category以外，不应包含其他注释，变量名尽量短，代码避免有AI味
- 注意洛谷题目通常需要在标准输入/标准输出上运行
- 代码应处理输入输出超时问题（快速 IO 已包含）
