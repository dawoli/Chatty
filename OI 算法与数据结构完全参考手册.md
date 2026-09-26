# OI 算法与数据结构完全参考手册

## 第一部分：基础数据结构

### 1.1 静态数组与前缀和

前缀和是最基础的预处理技巧，用于 $O(1)$ 回答区间和查询。

设 $a_1, a_2, \dots, a_n$，定义前缀和数组 $s_i = \sum_{j=1}^{i} a_j$，其中 $s_0 = 0$。则区间 $[l, r]$ 的和为 $s_r - s_{l-1}$。

```cpp
#include <cstdio>

const int MAX_N = 1000005;

int n, q;
long long a[MAX_N], s[MAX_N];

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    s[i] = s[i - 1] + a[i];
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%lld\n", s[r] - s[l - 1]);
  }
  return 0;
}
```

**注意事项**：
- 前缀和可能溢出 `int`，当 $n \le 10^6$ 且 $|a_i| \le 10^9$ 时，总和可达 $10^{15}$，必须使用 `long long`。
- 二维前缀和：$s_{i,j} = a_{i,j} + s_{i-1,j} + s_{i,j-1} - s_{i-1,j-1}$，子矩阵 $(x_1,y_1,x_2,y_2)$ 的和为 $s_{x_2,y_2} - s_{x_1-1,y_2} - s_{x_2,y_1-1} + s_{x_1-1,y_1-1}$，这就是容斥原理。

### 1.2 差分

差分是前缀和的逆运算。给区间 $[l, r]$ 整体加上 $d$，只需 `b[l] += d; b[r+1] -= d;`，最后对 $b$ 求前缀和即得到修改后的数组。

```cpp
void range_add(int l, int r, long long d) {
  b[l] += d;
  b[r + 1] -= d;
}

void finalize() {
  for (int i = 1; i <= n; ++i)
    a[i] = a[i - 1] + b[i];
}
```

差分树上同样可以玩出花样：树上差分用于处理“路径加”问题。点差分：对路径 $(u, v)$ 加 1，令 `b[u]++, b[v]++, b[lca]--, b[fa[lca]]--`；边差分：`b[u]++, b[v]++, b[lca] -= 2`，最后子树求和。

### 1.3 并查集

并查集维护不相交集合，支持合并与查询。路径压缩 + 按秩合并后，单次操作均摊 $O(\alpha(n))$，其中 $\alpha$ 是反阿克曼函数，可视为常数。

```cpp
struct DSU {
  int fa[MAX_N], sz[MAX_N];

  void init(int n) {
    for (int i = 1; i <= n; ++i) {
      fa[i] = i;
      sz[i] = 1;
    }
  }

  int find(int x) {
    while (fa[x] != x)
      x = fa[x] = fa[fa[x]]; // 路径减半
    return x;
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return false;
    if (sz[x] < sz[y])
      x ^= y ^= x ^= y; // 交换
    fa[y] = x;
    sz[x] += sz[y];
    return true;
  }
};
```

**扩展应用**：
1. **带权并查集**：维护每个点到根的相对权值，路径压缩时同步更新 `d[x] += d[fa[x]]`。典型题：食物链（NOI 2001）。
2. **边带权**：food chain 类问题中权值模 3 运算。
3. **可撤销并查集**：不路径压缩，按秩合并，用栈记录修改，支持回退。配合整体二分或线段树分治使用。
4. **种类并查集**：开 $2n$ 的空间，$i$ 与 $i+n$ 表示对立关系。

### 1.4 ST 表

ST 表（Sparse Table）用于 $O(n \log n)$ 预处理、$O(1)$ 查询静态区间最值。基于倍增思想：$f_{i,j} = \max(f_{i,j-1}, f_{i+2^{j-1},j-1})$。

```cpp
int lg[MAX_N];
int f[MAX_N][21];

void build(int n) {
  lg[1] = 0;
  for (int i = 2; i <= n; ++i)
    lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; ++i)
    f[i][0] = a[i];
  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; ++i)
      f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
  int k = lg[r - l + 1];
  return max(f[l][k], f[r - (1 << k) + 1][k]);
}
```

ST 表只能处理**可重复贡献**的信息（$\max, \min, \gcd$,按位或、按位与），不能处理区间和（因为区间和不是可重复贡献的——元素不能被算两次）。

### 1.5 树状数组

树状数组（BIT / Fenwick Tree）维护满足“前缀可减”性质的信息（和、异或等），单点修改 $O(\log n)$，前缀查询 $O(\log n)$。

核心操作 `x & (-x)` 取出 $x$ 二进制最低位的 1。

```cpp
struct BIT {
  long long c[MAX_N];
  int n;

  void init(int n_) { n = n_; }

  void add(int x, long long d) {
    for (; x <= n; x += x & (-x))
      c[x] += d;
  }

  long long query(int x) {
    long long res = 0;
    for (; x > 0; x -= x & (-x))
      res += c[x];
    return res;
  }

  long long range_query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
```

**进阶技巧**：

1. **区间修改 + 区间查询**：维护两个数组。若 $[l,r]$ 加 $d$，则维护 $c_1$（差分）与 $c_2$（差分 × 位置）。前缀和 $=\sum_{i=1}^{x} \sum_{j=1}^{i} b_j = \sum_{j=1}^{x} b_j (x - j + 1) = (x+1)\sum b_j - \sum j \cdot b_j$。

```cpp
struct BIT2 {
  long long c1[MAX_N], c2[MAX_N];
  int n;

  void add(long long *c, int x, long long d) {
    for (; x <= n; x += x & (-x))
      c[x] += d;
  }

  long long query(long long *c, int x) {
    long long res = 0;
    for (; x > 0; x -= x & (-x))
      res += c[x];
    return res;
  }

  void range_add(int l, int r, long long d) {
    add(c1, l, d);
    add(c1, r + 1, -d);
    add(c2, l, d * l);
    add(c2, r + 1, -d * (r + 1));
  }

  long long prefix(int x) {
    return (x + 1) * query(c1, x) - query(c2, x);
  }

  long long range_query(int l, int r) {
    return prefix(r) - prefix(l - 1);
  }
};
```

2. **求第 $k$ 小（整体二分上树状数组）**：利用 `find_kth` 沿着二进制位下降，$O(\log n)$。

```cpp
int kth(long long k) {
  int pos = 0;
  for (int j = 20; j >= 0; --j) {
    if (pos + (1 << j) <= n && c[pos + (1 << j)] < k) {
      pos += 1 << j;
      k -= c[pos];
    }
  }
  return pos + 1;
}
```

3. **二维树状数组**：单点加、子矩阵和，均为 $O(\log^2 n)$。

4. **逆序对**：离散化后从右往左扫，`ans += query(a[i] - 1)`，或从左往右 `ans += i - query(a[i])`。

### 1.6 线段树

线段树是 OI 中最重要的数据结构，支持单点/区间修改与区间查询，$O(\log n)$ 每次操作。

```cpp
struct SegTree {
  long long sum[MAX_N << 2], lz[MAX_N << 2];
  int n;

  void push_up(int p) { sum[p] = sum[p << 1] + sum[p << 1 | 1]; }

  void build(int p, int l, int r, long long *a) {
    lz[p] = 0;
    if (l == r) {
      sum[p] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid, a);
    build(p << 1 | 1, mid + 1, r, a);
    push_up(p);
  }

  void apply(int p, int l, int r, long long d) {
    sum[p] += d * (r - l + 1);
    lz[p] += d;
  }

  void push_down(int p, int l, int r) {
    if (lz[p]) {
      int mid = (l + r) >> 1;
      apply(p << 1, l, mid, lz[p]);
      apply(p << 1 | 1, mid + 1, r, lz[p]);
      lz[p] = 0;
    }
  }

  void update(int p, int l, int r, int ql, int qr, long long d) {
    if (ql <= l && r <= qr) {
      apply(p, l, r, d);
      return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid)
      update(p << 1, l, mid, ql, qr, d);
    if (qr > mid)
      update(p << 1 | 1, mid + 1, r, ql, qr, d);
    push_up(p);
  }

  long long query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return sum[p];
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    long long res = 0;
    if (ql <= mid)
      res += query(p << 1, l, mid, ql, qr);
    if (qr > mid)
      res += query(p << 1 | 1, mid + 1, r, ql, qr);
    return res;
  }
};
```

**线段树的核心变体**：

1. **动态开点线段树**：值域 $10^{18}$ 时不能开满，每次访问时创建节点。空间 $O(q \log V)$。配合标记永久化可省去 push_down。

2. **标记永久化**：不下传标记，查询时累加路径上的标记。适用于“标记可交换、信息可叠加”的场景，如区间加 + 区间 max。

3. **李超线段树（LiChao Tree）**：维护线段/直线集合，查询某 $x$ 处的最值。插入一条线段 $O(\log^2 n)$（或 $O(\log n)$）。核心思想：在每个节点保留“ dominating 线段”，新线段与旧线段比较中点处优劣，劣者在交点所在的一半递归。

```cpp
struct Line {
  long long k, b;
  long long eval(long long x) const { return k * x + b; }
};

struct LiChao {
  Line tr[MAX_N << 2];
  bool has[MAX_N << 2];
  int n;

  void insert(int p, int l, int r, Line v) {
    if (!has[p]) {
      tr[p] = v;
      has[p] = true;
      return;
    }
    int mid = (l + r) >> 1;
    bool lft = v.eval(l) < tr[p].eval(l);
    bool mid_better = v.eval(mid) < tr[p].eval(mid);
    if (mid_better)
      swap(v, tr[p]);
    if (l == r)
      return;
    if (lft != mid_better)
      insert(p << 1, l, mid, v);
    else
      insert(p << 1 | 1, mid + 1, r, v);
  }

  long long query(int p, int l, int r, int x) {
    if (!has[p])
      return INF;
    long long res = tr[p].eval(x);
    if (l == r)
      return res;
    int mid = (l + r) >> 1;
    if (x <= mid)
      res = min(res, query(p << 1, l, mid, x));
    else
      res = min(res, query(p << 1 | 1, mid + 1, r, x));
    return res;
  }
};
```

4. **吉司机线段树（Segment Tree Beats）**：区间取 min / max、区间历史最值。`chmin` 操作的复杂度是均摊 $O(\log^2 n)$，核心是维护区间最大值 $mx$ 与严格次大值 $se$，当 $d \ge mx$ 时直接打标记返回，当 $se < d < mx$ 时只修改最大值并递归。

5. **zkw 线段树**：非递归实现，常数极小。把树补成满二叉树，所有叶子集中在同一层，用循环代替递归。

6. **线段树合并**：把两棵动态开点线段树合并，复杂度 $O(m \log V)$（$m$ 为总节点数）。用于树上问题（如“雨天的尾巴”）、DSU on tree 等。

```cpp
int merge(int p, int q, int l, int r) {
  if (!p || !q)
    return p + q;
  if (l == r) {
    val[p] += val[q];
    return p;
  }
  int mid = (l + r) >> 1;
  ls[p] = merge(ls[p], ls[q], l, mid);
  rs[p] = merge(rs[p], rs[q], mid + 1, r);
  push_up(p);
  return p;
}
```

7. **线段树分裂**：合并的逆操作，按前 $k$ 个分裂。与主席树（可持久化数组）配合可维护可持久化平衡树。

8. **扫描线**：矩形面积并、周长并。把每个矩形拆成两条竖线（加入/删除），按 $x$ 排序，线段树维护 $y$ 轴上的覆盖情况。

### 1.7 平衡树

#### 1.7.1 Treap

树堆（Treap）= BST + 堆。给每个节点一个随机优先级，使其同时满足 BST 性质（按键）和堆性质（按优先级），期望树高 $O(\log n)$。

**旋转 Treap**：

```cpp
struct Treap {
  int lc[MAX_N], rc[MAX_N];
  int pri[MAX_N], cnt[MAX_N], sz[MAX_N];
  long long key[MAX_N];
  int tot, root;

  int new_node(long long k) {
    ++tot;
    lc[tot] = rc[tot] = 0;
    pri[tot] = rand();
    cnt[tot] = sz[tot] = 1;
    key[tot] = k;
    return tot;
  }

  void push_up(int p) { sz[p] = sz[lc[p]] + sz[rc[p]] + cnt[p]; }

  void zig(int &p) { // 右旋
    int q = lc[p];
    lc[p] = rc[q];
    rc[q] = p;
    p = q;
    push_up(rc[p]);
    push_up(p);
  }

  void zag(int &p) { // 左旋
    int q = rc[p];
    rc[p] = lc[q];
    lc[q] = p;
    p = q;
    push_up(lc[p]);
    push_up(p);
  }

  void insert(int &p, long long k) {
    if (!p) {
      p = new_node(k);
      return;
    }
    if (k == key[p]) {
      ++cnt[p];
    } else if (k < key[p]) {
      insert(lc[p], k);
      if (pri[lc[p]] > pri[p])
        zig(p);
    } else {
      insert(rc[p], k);
      if (pri[rc[p]] > pri[p])
        zag(p);
    }
    push_up(p);
  }
  // ... 其余操作类似
};
```

**无旋 Treap（fhq Treap / 非旋 Treap）**：只靠 `split` 和 `merge` 两个操作实现一切，代码简洁，支持可持久化。

- `split(p, k)`：按排名/键值把树分成两棵。
- `merge(a, b)`：要求 $a$ 中所有键 $< b$ 中所有键，按优先级合并。

```cpp
void split(int p, int k, int &a, int &b) { // 前 k 个进 a
  if (!p) {
    a = b = 0;
    return;
  }
  if (sz[lc[p]] + 1 <= k) {
    a = p;
    split(rc[p], k - sz[lc[p]] - 1, rc[a], b);
  } else {
    b = p;
    split(lc[p], k, a, lc[b]);
  }
  push_up(p);
}

int merge(int a, int b) {
  if (!a || !b)
    return a + b;
  if (pri[a] > pri[b]) {
    rc[a] = merge(rc[a], b);
    push_up(a);
    return a;
  } else {
    lc[b] = merge(a, lc[b]);
    push_up(b);
    return b;
  }
}
```

fhq Treap 的经典应用：区间翻转（懒标记 `rev`，`push_down` 时交换左右儿子）、文艺平衡树、可持久化平衡树。

#### 1.7.2 Splay

Splay 树通过“每次访问节点后将其伸展到根”保证均摊 $O(\log n)$。核心是 `splay` 操作的三种双旋：一字型（zig-zig / zag-zag）与之字形（zig-zag / zag-zig）。**必须先旋转父亲再旋转自己**（先 zig 爷爷），这是均摊分析正确性的关键。

LCT（Link-Cut Tree）就是基于 Splay 实现的。

#### 1.7.3 替罪羊树

暴力重构：当某子树的“不平衡度”超过阈值（如 0.7）时，中序遍历后拍平重建。均摊 $O(\log n)$，代码极短，还支持各种奇怪的可删除操作。

### 1.8 分块

“大段维护、局部朴素”。数组分成长度 $\sqrt{n}$ 的块，整块打标记，散块暴力。修改查询 $O(\sqrt{n})$。

```cpp
int n, block, bcnt;
int bel[MAX_N], bl[MAX_N], br[MAX_N];
long long a[MAX_N], sum[MAX_N], addv[MAX_N];

void build_block() {
  block = (int)sqrt((double)n) + 1;
  bcnt = (n + block - 1) / block;
  for (int i = 1; i <= n; ++i)
    bel[i] = (i - 1) / block + 1;
  for (int i = 1; i <= bcnt; ++i) {
    bl[i] = (i - 1) * block + 1;
    br[i] = min(i * block, n);
  }
}

void update(int l, int r, long long d) {
  int p = bel[l], q = bel[r];
  if (p == q) {
    for (int i = l; i <= r; ++i)
      a[i] += d;
    sum[p] += d * (r - l + 1);
    return;
  }
  for (int i = l; i <= br[p]; ++i)
    a[i] += d;
  sum[p] += d * (br[p] - l + 1);
  for (int i = bl[q]; i <= r; ++i)
    a[i] += d;
  sum[q] += d * (r - bl[q] + 1);
  for (int i = p + 1; i < q; ++i) {
    addv[i] += d;
    sum[i] += d * (br[i] - bl[i] + 1);
  }
}
```

**块的常见姿势**：
- 块内排序 + 二分：区间查询“小于 $x$ 的个数”，$O(\sqrt{n} \log n)$。
- 值域分块：$O(1)$ 修改 $O(\sqrt{n})$ 查询第 $k$ 小（与线段树取长补短，避免两个 $\log$）。
- 带插入的分块：`vector` 块 + 定期重构（每 $\sqrt{n}$ 次插入重建一次）。
- 莫队算法的复杂度分析也依赖分块。

### 1.9 李超树、珂朵莉树与更多

**珂朵莉树（Chtholly Tree / 老司机树 ODT）**：用 `map`/`set` 维护若干个“颜色段”，每次操作只涉及 $O(\log n)$ 个连续段。在“区间赋值”操作占主导（数据随机）的题目中表现出均摊 $O(\log^2 n)$ 的复杂度。核心操作 `assign(l, r, v)`：把 $[l,r]$ 内的段全部删除后插入一个新段。

```cpp
struct Node {
  int l, r;
  mutable long long v;
  bool operator<(const Node &o) const { return l < o.l; }
};

set<Node> odt;

auto split(int x) {
  if (x > n)
    return odt.end();
  auto it = --odt.upper_bound((Node){x, 0, 0});
  if (it->l == x)
    return it;
  int l = it->l, r = it->r;
  long long v = it->v;
  odt.erase(it);
  odt.insert((Node){l, x - 1, v});
  return odt.insert((Node){x, r, v}).first;
}

void assign(int l, int r, long long v) {
  auto itr = split(r + 1), itl = split(l);
  odt.erase(itl, itr);
  odt.insert((Node){l, r, v});
}
```

**注意**：`split` 的调用顺序必须是先 `split(r+1)` 再 `split(l)`，否则迭代器可能失效！

---

## 第二部分：字符串算法

### 2.1 哈希

字符串哈希把字符串映射为整数，用单模数或双模数比较。常用多项式哈希：$h(s) = \sum_{i} s_i \cdot b^{len-i} \mod p$。

```cpp
typedef unsigned long long ull;

const ull BASE = 131;

ull pw[MAX_N], hsh[MAX_N];

void hash_init(const char *s, int n) {
  pw[0] = 1;
  for (int i = 1; i <= n; ++i)
    pw[i] = pw[i - 1] * BASE;
  for (int i = 1; i <= n; ++i)
    hsh[i] = hsh[i - 1] * BASE + s[i];
}

ull get_hash(int l, int r) {
  return hsh[r] - hsh[l - 1] * pw[r - l + 1];
}
```

用 `unsigned long long` 自然溢出等价于对 $2^{64}$ 取模，可被特殊构造的数据卡掉；稳妥起见用双哈希（两个不同模数），或使用 $10^{18}$ 级别的模数配合 `__int128` 做乘法取模。

**经典应用**：最长回文子串（二分+哈希，回文中心两侧二分）、后缀比较、允许 $k$ 次失配的匹配（哈希+二分找第一个不同点，$O(k \log n)$）。

### 2.2 KMP

KMP 算法求模式串在文本串中的出现。`nxt[i]` 定义为子串 $s[1..i]$ 的最长相等前后缀（不含自身）。

```cpp
int nxt[MAX_N];

void get_nxt(const char *p, int m) {
  nxt[1] = 0;
  for (int i = 2, j = 0; i <= m; ++i) {
    while (j && p[i] != p[j + 1])
      j = nxt[j];
    if (p[i] == p[j + 1])
      ++j;
    nxt[i] = j;
  }
}

int kmp(const char *s, int n, const char *p, int m) {
  int res = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j && (j == m || s[i] != p[j + 1]))
      j = nxt[j];
    if (s[i] == p[j + 1])
      ++j;
    if (j == m)
      ++res; // 在 i-m+1 处匹配
  }
  return res;
}
```

KMP 的 `nxt` 数组还有个隐藏应用：求循环节。若 $m \mid (m - nxt[m])$，则 $s$ 的最小循环节长度为 $m - nxt[m]$，否则 $m - nxt[m]$ 是“近似循环节”长度，补齐若干字符后可循环。

### 2.3 扩展 KMP（Z 函数）

$z_i$ 定义为后缀 $s[i..n]$ 与整个串 $s$ 的最长公共前缀长度。利用已计算的 $z$ 值加速当前计算，维护“匹配达到最右的区间” $[l, r]$。

```cpp
int z[MAX_N];

void z_func(const char *s, int n) {
  z[1] = n;
  for (int i = 2, l = 0, r = 0; i <= n; ++i) {
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l + 1]);
    while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}
```

### 2.4 Manacher

线性时间求出每个位置的回文半径。技巧：插入分隔符 `#` 把奇偶回文统一为奇回文。

```cpp
char t[MAX_N << 1];
int rad[MAX_N << 1];

int manacher(const char *s, int n) {
  int m = 0;
  t[++m] = '#';
  for (int i = 1; i <= n; ++i) {
    t[++m] = s[i];
    t[++m] = '#';
  }
  int res = 0, mid = 0, r = 0;
  for (int i = 1; i <= m; ++i) {
    if (i <= r)
      rad[i] = min(r - i + 1, rad[2 * mid - i]);
    while (i - rad[i] >= 1 && i + rad[i] <= m && t[i - rad[i]] == t[i + rad[i]])
      ++rad[i];
    if (i + rad[i] - 1 > r) {
      mid = i;
      r = i + rad[i] - 1;
    }
    res = max(res, rad[i] - 1);
  }
  return res;
}
```

### 2.5 AC 自动机

AC 自动机（Aho-Corasick）= Trie + KMP 的 fail 指针，多模式串匹配。

构建过程：BFS 每个节点，`fail[u]` 指向“u 所代表字符串的最长后缀对应的节点”。查询时沿 fail 链统计。

**失配树（fail 树）** 是 AC 自动机的核心结构：`fail[u]` 作为树边建树后，“模式串 $x$ 在文本 $t$ 中出现次数” = fail 树上 $x$ 节点的子树内有多少个“文本串前缀对应的 Trie 节点”。把文本串在 Trie 上跑一遍，沿途所有节点打 +1 标记，然后在 fail 树上做子树和。

```cpp
struct ACAutomaton {
  int ch[MAX_N][26], tot;
  int fail_[MAX_N];
  int cnt_[MAX_N];

  void init() { tot = 0; }

  void insert(const char *s) {
    int u = 0;
    for (int i = 1; s[i]; ++i) {
      int c = s[i] - 'a';
      if (!ch[u][c])
        ch[u][c] = ++tot;
      u = ch[u][c];
    }
  }

  void build() {
    queue<int> q;
    for (int c = 0; c < 26; ++c)
      if (ch[0][c])
        q.push(ch[0][c]);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int c = 0; c < 26; ++c) {
        if (ch[u][c]) {
          fail_[ch[u][c]] = ch[fail_[u]][c];
          q.push(ch[u][c]);
        } else {
          ch[u][c] = ch[fail_[u]][c]; // 路径压缩
        }
      }
    }
  }
};
```

注意这里用了“路径压缩”写法（不存在儿子直接指向 fail 节点的儿子），这样匹配时无需沿 fail 链跳，但也因此不能直接用 Trie 的原结构做树形 DP——压缩后的图叫 trie 图。

### 2.6 后缀数组

后缀数组 SA 是“把所有后缀按字典序排序”后的结果。倍增构造 $O(n \log n)$，或 DC3/SA-IS $O(n)$。

```cpp
int sa[MAX_N], rk[MAX_N], tmp[MAX_N], c[MAX_N];

void suffix_array(const char *s, int n, int m) {
  // 基数排序初始化
  for (int i = 1; i <= m; ++i)
    c[i] = 0;
  for (int i = 1; i <= n; ++i)
    ++c[rk[i] = s[i]];
  for (int i = 1; i <= m; ++i)
    c[i] += c[i - 1];
  for (int i = n; i >= 1; --i)
    sa[c[rk[i]]--] = i;

  for (int k = 1; k < n; k <<= 1) {
    int p = 0;
    for (int i = n - k + 1; i <= n; ++i)
      tmp[++p] = i;
    for (int i = 1; i <= n; ++i)
      if (sa[i] > k)
        tmp[++p] = sa[i] - k;
    for (int i = 1; i <= m; ++i)
      c[i] = 0;
    for (int i = 1; i <= n; ++i)
      ++c[rk[i]];
    for (int i = 1; i <= m; ++i)
      c[i] += c[i - 1];
    for (int i = n; i >= 1; --i)
      sa[c[rk[tmp[i]]]--] = tmp[i];
    swap(rk, tmp); // tmp 变成旧 rk
    p = 0;
    rk[sa[1]] = ++p;
    for (int i = 2; i <= n; ++i)
      rk[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] &&
                   tmp[sa[i] + k] == tmp[sa[i - 1] + k])
                      ? p
                      : ++p;
    if (p == n)
      break;
    m = p;
  }
}
```

**height 数组**：$h_i = \mathrm{lcp}(sa_{i-1}, sa_i)$。性质：$h_{rk_i} \ge h_{rk_{i-1}} - 1$，因此可以按排名顺序 $O(n)$ 递推。

$$h_i \ge h_{i-1} - 1$$

**经典结论**：后缀 $i$ 与后缀 $j$（$rk_i < rk_j$）的 LCP $= \min_{k=rk_i+1}^{rk_j} h_k$，即 RMQ。

**经典应用**：
- 本质不同子串数：$\frac{n(n+1)}{2} - \sum h_i$。
- 出现至少 $k$ 次的最长子串：height 数组上滑窗，求长度 $\ge k-1$ 的窗口内最小 height 的最大值。
- 两个串的最长公共子串：拼接后枚举 height，限制分属两个串。

### 2.7 后缀自动机（SAM）

SAM 是能接受字符串所有子串的最小 DFA。核心概念：`endpos` 集合、parent 树（后缀链树）。

**关键性质**：
1. 每个状态代表一个或多个 endpos 相同的子串，这些子串的长度是一段连续区间 $[\mathrm{len}(fa)+1, \mathrm{len}(u)]$。
2. parent 树上子节点的 endpos 是父节点 endpos 的子集。
3. `minlen(u) = len(fa(u)) + 1`。
4. 子串总数 $= \sum (\mathrm{len}(u) - \mathrm{len}(fa(u)))$。

```cpp
struct SAM {
  struct State {
    int len, link;
    int nxt[26];
  } st[MAX_N << 1];
  int tot, last;

  void init() {
    tot = last = 1;
    st[1].len = 0;
    st[1].link = 0;
  }

  void extend(int c) {
    int cur = ++tot;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p && !st[p].nxt[c]) {
      st[p].nxt[c] = cur;
      p = st[p].link;
    }
    if (!p) {
      st[cur].link = 1;
    } else {
      int q = st[p].nxt[c];
      if (st[p].len + 1 == st[q].len) {
        st[cur].link = q;
      } else {
        int clone = ++tot;
        st[clone] = st[q];
        st[clone].len = st[p].len + 1;
        while (p && st[p].nxt[c] == q) {
          st[p].nxt[c] = clone;
          p = st[p].link;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
};
```

**注意**：`st[clone] = st[q]` 会连 `nxt` 数组一起拷贝，这正是我们想要的。

**parent 树应用**：子串出现次数 = parent 树上子树内的“前缀节点”数量；广义 SAM 处理多串；SAM 上跑匹配可以求出每个前缀的最长匹配后缀。

### 2.8 回文自动机（PAM）

回文自动机的每个节点代表一个本质不同的回文串。两棵树：长度为奇数的树与偶数的树。`fail` 指向最长回文后缀。节点数不超过 $n+2$（本质不同回文串个数 $\le n$）。每个节点再维护 `len`、`cnt`（当前回文后缀的出现次数，沿 fail 链累加）。

### 2.9 Lyndon 分解

Lyndon 串：字典序小于其所有非平凡循环移位的串。Lyndon 分解（Duval 算法）$O(n)$ 把串分解为字典序不增的 Lyndon 串序列。

关键结论：**最小表示法**可以用 Lyndon 分解解决——把串倍长后做 Lyndon 分解，首个“起始位置超过原长”的 Lyndon 串的起点即为最小循环移位的起点。

---

## 第三部分：图论

### 3.1 图的存储

- 邻接矩阵：$O(n^2)$ 空间，适合稠密图与 Floyd。
- 链式前向星：数组模拟链表，`head[u]` + `nxt[]`，遍历效率高，是 OI 标准存图方式。
- `vector` 邻接表：方便，但可能有被卡常/爆内存的风险（`vector` 每次扩容拷贝）。

```cpp
int head[MAX_N], nxt[MAX_M << 1], to[MAX_M << 1], wgt[MAX_M << 1];
int etot;

void add_edge(int u, int v, int w) {
  ++etot;
  to[etot] = v;
  wgt[etot] = w;
  nxt[etot] = head[u];
  head[u] = etot;
}

// 遍历
for (int e = head[u]; e; e = nxt[e]) {
  int v = to[e];
  // ...
}
```

### 3.2 最短路

#### 3.2.1 Dijkstra

非负权图单源最短路。堆优化 $O((n+m)\log n)$。

```cpp
typedef pair<long long, int> pli;
priority_queue<pli, vector<pli>, greater<pli>> pq;
long long dis[MAX_N];
bool vis[MAX_N];

void dijkstra(int s) {
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  dis[s] = 0;
  pq.push(make_pair(0LL, s));
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    for (int e = head[u]; e; e = nxt[e]) {
      int v = to[e];
      long long nd = dis[u] + wgt[e];
      if (nd < dis[v]) {
        dis[v] = nd;
        pq.push(make_pair(nd, v));
      }
    }
  }
}
```

**注意**：`dis[u] + w` 可能溢出 `int`；用 `long long`，且初始化 `0x3f` 对 `long long` 来说只有约 $4.6 \times 10^{18}$，注意 `dis[u] + w` 是否可能加爆（一般 `0x3f3f3f3f3f3f3f3f` 配合 `INF = 4e18` 是安全的）。

#### 3.2.2 Bellman-Ford 与 SPFA

Bellman-Ford：松弛 $n-1$ 轮，能处理负权，能判负环。SPFA 是其队列优化，随机数据快，最坏 $O(nm)$，**NOI 系列比赛出题人默认卡 SPFA**。

SPFA 判负环的两种方法：① 记录最短路边数，超过 $n-1$ 则有负环；② 把 $n$ 个点全部初始入队（超级源点思想），用 cnt 统计松弛次数。

#### 3.2.3 Floyd

全源最短路，$O(n^3)$。注意循环顺序：**中转点 k 必须在最外层**。

```cpp
for (int k = 1; k <= n; ++k)
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (d[i][k] + d[k][j] < d[i][j])
        d[i][j] = d[i][k] + d[k][j];
```

Floyd 的 k 最外层使得 $d_{k}$ 只依赖 $d_{k-1}$，正确性来自 DP：$d_{k}[i][j]$ 表示“只经过前 $k$ 个点中转”的最短路。

**Floyd 传闭包 / 最小环**：最小环 = $\min_{i<j<k} d_{k-1}[i][j] + w(j,k) + w(k,i)$，在枚举 $k$ 时对 $i,j<k$ 计算。

#### 3.2.4 Johnson 全源最短路

对有负权而无负环的图：先跑 Bellman-Ford 求 $h_u$（势能），将边权改为 $w'(u,v) = w(u,v) + h_u - h_v \ge 0$，再每个点跑 Dijkstra。$O(nm \log n)$。

### 3.3 生成树

#### 3.3.1 Kruskal

边按权排序，用并查集避免环。$O(m \log m)$。

```cpp
struct Edge {
  int u, v, w;
  bool operator<(const Edge &o) const { return w < o.w; }
} ed[MAX_M];

int kruskal(int n, int m) {
  sort(ed + 1, ed + m + 1);
  dsu.init(n);
  int cnt = 0;
  long long total = 0;
  for (int i = 1; i <= m && cnt < n - 1; ++i) {
    if (dsu.unite(ed[i].u, ed[i].v)) {
      ++cnt;
      total += ed[i].w;
    }
  }
  return cnt == n - 1 ? total : -1;
}
```

**Kruskal 重构树**：建树过程中，每选一条边就新建一个节点（权值为边权），把两连通块的代表作为其儿子。性质：两点路径上边权最大值 = 重构树上 LCA 的权值；按权值 $\le x$ 能到达的点 = LCA 子树内所有叶子。这是处理“瓶颈类问题”的利器。

#### 3.3.2 Prim 与 Boruvka

Prim：任一点开始，每次选择距离树最近的点。堆优化 $O(m \log n)$，稠密图暴力 $O(n^2)$。

Boruvka：每轮每个连通块选择一条连出去的最小边，合并。轮数 $O(\log n)$，总 $O(m \log n)$。当“最小边”可以 $O(1)$ 或用数据结构快速求出时（如完全图但边权由公式给出），Boruvka 是唯一可行解法。

#### 3.3.3 最小生成树变体

- **次小生成树**：先求 MST，枚举非树边 $(u,v,w)$，替换路径上最大边（严格次小需同时维护严格次大边）。$O(m \log m)$。
- **瓶颈生成树 / 最小瓶颈路**：MST 即为瓶颈生成树。
- **度限制生成树**：NP-hard 的度数限制是 2（TSP），一般度限制可用 Wangerow 算法。
- **单度限制（$k=1$ 特殊点）**：先去掉特殊点建 MST，再拆树为若干连通块，每个块向特殊点连最小边。

### 3.4 树上问题

#### 3.4.1 树的直径

两次 DFS / BFS：任一点出发找最远点 $u$，再从 $u$ 出发找最远点 $v$，$u \to v$ 即为直径。也可树形 DP：维护每个点向下最长链 `d1` 与次长链 `d2`，直径 $= \max(d1_u + d2_u)$。后者可处理负权边。

#### 3.4.2 LCA

**倍增 LCA**：预处理 `fa[u][j]`（$u$ 的 $2^j$ 级祖先），查询先跳到同一深度再一起往上跳。$O(n \log n)$ 预处理，$O(\log n)$ 查询。

```cpp
int fa[MAX_N][21], dep[MAX_N];

void dfs(int u, int f) {
  fa[u][0] = f;
  dep[u] = dep[f] + 1;
  for (int j = 1; j <= 20; ++j)
    fa[u][j] = fa[fa[u][j - 1]][j - 1];
  for (int e = head[u]; e; e = nxt[e])
    if (to[e] != f)
      dfs(to[e], u);
}

int lca(int u, int v) {
  if (dep[u] < dep[v])
    swap(u, v);
  for (int j = 20; j >= 0; --j)
    if (dep[fa[u][j]] >= dep[v])
      u = fa[u][j];
  if (u == v)
    return u;
  for (int j = 20; j >= 0; --j)
    if (fa[u][j] != fa[v][j]) {
      u = fa[u][j];
      v = fa[v][j];
    }
  return fa[u][0];
}
```

**欧拉序 + ST 表**：DFS 记录进出的欧拉序，LCA = 区间深度最小。$O(1)$ 查询，配合树分块等需要大量 LCA 的算法。

**Tarjan LCA**：离线，DFS 回溯时用并查集，$O((n+q)\alpha)$。

#### 3.4.3 树链剖分

重链剖分：每个点选子树最大的儿子为重儿子，把树分成若干条竖直链，用数据结构（通常线段树）维护每条链。

```cpp
int sz_[MAX_N], dep[MAX_N], fa[MAX_N], son[MAX_N];
int top[MAX_N], dfn[MAX_N], rnk[MAX_N], dfs_clock;

void dfs1(int u, int f) {
  sz_[u] = 1;
  son[u] = 0;
  for (int e = head[u]; e; e = nxt[e]) {
    int v = to[e];
    if (v == f)
      continue;
    fa[v] = u;
    dep[v] = dep[u] + 1;
    dfs1(v, u);
    sz_[u] += sz_[v];
    if (sz_[v] > sz_[son[u]])
      son[u] = v;
  }
}

void dfs2(int u, int t) {
  top[u] = t;
  dfn[u] = ++dfs_clock;
  rnk[dfs_clock] = u;
  if (!son[u])
    return;
  dfs2(son[u], t);
  for (int e = head[u]; e; e = nxt[e]) {
    int v = to[e];
    if (v != fa[u] && v != son[u])
      dfs2(v, v);
  }
}

void path_update(int u, int v, long long d) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    seg.update(1, 1, n, dfn[top[u]], dfn[u], d);
    u = fa[top[u]];
  }
  if (dep[u] > dep[v])
    swap(u, v);
  seg.update(1, 1, n, dfn[u], dfn[v], d);
}
```

**关键性质**：一条链内的 dfn 连续；一个子树的 dfn 连续（$[dfn_u, dfn_u + sz_u - 1]$）。这使“路径操作”与“子树操作”都能转化为区间操作。

**长链剖分**：按深度最深的儿子剖分，性质：任意点到根经过的长链长度和为 $O(\sqrt{n})$（准确地说，经过的短链长度 $\le \sqrt{n}$ 条数级别）；链长恰好等于“以链头为根的子树的最大深度”。应用：$O(1)$ 求 $k$ 级祖先、与深度相关的 DP 值接上继承。

#### 3.4.4 树上启发式合并（DSU on tree）

统计“只与子树内信息相关”的离线询问。流程：轻儿子递归后清空，重儿子递归保留，再暴力加入轻子树与自身贡献。

```cpp
int cnt[MAX_N], son[MAX_N], sz_[MAX_N];
long long ans[MAX_N];
bool big[MAX_N];

void add(int u, int f, int val) {
  cnt[col[u]] += val;
  for (int e = head[u]; e; e = nxt[e])
    if (to[e] != f && !big[to[e]])
      add(to[e], u, val);
}

void dfs(int u, int f, bool keep) {
  for (int e = head[u]; e; e = nxt[e])
    if (to[e] != f && to[e] != son[u])
      dfs(to[e], u, false);
  if (son[u]) {
    dfs(son[u], u, true);
    big[son[u]] = true;
  }
  add(u, f, 1); // 加入自己与轻子树
  // 此处统计以 u 为根的答案
  ans[u] = ...;
  if (son[u])
    big[son[u]] = false;
  if (!keep)
    add(u, f, -1); // 清空
}
```

复杂度：每个点到根路径上轻边 $O(\log n)$ 条，每条轻边导致一次 $O(sz)$ 的暴力，总计 $O(n \log n)$。

### 3.5 连通性

#### 3.5.1 Tarjan 求割点与桥

`dfn[u]` 为 DFS 序，`low[u]` 为 $u$ 经子树内至多一条返祖边能到达的最小 dfn。

- 割点判定：$u$ 是根且有 $\ge 2$ 个子树；或非根且存在儿子 $v$ 满足 $low_v \ge dfn_u$。
- 桥判定：树边 $(u, v)$ 满足 $low_v > dfn_u$。**注意**：桥的判定不能容忍重边，若原图有重边，一条重边不算桥，需要用“边编号”而不是“父亲点”来判禁止访问。

```cpp
int dfn[MAX_N], low[MAX_N], clk;
bool cut[MAX_N];

void tarjan(int u, int in_edge) {
  dfn[u] = low[u] = ++clk;
  int child = 0;
  for (int e = head[u]; e; e = nxt[e]) {
    int v = to[e];
    if (!dfn[v]) {
      ++child;
      tarjan(v, e);
      low[u] = min(low[u], low[v]);
      if (in_edge == 0 && child > 1)
        cut[u] = true; // 根
      if (in_edge != 0 && low[v] >= dfn[u])
        cut[u] = true; // 非根
      if (low[v] > dfn[u])
        is_bridge[e] = is_bridge[e ^ 1] = true;
    } else if (e != (in_edge ^ 1)) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}
```

（此处用了 `etot` 从 1 开始、边 $e$ 与 $e \oplus 1$ 互为反向边的技巧，所以 0 号边作为哨兵。）

#### 3.5.2 边双与点双

- **边双连通分量（E-DCC）**：把桥全部删掉后的连通块。缩点后是一棵树。
- **点双连通分量（V-DCC）**：极大“无割点”子图。注意点双之间通过割点连接，一个割点可属于多个点双。
- **圆方树**：每个点双建一个方点，圆点向方点连边。点双圆方树把“图上的路径问题”转化为“树上的路径问题”，例如求必经点（路径上圆点个数 - 1）。

```cpp
void tarjan(int u) {
  dfn[u] = low[u] = ++clk;
  stk.push(u);
  for (int e = head[u]; e; e = nxt[e]) {
    int v = to[e];
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u]) {
        // u 是割点（若非首次访问），弹栈至 v 构成一个点双
        ++bcc_cnt;
        while (true) {
          int x = stk.top();
          stk.pop();
          bcc[bcc_cnt].push_back(x);
          if (x == v)
            break;
        }
        bcc[bcc_cnt].push_back(u);
      }
    } else {
      low[u] = min(low[u], dfn[v]);
    }
  }
}
```

#### 3.5.3 有向图强连通分量（SCC）

Tarjan / Kosaraju 两种实现。Tarjan 用栈维护未确定分量的节点；Kosaraju 跑两遍 DFS（正图反图）。缩点后是 DAG，可以 DP 求“最长路”等。

**半群复合性质**：DAG 上 DP 的顺序 = 缩点后拓扑序。缩点代码：

```cpp
void tarjan(int u) {
  dfn[u] = low[u] = ++clk;
  stk[++top] = u;
  in_stk[u] = true;
  for (int e = head[u]; e; e = nxt[e]) {
    int v = to[e];
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stk[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++scc_cnt;
    while (true) {
      int x = stk[top--];
      in_stk[x] = false;
      bel[x] = scc_cnt;
      if (x == u)
        break;
    }
  }
}
```

**注意**：Tarjan 缩点后的 SCC 编号恰好是**拓扑序的逆序**（编号大的拓扑序在前），新建图时无需再跑拓扑排序，直接按 scc_cnt → 1 的顺序 DP。

#### 3.5.4 2-SAT

把布尔变量拆成 $x$ 与 $\neg x$ 两个点，约束转边：$a \lor b$ 等价于 $\neg a \to b$ 与 $\neg b \to a$。跑 SCC，$x$ 与 $\neg x$ 不同分量时有解，选择“SCC 编号更大”的那个取值即得一组方案。

常见约束的连边：
- $a \lor b$：$\neg a \to b$，$\neg b \to a$。
- $a \to b$：$a \to b$，$\neg b \to \neg a$。
- $a = b$：$a \to b$，$b \to a$，$\neg a \to \neg b$，$\neg b \to \neg a$。
- $a \ne b$：$a \to \neg b$，$\neg b \to a$，$b \to \neg a$，$\neg a \to b$。

### 3.6 网络流

#### 3.6.1 最大流

**EK 算法**：BFS 找增广路，$O(n m^2)$。
**Dinic**：BFS 分层 + DFS 多路增广 + 当前弧优化，$O(n^2 m)$；单位容量图 $O(m\sqrt{n})$（二分图匹配 $O(m\sqrt{n})$）。

```cpp
struct Dinic {
  int head[MAX_N], nxt[MAX_M], to[MAX_M];
  long long cap[MAX_M];
  int etot = 1; // 从 1 开始，e 与 e^1 互为反向边
  int cur[MAX_N], dis[MAX_N];

  void add_edge(int u, int v, long long c) {
    ++etot;
    to[etot] = v;
    cap[etot] = c;
    nxt[etot] = head[u];
    head[u] = etot;
  }

  bool bfs(int s, int t) {
    queue<int> q;
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int e = head[u]; e; e = nxt[e])
        if (cap[e] > 0 && dis[to[e]] == -1) {
          dis[to[e]] = dis[u] + 1;
          q.push(to[e]);
        }
    }
    return dis[t] != -1;
  }

  long long dfs(int u, int t, long long lim) {
    if (u == t)
      return lim;
    long long used = 0;
    for (int &e = cur[u]; e; e = nxt[e]) { // 当前弧
      int v = to[e];
      if (cap[e] > 0 && dis[v] == dis[u] + 1) {
        long long f = dfs(v, t, min(lim - used, cap[e]));
        if (f > 0) {
          cap[e] -= f;
          cap[e ^ 1] += f;
          used += f;
          if (used == lim)
            break;
        }
      }
    }
    if (!used)
      dis[u] = -1; // 炸点优化
    return used;
  }

  long long maxflow(int s, int t) {
    long long res = 0;
    while (bfs(s, t)) {
      memcpy(cur, head, sizeof(head));
      res += dfs(s, t, INF);
    }
    return res;
  }
};
```

**当前弧优化**是 Dinic 必须的：每次 DFS 中已经流满的弧不再遍历。

#### 3.6.2 最小割

最大流 = 最小割。割边集的判定：残量网络中从 $s$ 可达的点集为 $S$，其余为 $T$，$S \to T$ 的原图边构成最小割。

**最小割建模的三个经典技巧**：
1. **点权转边权**：点拆成入点出点，中间连容量为点权的边。
2. **二者选其一**：$s \to x$ 表示选 A，$x \to t$ 表示选 B，割掉哪条边即付出哪个代价。
3. **“必须同时”关系**：用 $\inf$ 边强制某两条割边不能同时保留/割掉。

#### 3.6.3 费用流

把 Dinic 的 BFS 换成 SPFA（处理负权），找最短增广路。或者用 Johnson 初始加势能 + Dijkstra（势能更新：$h_v = min(h_v, h_u + w')$，最终边权 $\ge 0$）。

**经典应用**：K 小区间和、最长 $k$ 可重区间集、棋盘覆盖问题。核心思路都是“把题目中的选择离散成流”，费用对应权值。

#### 3.6.4 上下界网络流

- 无源汇上下界可行流：每条边拆出下界 $l$ 的“必须流量”，额外建 $s' \to u$（$u$ 的流出下界和 > 流入下界和时）或 $u \to t'$，跑普通最大流。
- 有源汇：$t \to s$ 连 $\inf$ 边转为无源汇。
- 上下界最小/最大流 = 可行流基础上的残量网络增广。

### 3.7 二分图

- **Hall 定理**：二分图 $X$ 部存在完美匹配 $\iff$ $\forall S \subseteq X, |N(S)| \ge |S|$。扩展形式（Hall 定理的缺陷版）：$X$ 部最大匹配 $= |X| - \max_{S}( |S| - |N(S)| )$。
- **König 定理**：二分图最小点覆盖 = 最大匹配数。
- **最大独立集 = n − 最小点覆盖 = n − 最大匹配**。
- **DAG 最小路径覆盖**（路径可不相交）= $n -$ 拆点二分图最大匹配。
- **DAG 最小链覆盖**（路径可相交）= 传递闭包后的最小路径覆盖。

**KM 算法**（带权完美匹配）：维护顶标 $lx, ly$，相等子图内的边，用“调整 slack”扩展。$O(n^3)$。

---

## 第四部分：动态规划

### 4.1 线性 DP

**LIS**：最长递增子序列。贪心 + 二分 $O(n \log n)$：`f[i]` 维护长度为 $i$ 的 LIS 的最小结尾。

```cpp
int len = 0;
for (int i = 1; i <= n; ++i) {
  if (len == 0 || f[len] < a[i])
    f[++len] = a[i];
  else
    *lower_bound(f + 1, f + len + 1, a[i]) = a[i];
}
```

**LCS**：经典 $O(n^2)$，或转化为 LIS（当两串字符互异或用排名映射后）$O(n \log n)$。

**背包九讲要点**：
- 01 背包：`for i: for v from V downto w[i]`（倒序保证每件只选一次）。
- 完全背包：正序。
- 多重背包：二进制拆分（每件拆 $1, 2, 4, \dots$）或单调队列优化（$f_v = \max_{0\le k\le c_i} f'_{v - k w_i} + k val_i$，按 $v \bmod w_i$ 分层单调队列）。
- 分组背包：先枚举组，再组内枚举物品，体积倒序。
- 二维费用、树上依赖背包（“有依赖的背包”用 dfs 合并，$O(nV)$：儿子间做分组背包，加上父节点强制选）。

### 4.2 区间 DP

**石子合并**：$f_{l,r} = \min_{k} f_{l,k} + f_{k+1,r} + w(l,r)$，$O(n^3)$。四边形不等式优化到 $O(n^2)$（决策点单调）。

**四边形不等式（区间包含单调 + 满足交叉不等）**：若 $w(a,d) + w(b,c) \ge w(a,c) + w(b,d)$（$a\le b\le c\le d$），则该区间 DP 满足决策单调性，$p_{l,r-1} \le p_{l,r} \le p_{l+1,r}$。

```cpp
for (int len = 2; len <= n; ++len)
  for (int l = 1, r = len; r <= n; ++l, ++r) {
    f[l][r] = INF;
    for (int k = p[l][r - 1]; k <= p[l + 1][r]; ++k)
      if (f[l][k] + f[k + 1][r] + w(l, r) < f[l][r]) {
        f[l][r] = f[l][k] + f[k + 1][r] + w(l, r);
        p[l][r] = k;
      }
  }
```

（边界 `p[i][i] = i`、`p[i][i-1]` 之类的初始化要小心。）

### 4.3 树形 DP

**没有上司的舞会**（最大权独立集）：$f_{u,0/1}$ 表示 $u$ 不选/选时子树最大权值。

**树上背包**：合并子树时体积枚举上限取 $\min(\text{size}, V)$，可以证明复杂度是 $O(nV)$ 而非 $O(n^2 V)$。

**换根 DP（二次扫描）**：第一遍 dfs 求“以 1 为根的答案”与子树贡献，第二遍 dfs 用父节点信息推出“换根后”的答案。典型题：求使“到所有点距离和”最小的重心类问题。

```cpp
// up[v]：v 之外的所有节点对 v 的贡献
void dfs2(int u, int f) {
  for (int e = head[u]; e; e = nxt[e]) {
    int v = to[e];
    if (v == f)
      continue;
    up[v] = up[u] + down_calc_sibling(u, v) + edge_w(e);
    dfs2(v, u);
  }
}
```

### 4.4 状压 DP

$n \le 20$ 左右的集合枚举。常用位运算技巧：

```cpp
for (int S = 0; S < (1 << n); ++S)
  for (int T = S; T; T = (T - 1) & S) // 枚举子集
    f[S] = max(f[S], f[T] + g[S ^ T]);
```

枚举子集的总复杂度是 $O(3^n)$。子集枚举配合预处理 `popcount`（C++14 中自己写 `__builtin_popcount`）。

**高维前缀和（SOS DP）**：对集合做“超集和/子集和”的 DP，$O(n 2^n)$：

```cpp
for (int j = 0; j < n; ++j)
  for (int S = 0; S < (1 << n); ++S)
    if (S >> j & 1)
      f[S] += f[S ^ (1 << j)];
```

**典型题**：Corn Fields、互不侵犯（棋盘状压，逐行转移 + 轮廓线）、炮兵阵地（状压两层）。

### 4.5 数位 DP

统计 $[l, r]$ 中满足条件的数：`dfs(pos, state, limit, lead)`。`limit` 表示前面是否贴着上界，`lead` 表示是否有前导零。记忆化只能对 `limit == false && lead == false` 的状态生效。

```cpp
long long dp[21][STATE];
int digits[21], len;

long long dfs(int pos, int st, bool limit, bool lead) {
  if (pos == 0)
    return /* 终态判断 */;
  if (!limit && !lead && dp[pos][st] != -1)
    return dp[pos][st];
  int up = limit ? digits[pos] : 9;
  long long res = 0;
  for (int d = 0; d <= up; ++d) {
    int nst = /* 转移 */;
    res += dfs(pos - 1, nst, limit && d == up, lead && d == 0);
  }
  if (!limit && !lead)
    dp[pos][st] = res;
  return res;
}

long long solve(long long x) {
  len = 0;
  while (x) {
    digits[++len] = x % 10;
    x /= 10;
  }
  memset(dp, -1, sizeof(dp));
  return dfs(len, 0, true, true);
}
```

**减法陷阱**：`solve(r) - solve(l - 1)` 当 $l = 0$ 时 `l - 1 = -1` 会死循环，需特判。

### 4.6 概率与期望 DP

期望的线性性：$E[X + Y] = E[X] + E[Y]$（无需独立）。这是期望题的第一武器。

**逆推期望**：一般从终态倒推（尤其有环时需解方程）。无环时直接拓扑序 DP；有环时高斯消元 $O(n^3)$ 或利用图的特殊结构（如“有向无环图上的随机游走”）。

**经典模型**：
- 随机游走：走到 $n$ 的期望步数，$f_i = 1 + \frac{f_{i-1} + f_{i+1}}{2}$ 型（游走于数轴），解差分方程。
- 收集邮票：第 $k$ 张邮票的价格是 $k^2$ 之类的平方期望，用 $E[x^2] = E[x]^2 + Var[x]$ 或直接维护 $E[x^2]$ 的递推。

### 4.7 DP 优化

#### 4.7.1 单调队列 / 单调栈优化

转移形如 $f_i = \min_{j \in [i-c, i-1]} f_j + w(i)$ 时，滑动窗口最小值用单调队列 $O(n)$。

#### 4.7.2 斜率优化

转移 $f_i = \min_{j<i} \{ f_j + (s_i - s_j)^2 \}$ 展开后是关于 $s_j$ 的一次函数与 $s_i$ 的乘积——维护下凸包，均摊 $O(n)$。

一般形式：$f_i = \min\{a_i \cdot b_j + c_j\} + d_i$。把 $(b_j, c_j)$ 看作直线 $y = b_j x + c_j$，即李超线段树 / 凸包问题。若 $a_i$ 单调则单调队列维护凸包；否则 CDQ 分治 / 李超树 / 平衡树维护。

```cpp
// 斜率不单调的凸包查询用二分
int find(int h, int t, long long x) {
  while (h < t && slope(q[h], q[h + 1]) <= x)
    ++h; // 此时 h 是最优决策
  return q[h];
}
```

#### 4.7.3 决策单调性（分治 / Knuth 优化）

若转移满足**四边形不等式**（$w$ 满足交叉 $\le$ 包含，即“代价函数凸”），则决策点单调不降。整体二分（分治 DP）：`solve(l, r, ql, qr)` 解决 $[l,r]$ 的状态，用中点 $mid$ 的决策 $p_{mid}$ 把 $[ql,qr]$ 分成两半。

复杂度 $O(n \log n \times \text{计算 } w \text{ 的代价})$；若用二维指针维护 $w$，则类似莫队，$O(n \log n \sqrt{n})$ 摊还……不对，二维指针在分治下复杂度分析较复杂，一般每层指针移动 $O(n)$，总 $O(n \log n)$ 的说法需要满足条件，谨慎使用，实测能用。

#### 4.7.4 数据结构优化 DP

- CDQ 分治优化 2D/1D 动态规划（如“最长上升子序列的带权版本”）：按第一维分治，左半贡献到右半。
- 线段树维护 dp 值（单点改、区间查 max）。
- 可撤销数据结构 + DSU on tree。

#### 4.7.5 矩阵快速幂加速

状态转移为线性齐次递推时，用矩阵快速幂把 $O(n)$ 次转移压到 $O(k^3 \log n)$。典型：Fibonacci、路径计数（邻接矩阵的 $k$ 次幂）、图上“恰好走 $k$ 步”问题。

```cpp
struct Matrix {
  long long a[K][K];
  Matrix() { memset(a, 0, sizeof(a)); }
  Matrix operator*(const Matrix &o) const {
    Matrix res;
    for (int i = 0; i < K; ++i)
      for (int k = 0; k < K; ++k) {
        if (a[i][k] == 0)
          continue;
        for (int j = 0; j < K; ++j)
          res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
      }
    return res;
  }
};

Matrix mat_pow(Matrix b, long long e) {
  Matrix res;
  for (int i = 0; i < K; ++i)
    res.a[i][i] = 1;
  while (e) {
    if (e & 1)
      res = res * b;
    b = b * b;
    e >>= 1;
  }
  return res;
}
```

（矩阵乘法的 $i,k,j$ 循环顺序对缓存友好，可显著提速。）

---

## 第五部分：数学

### 5.1 数论基础

#### 5.1.1 素数筛

**欧拉筛（线性筛）**：

```cpp
int primes[MAX_N], pcnt;
bool comp[MAX_N];

void sieve(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!comp[i])
      primes[++pcnt] = i;
    for (int j = 1; j <= pcnt && (long long)i * primes[j] <= n; ++j) {
      comp[i * primes[j]] = true;
      if (i % primes[j] == 0)
        break; // 保证每个合数只被最小质因子筛一次
    }
  }
}
```

线性筛配合积性函数的性质：$f$ 积性时只需算 $f(p^k)$（$i \% p == 0$ 时利用 $i$ 与 $p$ 的关系）。例如欧拉函数：`phi[i*p] = (i % p == 0) ? phi[i] * p : phi[i] * (p - 1)`。

#### 5.1.2 gcd / exgcd

```cpp
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}
```

**线性同余方程** $ax \equiv b \pmod m$ 有解 $\iff \gcd(a, m) \mid b$。

**中国剩余定理（CRT）**：模数两两互质时合并；**exCRT** 处理不互质情形——逐个合并，每次解 $(k_1 m_1 - k_2 m_2 = r_2 - r_1)$，无解当且仅当 $\gcd(m_1,m_2) \nmid (r_2 - r_1)$。合并后模数翻倍会爆 `long long`，需要 `__int128` 或龟速乘。

#### 5.1.3 欧拉函数与欧拉定理

- $\varphi(n) = n \prod_{p \mid n} (1 - \frac{1}{p})$。
- 欧拉定理：$\gcd(a,n)=1 \Rightarrow a^{\varphi(n)} \equiv 1 \pmod n$。
- 扩展欧拉定理（降幂）：$a^b \equiv a^{b \bmod \varphi(n) + \varphi(n)} \pmod n$（当 $b \ge \log_2 n$ 时）。

#### 5.1.4 逆元

- 费马小定理：$a^{-1} \equiv a^{p-2} \pmod p$（$p$ 素数），单次 $O(\log p)$。
- 线性递推：$inv[i] = -(p / i) \cdot inv[p \% i] \bmod p$。
- 阶乘逆元：`inv_fact[n] = pow(fact[n], p-2)`，然后 `inv_fact[i] = inv_fact[i+1] * (i+1) % p`。

#### 5.1.5 BSGS 与 exBSGS

求 $a^x \equiv b \pmod p$ 的最小 $x$。大步小步：令 $x = i \cdot m - j$（$m = \lceil\sqrt{p}\rceil$），用哈希表存 $a^j \cdot b$，枚举 $i$ 查询。$O(\sqrt{p})$。exBSGS 处理 $\gcd(a,p) \ne 1$：不断除以 $d = \gcd(a, p)$ 直到互质，中间的每一步检查可整除性。

### 5.2 组合数学

**常见恒等式**：

$$\binom{n}{m} = \binom{n-1}{m-1} + \binom{n-1}{m}$$

$$\binom{n}{m}\binom{m}{k} = \binom{n}{k}\binom{n-k}{m-k}$$

$$\sum_{i=0}^{n} \binom{n}{i} = 2^n, \qquad \sum_{i=0}^{n} \binom{n}{i}^2 = \binom{2n}{n}$$

$$\sum_{i=0}^{m} \binom{n+i}{i} = \binom{n+m+1}{m} \quad \text{( hockey stick)}$$

**Lucas 定理**：$p$ 素数时 $\binom{n}{m} \bmod p = \binom{n/p}{m/p} \binom{n \bmod p}{m \bmod p} \bmod p$。

**Catalan 数**：$C_n = \frac{1}{n+1}\binom{2n}{n} = \binom{2n}{n} - \binom{2n}{n-1}$。计数对象：合法括号序、出栈序列、二叉树形态、不相交弦、格路计数（不穿过对角线）。

**Stirling 数**：
- 第一类（无符号）：$s(n,k)$ 把 $n$ 个元素排成 $k$ 个圆排列的方案数；$\sum_k s(n,k) x^k = x^{\overline{n}}$（上升阶乘）。
- 第二类：$S(n,k)$ 把 $n$ 个元素分成 $k$ 个非空无差别集合的方案数；$S(n,k) = k S(n-1,k) + S(n-1,k-1)$；$x^n = \sum_k S(n,k) x^{\underline{k}}$。

**容斥原理**：

$$\left| \bigcup_{i=1}^{n} A_i \right| = \sum_{\emptyset \ne J} (-1)^{|J|+1} \left| \bigcap_{j \in J} A_j \right|$$

**二项式反演**：

$$f_n = \sum_{i=0}^{n} \binom{n}{i} g_i \iff g_n = \sum_{i=0}^{n} (-1)^{n-i} \binom{n}{i} f_i$$

$$f_n = \sum_{i=n}^{m} \binom{i}{n} g_i \iff g_n = \sum_{i=n}^{m} (-1)^{i-n} \binom{i}{n} f_i$$

**Min-Max 容斥**：

$$\max(S) = \sum_{T \subseteq S} (-1)^{|T|+1} \min(T)$$

在期望意义下同样成立：$E[\max] = \sum (-1)^{|T|+1} E[\min]$。这是“收集全部元素的期望时间”类题目的关键。

### 5.3 多项式与生成函数

**NTT**：模数 $998244353 = 119 \times 2^{23} + 1$，原根 3。蝶形变换用迭代写法（先 bit-reversal 再逐层合并）。

```cpp
void ntt(long long *a, int n, bool inv) {
  for (int i = 0; i < n; ++i)
    if (i < rev[i])
      swap(a[i], a[rev[i]]);
  for (int len = 2; len <= n; len <<= 1) {
    long long gn = mat_pow(3, (MOD - 1) / len);
    if (inv)
      gn = mat_pow(gn, MOD - 2);
    for (int i = 0; i < n; i += len) {
      long long g = 1;
      for (int j = 0; j < len / 2; ++j) {
        long long u = a[i + j], v = a[i + j + len / 2] * g % MOD;
        a[i + j] = (u + v) % MOD;
        a[i + j + len / 2] = (u - v + MOD) % MOD;
        g = g * gn % MOD;
      }
    }
  }
  if (inv) {
    long long inv_n = mat_pow(n, MOD - 2);
    for (int i = 0; i < n; ++i)
      a[i] = a[i] * inv_n % MOD;
  }
}
```

**多项式全家桶**（基于 NTT + 牛顿迭代）：
- 多项式乘法 / 逆（$B \equiv B_0 (2 - A B_0) \pmod {x^n}$）。
- 开根（$B \equiv \frac{1}{2}(B_0 + A B_0^{-1})$）。
- $\ln$（求导 + 逆 + 积分）。
- $\exp$（牛顿迭代解 $B' = B(\ln A)'$）。
- 多项式除法 / 取模（翻转后求逆）。
- 多项式快速幂（$\exp(k \ln A)$，注意常数项为 1 才能直接 ln）。

**FWT / 位运算卷积**：
- OR 卷积 = 高维前缀和（SOS）。
- AND 卷积 = 高维后缀和。
- XOR 卷积 = 沃尔什变换（每维做 $(a+b, a-b)$）。
- 子集卷积：占位多项式 $f_{S,popcount}$ 的 OR 卷积后只取 $popcount$ 相同的项。

**生成函数速查**：

$$\frac{1}{1-x} = \sum x^i,\quad e^x = \sum \frac{x^i}{i!},\quad \ln(1+x) = \sum \frac{(-1)^{i-1} x^i}{i}$$

$$\frac{1}{(1-x)^k} = \sum \binom{i+k-1}{k-1} x^i$$

**Burnside / Pólya**：轨道数 $= \frac{1}{|G|}\sum_{g \in G} |X^g|$。Pólya 用循环指标写成 $\frac{1}{|G|}\sum_g m^{\mathrm{cyc}(g)}$。项链染色是模板题。

### 5.4 线性代数

**高斯消元**：$O(n^3)$。注意选主元避免精度问题；异或方程组用 bitset 加速到 $O(n^3 / w)$。

**矩阵的秩 / 线性基**：

线性基是“异或空间的高斯消元”，维护一组向量使它们能张成原集合的所有异或和。

```cpp
long long basis[60];

bool insert_val(long long x) {
  for (int i = 59; i >= 0; --i) {
    if (!(x >> i & 1))
      continue;
    if (!basis[i]) {
      basis[i] = x;
      return true;
    }
    x ^= basis[i];
  }
  return false; // x 可被表示，即异或和为 0 的子集存在
}

long long query_max(long long start) {
  long long res = start;
  for (int i = 59; i >= 0; --i)
    res = max(res, res ^ basis[i]);
  return res;
}

long long query_kth(long long k) { // 第 k 小（k 从 1 开始）
  long long res = 0;
  int rank = 0;
  for (int i = 0; i < 60; ++i) {
    if (!basis[i])
      continue;
    ++rank;
    if (k & 1)  // 处理后 k 的二进制对应……
      res ^= basis[i];
    k >>= 1;
  }
  return res; // 细节：需先做“消除主元位互相包含”的处理
}
```

线性基的性质：插入 $O(\log V)$；第 $k$ 小查询前需要做“对角化”，让每个主元位只在一个基向量中为 1；能表示的数恰好有 $2^{rank}$ 个（含 0）；判断某个数能否被表示 = 插入是否失败。

**Matrix-Tree 定理**：生成树个数 = 度数矩阵 − 邻接矩阵（去掉一行一列）的行列式（带权版本：边权放进入度与邻接矩阵）。

**BEST 定理**：有向图欧拉回路条数 = $t_w \cdot \prod_v (\deg_v - 1)!$，其中 $t_w$ 是以 $w$ 为根的内向树个数。

### 5.5 数值方法与杂项

**快速乘**：`__int128` 或龟速乘 $O(\log)$。模数接近 $10^{18}$ 时乘法需要 `long double` 技巧或 `__int128`。

**二次剩余（Cipolla）**：判定 $x^2 \equiv a \pmod p$ 是否有解用欧拉判别 $a^{(p-1)/2}$，求解用随机域扩张 $t^2 - a$ 无解时在 $\mathbb{F}_p(\sqrt{t^2-a})$ 中计算 $(t + \sqrt{t^2-a})^{(p+1)/2}$。

**原根**：$p$ 有原根当且仅当 $p \in \{2,4,q^k,2q^k\}$（$q$ 奇素数）。求法：枚举 $g$，检验对所有 $\varphi(p)$ 的素因子 $q$ 有 $g^{\varphi(p)/q} \ne 1$。

**分数 / Stern-Brocot 树 / Farey 序列**：找到分母不超过 $n$ 的最接近分数，用 Stern-Brocot 树二分（每次 L+R），复杂度与答案规模相关。

**裴蜀定理**：$ax + by = c$ 有整数解 $\iff \gcd(a,b) \mid c$。

**类欧几里得**：$f(a,b,c,n) = \sum_{i=0}^{n} \lfloor \frac{ai+b}{c} \rfloor$ 递归 $O(\log)$ 求解，三项联合递归（连同 $\sum i \lfloor\cdot\rfloor$ 与 $\sum \lfloor\cdot\rfloor^2$）。

### 5.6 莫比乌斯反演与杜教筛

**莫比乌斯函数**：$\mu(n) = 0$（含平方因子），否则 $(-1)^{\omega(n)}$。$\sum_{d \mid n} \mu(d) = [n = 1]$。

**反演公式**：

$$F(n) = \sum_{d \mid n} f(d) \iff f(n) = \sum_{d \mid n} \mu\left(\frac{n}{d}\right) F(d)$$

**整除分块**：$\lfloor n/i \rfloor$ 只有 $O(\sqrt n)$ 种取值。

```cpp
for (long long l = 1, r; l <= n; l = r + 1) {
  r = n / (n / l);
  // [l, r] 内 n/i 相同
}
```

**杜教筛**：求 $S(n) = \sum_{i=1}^n f(i)$，找到 $g$ 使 $f * g = h$ 且 $h, g$ 的前缀和易求，则 $S(n) = \frac{1}{g(1)}\left( H(n) - \sum_{d=2}^{n} g(d) S(\lfloor n/d \rfloor) \right)$，配合线性筛预处理 $n^{2/3}$ 以内的值，总复杂度 $O(n^{2/3})$。

**min_25 筛 / Powerful Number 筛**：处理积性函数前缀和的更强武器。min_25 筛的核心是“合数的最小质因子 $\le \sqrt{n}$”，先用只含质数的 DP（$g$ 数组）筛出质数处的取值和，再逐层枚举最小质因子还原。

---

## 第六部分：计算几何

### 6.1 基础模板

```cpp
const double EPS = 1e-9;

int sgn(double x) { return x < -EPS ? -1 : x > EPS; }

struct Point {
  double x, y;
  Point(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
  Point operator+(const Point &o) const { return Point(x + o.x, y + o.y); }
  Point operator-(const Point &o) const { return Point(x - o.x, y - o.y); }
  Point operator*(double k) const { return Point(x * k, y * k); }
  double operator*(const Point &o) const { return x * o.y - y * o.x; } // 叉积
  double dot(const Point &o) const { return x * o.x + y * o.y; }
  double len() const { return sqrt(x * x + y * y); }
};

double cross(const Point &o, const Point &a, const Point &b) {
  return (a - o) * (b - o);
}
```

**叉积**的正负表示 $b$ 在 $oa$ 的逆时针/顺时针方向（左手系/右手系），是所有几何算法的核心。

### 6.2 凸包

Andrew 算法：排序后正反两遍扫描，$O(n \log n)$。

```cpp
bool cmp_xy(const Point &a, const Point &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int convex_hull(Point *p, int n, Point *ch) {
  sort(p + 1, p + n + 1, cmp_xy);
  int m = 0;
  for (int i = 1; i <= n; ++i) { // 下凸壳
    while (m > 1 && cross(ch[m - 1], ch[m], p[i]) <= 0)
      --m;
    ch[++m] = p[i];
  }
  int k = m;
  for (int i = n - 1; i >= 1; --i) { // 上凸壳
    while (m > k && cross(ch[m - 1], ch[m], p[i]) <= 0)
      --m;
    ch[++m] = p[i];
  }
  if (n > 1)
    --m; // 首尾重复
  return m;
}
```

### 6.3 旋转卡壳

求凸包直径：两条平行卡壳线旋转，对踵点对的单调性使总复杂度 $O(n)$。注意“面积最大的三角形”需要在旋转卡壳的同时用另一个指针维护第三个点。

### 6.4 半平面交

每条直线表示一个半平面（用“点+方向向量”或“直线左侧”约定），排序后单调栈维护。$O(n \log n)$。结果可能是空集 / 无界区域，通常加一个巨大的框使其有界。

### 6.5 其他常见算法

- **判断点在线段上**：叉积为零 + 点积夹在中间。
- **线段相交**：快速排斥 + 跨立实验。
- **多边形面积**：$\frac{1}{2}|\sum p_i \times p_{i+1}|$（鞋带公式）。
- **点在多边形内**：射线法（注意穿过顶点的特判）或转角法。
- **圆与直线 / 圆与圆的交**：几何 + 代数联立，注意无解/一解/二解的分类。
- **最近点对**：分治，按 $x$ 排序，中间线两侧宽为 $d$ 的带内按 $y$ 归并，每点只需检查常数个后续点，$O(n\log n)$。
- **三维几何**：混合积 $(a \times b) \cdot c$ 判断共面、四面体体积 $\frac{1}{6}|\text{混合积}|$、三维凸包（增量法，注意面片法向一致）。

---

## 第七部分：贪心、构造与其他策略

### 7.1 贪心证明三件套

1. **交换论证（Exchange Argument）**：证明任意最优解可以通过有限次交换变成贪心解且不变劣。经典：邻项交换（如“国王游戏”类题目中比较 $\frac{a_i}{b_i}$）。
2. **反证 + 极端原理**：假设贪心解不是最优，取出最优解的第一个分歧点，构造矛盾。
3. **归纳证明**：证明贪心的每一步都保持“存在一个以当前前缀开头的最优解”。

### 7.2 经典贪心模型

- **区间调度**：按右端点排序，能选就选（最多不相交区间）。
- **区间覆盖**：按左端点排序，每次扩展到能到达的最远右端点（跳跃游戏模型）。
- **Huffman 编码**：每次合并最小两个（priority_queue）。
- **排序不等式 / 排序论证**：交换两个元素分析变化量的正负。
- **反悔贪心**：用堆维护“可反悔”的选择。经典：后悔堆（`选或不选`、带反悔的延迟选择），如“夹在序列中的删除问题”。

### 7.3 构造题技巧

- 从小规模手玩找规律（$n = 1..8$ 打表）。
- 奇偶性 / 染色不变量（棋盘染色、二进制异或和）。
- 倍增构造 / 分治构造（如暴力递归构造满足下界的序列）。
- “补集思想”：构造的逆操作往往是“撤销”，证明等价于“任意局面可被撤销”。
- 图构造：建出隐式图证明解的存在性（如通过欧拉路径构造排列）。

### 7.4 分治与 CDQ

- **普通分治**：统计跨中点的贡献。
- **CDQ 分治**：解决“左半的修改对右半的询问的贡献”。一维按时间分治、一维排序、一维数据结构。经典：三维偏序（陌上花开）。
- **CDQ 套 CDQ**：四维偏序，$O(n \log^2 n)$（第三维再分治）。
- **cdq 分治优化 DP**：转移有“时间顺序 + 偏序关系”时，分治过程中保证 $j < i$ 且偏序，用树状数组维护。

### 7.5 整体二分

答案具有单调性且询问独立时，把所有询问一起二分：`solve(ql..qr, val_l..val_r)`，用数据结构处理 `mid` 的判定，把询问按与 `mid` 的大小关系分到左右两侧。复杂度 $O((n+q) \log V \log n)$。典型题：区间第 $k$ 小（带修主席树的替代方案）、K 远/近对。

### 7.6 莫队算法

离线区间询问，按 $\sqrt n$ 分块排序左右端点，指针移动均摊 $O(n\sqrt n)$。

排序方式：奇偶块优化（偶数块右端点从大到小，减少右指针回退）。回滚莫队（删除困难时用“只增加”的莫队 + 时间戳回退）。带修莫队（加一维时间戳，块大小 $n^{2/3}$，复杂度 $O(n^{5/3})$）。

树上莫队：欧拉序（每个点进出各一次，出现两次抵消），把树上路径转化为序列区间。

---

## 第八部分：代码细节与考试策略清单

### 8.1 常见 WA 原因

1. 数组开小（线段树要 `<< 2`，链式前向星边要 `<< 1` 且 $\times$ 可能有重边/无向）。
2. `int` 溢出：$10^5 \times 10^5 = 10^{10}$ 级别的乘法必须 `long long`。位运算优先级：`1 << 40` 是 UB，要 `1LL << 40`。
3. 多测不清空：`memset` 或重新 `init()`，特别注意 `tot`、`etot`、`clk` 等全局计数器。
4. 深搜爆栈：CSP/NOI 通常栈空间与内存同限，但递归 $10^6$ 层的链状树可能爆栈，必要时显式 BFS/转迭代。
5. 浮点精度：几何题比较用 `EPS`；`round` 的四舍五入在 `.5` 处的银行家舍入陷阱（C++ 的 `round` 是远离零方向，但 `(int)(x + 0.5)` 对负数错误）。
6. 输出格式：行末空格（多数评测忽略，但 NOIP 有些题目严格）、换行、文件名（`.in/.out`）。
7. 未初始化的局部变量、越界访问导致的未定义行为（本地能过评测挂）。
8. 哈希被卡：出题人造了反哈希数据。
9. 快读读入负数/越界数字出错（手写快读要处理 `-`）。
10. 取模后出现负数：`(a - b % MOD + MOD) % MOD`。

### 8.2 对拍模板

```cpp
// gen.cpp
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  unsigned seed = (unsigned)time(0);
  if (argc > 1)
    seed = (unsigned)atoi(argv[1]);
  mt19937 rng(seed);
  int n = rng() % 10 + 1;
  printf("%d\n", n);
  for (int i = 1; i <= n; ++i)
    printf("%d ", (int)(rng() % 100) - 50);
  printf("\n");
  return 0;
}
```

```bash
#!/bin/bash
# duipai.sh
g++ -O2 -std=c++14 -o sol sol.cpp
g++ -O2 -std=c++14 -o brute brute.cpp
g++ -O2 -std=c++14 -o gen gen.cpp
for i in $(seq 1 1000); do
  ./gen $i > data.in
  ./sol < data.in > sol.out
  ./brute < data.in > brute.out
  if ! diff -q sol.out brute.out > /dev/null; then
    echo "Wrong Answer on test $i"
    exit 1
  fi
done
echo "All passed"
```

### 8.3 时间复杂度与数据范围对照表

| 数据范围        | 期望复杂度              | 典型算法           |
| --------------- | ----------------------- | ------------------ |
| $n \le 10$      | $O(n!)$ 或 $O(2^n n^2)$ | 状压、搜索+剪枝    |
| $n \le 20$      | $O(2^n n)$              | 折半搜索、状压 DP  |
| $n \le 500$     | $O(n^3)$                | Floyd、区间 DP     |
| $n \le 5000$    | $O(n^2)$                | 朴素 DP            |
| $n \le 10^5$    | $O(n \sqrt n)$          | 莫队、分块         |
| $n \le 10^6$    | $O(n \log n)$           | 排序、线段树       |
| $n \le 10^7$    | $O(n)$                  | 双指针、线性筛     |
| $n \le 10^{18}$ | $O(\log n)$             | 快速幂、矩阵、数学 |

按 NOI 系列评测机性能，1 秒大约能承受 $10^8 \sim 5 \times 10^8$ 次简单运算（常数敏感），2 秒对应约 $10^9$。

### 8.4 考场策略

1. **通读全部题目**再决定开题顺序，性价比优先。
2. 部分分策略：$n \le 1000$ 的暴力、特殊性质（树退化为链/菊花、全 0、无修改）先写。
3. 对拍环境提前搭好（`sublime`/终端脚本），每道题至少拍 10 分钟。
4. 卡常三招：`#pragma GCC optimize(2)`（NOI 系列禁用 GCC 内建 pragma 吗——CSP/NOIP 通常允许，NOI 需查规则）、快读、循环展开/减少函数调用。**注意某些比赛禁用 pragma，保险起见写正常代码**。
5. 保留每个版本：`sol_v1.cpp`、`sol_v2.cpp`，防止改崩后无法回退。
6. 内存计算：`int` 数组 $10^7$ ≈ 40 MB；`long long` $10^7$ ≈ 80 MB；线段树节点 $4 \times 10^6 \times 2$ 个 `long long` ≈ 64 MB，开数组前先算。
7. 文件读写：`freopen("xxx.in", "r", stdin)`，**写完立刻检查文件名**，每年都有人挂在 `freopen` 上。

---

## 第九部分：经典问题与对应解法速查

（这部分把常见的“看到什么问题 → 用什么算法”列成速查）

1. 看到“区间第 $k$ 小，无修改” → 主席树 / 归并树 / 离线整体二分。
2. 看到“区间第 $k$ 小，带修改” → 带修主席树 / 整体二分。
3. 看到“区间本质不同的 XX 数” → 离线 + 上一位置 + 树状数组（HH 的项链模型）/ 后缀自动机 + LCT。
4. 看到“数轴上插入/删除线段，查询覆盖” → std::set / 珂朵莉。
5. 看到“树上路径点权 max / 第 k 大” → 树剖 + 线段树 / 树上启发式合并 / Kruskal 重构树。
6. 看到“询问两点间必经边/点” → 边双缩点 / 圆方树。
7. 看到“动态加边删边连通性” → 线段树分治 + 可撤销并查集 / LCT。
8. 看到“区间等差数列 max” → 不可直接做，考虑单调栈 + 线段树历史最值。
9. 看到“最长回文” → Manacher / 回文自动机 / 哈希+二分。
10. 看到“最小循环节” → KMP / 哈希。
11. 看到“多串匹配 / 敏感词” → AC 自动机。
12. 看到“子串计数 / 本质不同子串” → 后缀数组 height / 后缀自动机。
13. 看到“字符串 LCP 相关” → 后缀数组 + ST。
14. 看到“任意两个串的最长公共子串” → 广义 SAM。
15. 看到“图上走 $k$ 步的方案数” → 矩阵快速幂。
16. 看到“恰好 $k$ 条边的最短路” → 分层图 / 矩阵。
17. 看到“删边/删点后图连通性变化” → Tarjan / LCT / 离线倒序加边。
18. 看到“二分图博弈 / 棋盘覆盖” → 二分图匹配（König）。
19. 看到“选择若干不相交区间使收益最大” → 贪心 / DP / 费用流。
20. 看到“$n$ 个任务有收益与截止时间” → 反悔贪心（堆）。
21. 看到“区间 XOR 最大子段” → 线性基 + 前缀和 + ST。
22. 看到“异或和为 0 的子集存在性 / 第 k 小异或和” → 线性基。
23. 看到“线性递推第 $n$ 项，$n$ 巨大” → 矩阵快速幂 / BM 算法（请谨慎：BM 只在数据保证线性递推时使用）。
24. 看到“组合数取模，$p$ 巨大且不保证 $< p$” → Lucas / exLucas。
25. 看到“期望步数 / 期望次数” → 期望 DP / 高斯消元 / Min-Max 容斥。
26. 看到“放东西最小化最大值/最大化最小值” → 二分答案 + 贪心判定。
27. 看到“构造一个方案使得 XX” → 打表找规律 / 构造性证明。
28. 看到“交互题（询问子集大小/位置）” → 二进制分组（按位拆分询问次数 $\log$ 次）。
29. 看到“操作次数限制为 $\log$ 级别” → 二进制/倍增构造。
30. 看到“没有思路的部分分成 $\sqrt{}$ 段” → 分块 / 莫队。

---

## 第十部分：一点长期学习建议

- 每个模板**手写 3 遍**再进考场：第一遍抄、第二遍默写、第三遍变形（如把线段树改成动态开点）。
- 建立“错题本”：记录 WA 的原因而不是题目本身，考前只看原因清单。
- 计时训练：模拟真实考试时间分配，锻炼“何时弃题”的判断力。
- 代码中多写 `assert`（提交前删除或用 `#ifdef` 保护），能极大加快调试。
- 读题时把“数据范围”当题面的一部分：范围即提示。