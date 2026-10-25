# 计数 DP + 双指针 P17729 [SCP-J 2026] 进位 carry

- 题目链接：https://www.luogu.com.cn/problem/P17729
- 算法：进位恒等式 + 双指针 + 前缀和优化 DP
- 复杂度：每组 $O(n)$，空间 $O(n)$

## 题意

$n$ 个数，$C(l,r)$ 表示从 $l$ 到 $r$ 依次做二进制加法时发生的进位总数（连续进位分别计数）。求满足

$$
p_1<p_2<\cdots<p_m,\qquad C(p_i,p_{i+1})=1
$$

的序列个数，对 $998244353$ 取模。

## 思路

**进位恒等式。** 多个数相加时，一次进位会使二进制中 1 的个数减少 1，因此

$$
C(l,r) = \sum_{i=l}^{r} \operatorname{popcount}(a_i) - \operatorname{popcount}\left(\sum_{i=l}^{r} a_i\right)
$$

用前缀和维护：`s1` 是数值前缀和，`s2` 是 popcount 前缀和，

```cpp
C(l, r) = s2[r] - s2[l - 1] - popcount(s1[r] - s1[l - 1])
```

**DP。** 设 `dp[i]` 为以 $i$ 结尾的合法序列数。单元素序列 `[i]` 贡献 1；若上一个元素是 $j$，则需要 $C(j,i)=1$，贡献 `dp[j-1]`：

$$
dp_i = 1 + \sum_{\substack{j<i \\ C(j,i)=1}} dp_{j-1}
$$

**双指针。** 固定右端点 $R$：

- $C(j,R)$ 关于 $j$ 单调不增（去掉元素，进位次数不会增加），所以满足 $C(j,R)=1$ 的 $j$ 是一段区间；
- $C(j,R)$ 关于 $R$ 单调不减，所以两个边界 $l,r$ 都只向右移动。

令 `l` 为最小的 $j$ 使 $C(j,R)\le 1$，`r` 为最小的 $j$ 使 $C(j,R)=0$，则

$$
C(j,R)=1 \iff j \in [l,\ r-1]
$$

用 `sdp` 维护 `dp` 前缀和：

```cpp
dp[R] = 1 + sdp[r - 1] - sdp[l - 1];
```

## 易错点

- 核心是进位恒等式。逐次模拟进位在 $n=2\times10^6$、$a<2^{30}$ 下不可行。
- 前缀和 `s1` 最大约 $2\times10^6 \times 2^{30}\approx 2\times10^{15}$，必须 `long long`。
- 多组数据：`dp`、`sdp`、`l,r` 都要重置（代码里用 `memset` + 重新赋值）。
- 双指针只在 $R$ 增大时右移，不能回退；边界含义是"进位 $\le 1$"和"进位 $=0$"，区间是 $[l,r-1]$，两处差一。
- 及时取模，`sdp[r-1]-sdp[l-1]` 可能为负，加 `MOD` 再 `%`。

## 关键结论

二进制加法的总进位次数满足 $\sum\operatorname{popcount}(a_i)-\operatorname{popcount}(\sum a_i)$。配合"满足条件的左端点构成连续区间 + 右端点单调"，把 $O(n^2)$ 的计数 DP 降到 $O(n)$。
