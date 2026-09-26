# Copilot instructions

## Repository shape

This is an OI/competitive-programming learning archive, not one application with a repository-wide build. Most problem directories contain independent solutions that read standard input and write standard output; solve and build only the relevant problem rather than treating neighboring files as shared application code. Contest archives can contain many participants' answer files.

`洛谷/`, `CSPJS/`, `LeetCode/`, `LibreOJ/`, and `YACS/` group problem solutions and contest material. `oi-templates/` holds reusable algorithm templates: `.cpp` examples for copying into submissions, header-only `.hpp` versions under `include/`, and focused checks under `tests/`. Some individual problem folders have their own `CMakeLists.txt`; there is no root-level build.

When a solved problem needs a review note, follow `AGENTS.md`: add a concise experience summary at the end of the solution and a Markdown note under `错题本/主观题/` named `<algorithm> <problem-id> <title>.md`, covering the problem link, approach, pitfalls, and key conclusion.

## Build, test, and format

Compile a single solution from its directory with the repository's C++14 baseline:

```powershell
g++ -O2 -std=c++14 -Wall -Wextra -o solution.exe solution.cpp
.\solution.exe
```

Keep the executable beside the solution rather than in a shared build directory. Quote source paths that contain spaces. VS Code's build/debug tasks also compile the active file as C++14 and place its `.exe` beside it; the configured compiler path is machine-specific.

There is no repository-wide test runner. Template tests are standalone programs; compile and run the one corresponding to the changed template. For example, from the repository root:

```powershell
g++ -std=c++14 -O2 .\oi-templates\tests\test_dsu.cpp -o .\oi-templates\tests\test_dsu.exe
.\oi-templates\tests\test_dsu.exe
```

Other focused checks are `test_bit.cpp`, `test_cht.cpp`, `test_lca.cpp`, `test_monotonic_queue.cpp`, and `test_segtree.cpp` in the same directory.

Use the root `.clang-format` for formatting. Check or apply it to a specific file with:

```powershell
clang-format --dry-run --Werror .\path\to\file.cpp
clang-format -i .\path\to\file.cpp
```

No repository-wide lint command is configured.

## Code conventions

- Use C++14 unless the problem or its existing folder explicitly requires another standard. Competitive solutions are normally standalone and use `#include <bits/stdc++.h>`, fast iostream setup, and standard input/output.
- Prefer the relevant starter or neighboring solution for boilerplate. The root and `oi-templates/` starters differ slightly; do not impose one starter's incidental macros on every file.
- `.clang-format` specifies tabs with width 4, Allman braces, and no column limit. Existing archived answers may use different styles, so match the local file when editing legacy or participant code.
- Template tests exercise the header-only implementations in `oi-templates/include/`; preserve that include-based interface when changing those templates.
- For OI explanations, default to Chinese and use a learning-oriented style; when implementation is requested, provide a complete solution suitable for the target judge.
