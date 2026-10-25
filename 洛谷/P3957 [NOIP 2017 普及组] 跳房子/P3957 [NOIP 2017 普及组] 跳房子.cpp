// Problem URL: https://www.luogu.com.cn/problem/P3957 [NOIP 2017 普及组] 跳房子
// Finish Time: 2026/10/17 18:21:17 AC
// Finish Time: 2026/10/17 18:07:03 WA 50pts
// Start Time: 2026/10/17 17:33:48

#include <bits/stdc++.h>
#define int ll
#define endl '\n'
#define p first
#define v second
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 5e5 + 5;
constexpr int		   MAXR = 1e5 + 5;

int n, d, k, f[MAXN], q[MAXN], l = 0, r = MAXR;
pii a[MAXN];

bool check(int g)
{
	memset(f, -1, sizeof(f));
	deque<int> q;
	int		   x = max(d - g, (int)1), s = d + g, j = 0;
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		while (a[i].p - a[j].p >= x && j < i)
		{
			if (f[j] > INT_MIN)
			{
				while (!q.empty() && f[q.back()] <= f[j])
					q.pop_back();
				q.push_back(j);
			}
			j++;
		}
		while (!q.empty() && a[i].p - a[q.front()].p > s)
			q.pop_front();
		if (!q.empty())
			f[i] = f[q.front()] + a[i].v;
		else
			f[i] = INT_MIN;
		if (f[i] >= k)
			return true;
	}
	return false;
}

signed main()
{
	cin >> n >> d >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i].p >> a[i].v;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	if (l == MAXR)
		cout << -1;
	else
		cout << l;
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：跳跃下界是 max(1,d-g)；不可达状态别入队，用 INT_MIN 标记而不是初始值（分数可为负）；
 *   先加入新点再弹右边界过期的队首，顺序反了会漏点。
 * - 关键结论/技巧：二分 g，check 内用单调队列维护 f[j] 在距离窗口 [d-g,d+g] 上的最大值。
 * - 复杂度：O(n log x_n)
 */