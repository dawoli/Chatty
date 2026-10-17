// Problem URL: https://www.luogu.com.cn/problem/P5663 [CSP-J 2019] 加工零件
// Finish Time: 2026/10/7 14:19:40 AC
// Start Time: 2026/10/7 13:49:31

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 1e5 + 5;

int			n, m, q, od[MAXN], ev[MAXN];
vector<int> e[MAXN];

void add_edge(int u, int v)
{
	e[u].push_back(v);
	e[v].push_back(u);
}

void bfs()
{
	memset(od, 0x3f, sizeof(od));
	memset(ev, 0x3f, sizeof(ev));
	queue<pii> q;
	for (int i = 0; i < e[1].size(); i++)
	{
		od[e[1][i]] = 1;
		q.push({e[1][i], 1});
	}
	while (q.size())
	{
		int x = q.front().first, y = q.front().second;
		for (int i = 0; i < e[x].size(); i++)
		{
			if (y % 2 == 1)
			{
				if (y + 1 < ev[e[x][i]])
				{
					ev[e[x][i]] = y + 1;
					q.push({e[x][i], y + 1});
				}
			}
			else
			{
				if (y + 1 < od[e[x][i]])
				{
					od[e[x][i]] = y + 1;
					q.push({e[x][i], y + 1});
				}
			}
		}
		q.pop();
	}
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
	}
	bfs();
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		if (y % 2 == 0)
		{
			if (ev[x] > y)
				puts("No");
			else
				puts("Yes");
		}
		else
		{
			if (od[x] > y)
				puts("No");
			else
				puts("Yes");
		}
	}
	return 0;
}