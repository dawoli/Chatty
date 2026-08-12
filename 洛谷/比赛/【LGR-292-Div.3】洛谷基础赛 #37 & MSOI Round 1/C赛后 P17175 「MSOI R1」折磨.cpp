// Problem URL: https://www.luogu.com.cn/problem/P17175
// Finish Time: 2026/8/3 17:34:04 AC
// Finish Time: 2026/8/3 17:27:18 WA 65pts
// Start Time: 2026/8/3 16:57:20

#include <bits/stdc++.h>
#define endl '\n'
#define val first
#define id second
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 2e5 + 5;

int			 n, f, m, c, a[MAXN], ans = 0;
bitset<MAXN> vis, full;
vector<int>	 e[MAXN];
vector<pii>	 w;
queue<pii>	 q;

void bfs()
{
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		int u	= p.id;
		int val = p.val;
		vis[u]	= true;
		for (auto v : e[u])
		{
			if (!vis[v] && val >= a[v])
			{
				q.push({val, v});
				vis[v] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> f >> m >> c;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= f; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= m; i++)
	{
		int u;
		cin >> u;
		w.push_back({a[u], u});
	}
	sort(w.begin(), w.end(), greater<pii>());
	for (int i = 1; i <= n; i++)
		full[i] = true;
	vis[c] = true;

	auto it = w.begin();
	while (vis != full && it != w.end())
	{
		do
		{
			q.push(*it);
			it++;
		} while (it != w.end() && (it - 1)->val == it->val);
		bfs();
	}
	for (auto p : e[c])
	{
		if (vis[p])
			ans++;
	}
	cout << ans;
	return 0;
}