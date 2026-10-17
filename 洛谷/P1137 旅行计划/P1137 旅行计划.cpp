// Problem URL: https://www.luogu.com.cn/problem/P1137 旅行计划
// Finish Time: 2026/10/6 12:05:41 AC
// Start Time: 2026/10/6 11:54:45

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 1e5 + 5;

int			n, m, in[MAXN], c[MAXN];
vector<int> e[MAXN];

void kahn()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0)
		{
			q.push(i);
			c[i] = 1;
		}
	while (!q.empty())
	{
		const auto u = q.front();
		q.pop();
		for (const auto &v : e[u])
		{
			in[v]--;
			if (in[v] == 0)
				q.push(v);
			c[v] = max(c[v], c[u] + 1);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		in[v]++;
	}
	// for (int i = 1; i <= n; i++)
	// 	cout << in[i] << " ";
	// cout << endl;
	// for (int i = 1; i <= n; i++)
	// 	cout << e[i].size() << " ";
	// cout << endl;
	kahn();
	for (int i = 1; i <= n; i++)
		cout << c[i] << endl;
	return 0;
}