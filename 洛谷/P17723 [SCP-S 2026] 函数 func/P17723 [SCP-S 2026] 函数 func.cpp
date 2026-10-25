// Problem URL: https://www.luogu.com.cn/problem/P17723 [SCP-S 2026] 函数 / func
// Finish Time: 2026/10/25 17:53:55 AC
// Start Time: 2026/10/25 16:57:11

#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
constexpr int			   MAXN = 2e6 + 6;

int n, a[MAXN], t[MAXN], pre[MAXN];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("func.in", "r", stdin);
	// freopen("func.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	ull ans = 0;
	for (int i = 0; i <= 31; i++)
	{
		int top = 0;
		ull cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (a[j] & (1LL << i))
			{
				cnt += (j - 1 - top) * 1ULL * (j - top) / 2;
				top = j;
			}
		}
		if (top == 0)
		{
			continue;
		}
		cnt += (n + 1 - top) * 1ULL * (n - top) / 2;
		ans += ((n + 1) * 1ULL * n / 2 - cnt) * 1ULL * (1LL << i);
	}
	queue<int> q;
	for (int i = 0; i <= 20; i++)
	{
		while (!q.empty())
		{
			pre[a[q.front()]] = 0;
			t[a[q.front()]]--;
			q.pop();
		}
		int top = 0;
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (a[j] & (1 << i))
			{
				while (!q.empty())
				{
					pre[a[q.front()]] = 0;
					t[a[q.front()]]--;
					q.pop();
				}
				cnt = 0;
				top = j;
				continue;
			}
			if (a[j] < (1 << i))
			{
				q.push(j);
				pre[a[j]] = j;
				if (t[a[j]] == 0)
				{
					cnt++;
				}
				t[a[j]]++;
			}
			while ((!q.empty()) && pre[a[q.front()]] > q.front())
			{
				t[a[q.front()]]--;
				q.pop();
			}
			if (cnt < (1 << i))
			{
				continue;
			}
			ans += (q.front() - top) * 1ULL * (1 << i);
		}
	}
	cout << ans << endl;
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：OR 与 MEX 的贡献会重叠，第二段只补"OR 该位为 0、MEX 该位为 1"；
 *   第一段算到 31 位，第二段只需到 20 位（要凑齐 0..2^b-1 需要 2^b <= n）。
 * - 关键结论/技巧：OR 按位用"全 0 段"求补集；MEX 第 b 位为 1 ⟺ 区间全第 b 位为 0 且包含 0..2^b-1 全部。
 * - 复杂度：O(n log A)
 */