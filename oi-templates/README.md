# OI 模板集合

此目录包含常用的 OI/竞赛模板，便于在解题时快速复制粘贴或以此为基础实现。

包含文件：
- `Cpp_template.cpp` — 基本单文件 C++ 模板（快速 IO）。
- `dsu.cpp` — 并查集（DSU）模板，带路径压缩与按秩合并。
- `bit.cpp` — 树状数组（Fenwick Tree），支持点加与前缀/区间和。
- `segtree_lazy.cpp` — 线段树（懒惰标记），支持区间加与区间求和。
- `monotonic_queue.cpp` — 单调队列示例（滑动窗口最大值）。
- `lca_binary_lifting.cpp` — 二进制倍增 LCA 模板。
- `cht.cpp` — 斜率优化（Convex Hull Trick）模板。

如何使用：
- 直接在题目文件中 `#include "../oi-templates/<模板>.cpp"`，或复制模板内容到你的提交文件中。
- 模板内已包含简短的使用说明与复杂度注释；你也可以在 `oi-templates/tests/` 中查看示例用法与自检测试。

在本地快速编译某个测试（示例，Windows + MinGW）：

```bash
g++ -std=c++14 -O2 oi-templates/tests/test_dsu.cpp -o oi-templates/tests/test_dsu.exe
./oi-templates/tests/test_dsu.exe
```

如果你希望我把模板拆成头文件（`.h/.hpp`）并改为更易复用的 include 结构，回复 “拆分为头/实现”。
