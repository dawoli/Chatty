# Workspace Agent Instructions

## 目标
这个仓库是一个个人 C++ 算法竞赛训练库。主要内容是单文件题解、竞赛模板、OJ 练习和训练资料。AI 助手应以竞赛场景为核心，优先输出可直接编译、可直接提交的高质量 C++ 代码。

## 主要参考文档
- `CLAUDE.md`：仓库级别的编程规范、编译与运行说明。
- `.agent.md`：为“OI 助手”配置的专用助手角色与模板路径。
- `oi-templates/README.md`：模板使用说明。

## 代码风格与约定
- 默认使用 `C++14`。
- 典型编译命令：
  - `g++ -O2 -std=c++14 -Wall -Wextra -pedantic -o main.exe main.cpp`
  - 调试时可使用 `g++ -g -std=c++14 -fsanitize=address,undefined,leak -o debug.exe main.cpp`。
- 题目代码通常为单文件实现，包含必要的 `#include`、`using namespace std;` 和 `main()`。
- 使用快速 IO 模板，避免 `scanf/printf` 与 `cin/cout` 混用：
  ```cpp
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ```
- 保持代码简洁、易于调试，避免过多注释和冗余封装。竞赛题目提交版本不应有“AI 风格”或过度解释性文本。

## 任务与建议
- 如果用户要求“写题解”或“优化代码”，优先给出符合竞争编程习惯的单文件 C++ 实现。
- 如果用户提出具体题目、限制或 OJ 来源，遵循对应目录结构和命名风格编写代码。
- 在修改现有文件时，保留原有题目目录结构和文件命名，避免无关重构。
- 当需要引用模板时，建议使用 `oi-templates/` 中已有文件，如 `oi-templates/Cpp_template.cpp`，也可在回答中说明模板来源。

## 目录结构指引
- `洛谷/`：洛谷题目目录，通常按题号或题目名分类。
- `CSPJS/`：CSP 竞赛题目。
- `LeetCode/`、`LibreOJ/`、`YACS/`：对应平台题目。
- `oi-templates/`：常用算法模板和数据结构实现。

## 编译与本地测试
- 默认使用仓库根目录的 VS Code 任务或者直接在题目目录中运行编译命令。
- 运行时使用标准输入/输出，避免在代码中硬编码测试路径。

## 为 AI 助手提供的额外说明
- 该仓库已有 `.agent.md`，它定义了“OI 助手”的 persona、可用工具、模板路径和对竞赛代码的偏好。
- 这个文件补充仓库级别的工作流与风格要求，适用于任何需要理解仓库结构的代理。
- 若要进一步增强，可继续创建 `.github/copilot-instructions.md`，将 `AGENTS.md` 中的核心指南同步到 GitHub Copilot 定制说明。
