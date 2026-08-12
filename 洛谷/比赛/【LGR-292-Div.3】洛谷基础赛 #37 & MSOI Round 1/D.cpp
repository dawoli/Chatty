// Problem URL: https://www.luogu.com.cn/contest/325521
// Finish Time: 2026/8/1 16:28:09 WA 40pts
// Finish Time: 2026/8/1 14:30:22 WA
// Start Time: 2026/8/1 14:03:27

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	set<pair<int, int>>		 und_edges;
	map<pair<int, int>, int> min_w;
	vector<vector<int>>		 adj(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (u == v)
			continue;
		und_edges.insert({min(u, v), max(u, v)});
		auto it = min_w.find({u, v});
		if (it == min_w.end() || w < it->second)
		{
			min_w[{u, v}] = w;
		}
		adj[u].push_back(v);
	}
	if (N == 1)
	{
		cout << -1 << '\n';
		return 0;
	}
	bool is_chain = true;
	if ((int)und_edges.size() != N - 1)
	{
		is_chain = false;
	}
	else
	{
		vector<int> deg(N + 1, 0);
		for (auto &e : und_edges)
		{
			deg[e.first]++;
			deg[e.second]++;
		}
		for (int i = 1; i <= N; ++i)
		{
			if (deg[i] > 2)
			{
				is_chain = false;
				break;
			}
		}
		if (is_chain)
		{
			vector<vector<int>> und_adj(N + 1);
			for (auto &e : und_edges)
			{
				int u = e.first, v = e.second;
				und_adj[u].push_back(v);
				und_adj[v].push_back(u);
			}
			vector<bool> vis(N + 1, false);
			queue<int>	 q;
			q.push(1);
			vis[1]		= true;
			int vis_cnt = 1;
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				for (int v : und_adj[u])
				{
					if (!vis[v])
					{
						vis[v] = true;
						q.push(v);
						++vis_cnt;
					}
				}
			}
			if (vis_cnt != N)
				is_chain = false;
		}
	}
	if (is_chain)
	{
		vector<vector<int>> und_adj(N + 1);
		for (auto &e : und_edges)
		{
			int u = e.first, v = e.second;
			und_adj[u].push_back(v);
			und_adj[v].push_back(u);
		}
		vector<int> parent(N + 1, 0);
		queue<int>	q;
		q.push(1);
		parent[1] = -1;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			if (u == N)
				break;
			for (int v : und_adj[u])
			{
				if (parent[v] == 0)
				{
					parent[v] = u;
					q.push(v);
				}
			}
		}

		if (parent[N] == 0)
		{
			cout << -1 << '\n';
			return 0;
		}
		vector<int> path;
		for (int cur = N; cur != -1; cur = parent[cur])
		{
			path.push_back(cur);
		}
		reverse(path.begin(), path.end());
		int		  L	  = path.size();
		long long sum = 0;
		bool	  ok  = true;
		for (int i = 0; i < L - 1; ++i)
		{
			int	 u = path[i], v = path[i + 1];
			auto it = min_w.find({u, v});
			if (it != min_w.end())
			{
				sum += it->second;
			}
			else
			{
				ok = false;
				break;
			}
		}
		if (ok && L <= N / 2)
		{
			cout << sum << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
		return 0;
	}
	vector<int> dist(N + 1, -1);
	queue<int>	q;
	dist[1] = 0;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (u == N)
			break;
		for (int v : adj[u])
		{
			if (dist[v] == -1)
			{
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	if (dist[N] == -1)
	{
		cout << -1 << '\n';
	}
	else
	{
		int L = dist[N] + 1;
		if (L <= N / 2)
		{
			cout << dist[N] << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}

	return 0;
}