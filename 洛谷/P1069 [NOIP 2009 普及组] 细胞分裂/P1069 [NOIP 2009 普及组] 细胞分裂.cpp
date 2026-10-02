// Problem URL: https://www.luogu.com.cn/problem/P1069
// Finish Time: 2026/10/2 22:26:33 AC
// Finish Time: 2026/10/2 21:54:36 WA/RE 40pts
// Finish Time: 2026/10/2 21:51:24 WA/RE 30pts
// Start Time: 2026/10/2 21:21:07

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 1e4 + 4;

int						n, m1, m2, s, ans = INT_MAX;
unordered_map<int, int> fm;
unordered_set<int>		ss;

unordered_map<int, int> factorize(int x)
{
	unordered_map<int, int> factors;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			while (x % i == 0)
			{
				x /= i;
				factors[i]++;
			}
		}
	}
	if (x > 1)
		factors[x]++;
	return factors;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m1 >> m2;
	fm = factorize(m1);
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		if (ss.find(s) != ss.end())
			continue;
		ss.insert(s);
		int x = 0;
		if (s % 2 != 0 && m1 % 2 == 0)
			continue;
		auto fs = factorize(s);
		for (auto f : fm)
		{
			auto it = fs.find(f.first);
			if (it == fs.end())
			{
				x = -1;
				break;
			}
			x = max(x, (int)ceil((double)f.second * m2 / (double)(*it).second));
		}
		if (x == -1)
			continue;
		// int l = ans;
		ans = min(ans, x);
		// if (ans != l || s == 4 || s == 16)
		// 	cout << "s: " << s << ", x: " << x << ", ans: " << ans << endl;
	}
	if (ans == INT_MAX)
		ans = -1;
	cout << ans << endl;
	return 0;
}

/*
经验总结：
- 从 1 个细胞开始，经过 x 秒后有 S^x 个细胞；实验能开始当且仅当 M1^M2 | S^x。
- 将 M1 和每个候选 S 分别质因数分解，并保留每个质因数的指数。
- 若 M1 含有质因数 p，而 S 不含 p，则该候选无解。
- 设 p 在 M1 和 S 中的指数分别为 a 和 b。整除要求 x*b >= M2*a，
	所以 p 对 x 的限制是 x >= ceil(M2*a/b)。对 M1 的所有质因数取最大值，
	得到该候选最早可开始实验的整数秒数；再对所有候选取最小值。
- 不能只比较 S^x 和 M1^M2 的数值大小，必须满足每个质因数的指数都足够。
- WA 版先找最小的 t 使 M1 | S^t，再令 q=S^t/M1，并根据 q 的数值估算额外时间，
	最后用 t+y-1 作为答案。这个商只表示整体数值之比，不能说明每个质因数还缺多少指数。
- 反例：M1=2、M2=3、S=4 时，WA 版得到 t=1、q=2、y=1，输出 1；但 2^3 不整除 4，
	最早要等 2 秒，因为 2^3 | 4^2。正确做法是比较质因数 2 的指数：2x >= 3。
- 复杂度：预处理 M1 为 O(sqrt(M1))；每个候选 S_i 的试除分解为 O(sqrt(S_i))。
*/