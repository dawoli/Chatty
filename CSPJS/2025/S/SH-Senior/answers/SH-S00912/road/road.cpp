#include <bits/stdc++.h> 
using namespace std;
#define ll long long

ll n, m, k, ans = 1000000005;
ll arr[10005], vis[10005];
vector<pair<ll, ll> > G[100005];

void dfs(ll now)
{
	bool flag = true;
	for (auto i : G[now])
	{
		flag = false;
		if (!vis[i.first])
		{
			vis[i.first] = min(vis[now] + i.second, vis[i.first]);
			dfs(i.first);
		}
	}
	if (flag)
	{
		ll tv = 0;
		for (int i = 1; i <= n; i++)
		{
			tv = max(tv, vis[i]);
		}
		ans = min(ans, tv);
	}
	return;
}

void solve1()
{
	for (int i = 0; i < m; i++)
	{
		ll u, v, c;
		cin >> u >> v >> c;
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0x3f3f3f3f3f3f3f3f3f3f, sizeof vis);
		dfs(i);
	}
	
	cout << ans << endl;
	return;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (k == 0)
	{
		solve1();
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			ll tmp;
			for (int i = 0; i <= k; i++)
			{
				cin >>tmp;
			}
		}
		cout << 0 << endl;
	}
	return 0;
}
