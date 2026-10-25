// Problem URL: https://www.luogu.com.cn/problem/P9751 [CSP-J 2023] 旅游巴士
// Finish Time: 2026/10/18 16:01:51 AC
// Start Time: 2026/10/18 15:23:00

#include <bits/stdc++.h>
#define int ll
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 10010;
constexpr int		   MAXM = 105;

int			n, m, k;
int			dis[MAXN][MAXM];
bool		f[MAXN][MAXM];
vector<pii> e[MAXN];

priority_queue<pii, vector<pii>, greater<pii>> q;

void add(int u, int v, int w)
{
	e[u].push_back({v, w});
}
void dijkstra(int s)
{
	dis[s][0] = 0;
	q.push({0, s});
	while (!q.empty())
	{
		int u = q.top().second, p = q.top().first;
		q.pop();
		if (f[u][p % k])
			continue;
		f[u][p % k] = 1;
		for (auto d : e[u])
		{
			int v = d.first, w = d.second, t = (p + 1) % k;
			if (p >= w)
				t = p;
			else
				t = ((w - p + k - 1) / k) * k + p;
			if (dis[v][(t + 1) % k] > t + 1)
			{
				dis[v][(t + 1) % k] = t + 1;
				q.push({t + 1, v});
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dis, 0x3f, sizeof(dis));
	cin >> n >> m >> k;
	for (int u, v, w, i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		add(u, v, w);
	}
	dijkstra(1);
	if (!f[n][0])
		cout << -1 << endl;
	else
		cout << dis[n][0] << endl;
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：等待不是直接等到 w，而是等到 ≥w 且与当前时刻同余的最小时刻 ceil((w-p)/k)*k；
 *   状态是 (点, 时刻 mod k)，不能只按 n 开数组。
 * - 关键结论/技巧：把"到达时刻是 k 的倍数"变成余数状态，跑分层 Dijkstra，答案 dis[n][0]。
 * - 复杂度：O(mk log(nk))
 */