#include<bits/stdc++.h>
using namespace std;
int n, m, k, dis[10015], pre[10015], c[10015], co[10015];
bool vis[10015];
long long ans;
struct node
{
	int v, w;
};
vector<node> mp[10015];
void f()
{
	while(1)
	{
		bool flag = false;
		int t = -1;
		for(int i = 1; i <= n+k; i++)
		{
			if(!vis[i] && (t == -1 || co[t] > co[i]))
				t = i;
		}
		if(t == -1)
			return;	
		vis[t] = true;
		for(int i = 0; i < mp[t].size(); i++)
		{
			node y = mp[t][i];
			if(!vis[y.v])
			{
				if(co[y.v] > (y.w + c[y.v]))
				{
					co[y.v] = y.w + c[y.v];
					dis[y.v] = dis[t] + co[y.v];
					pre[y.v] = t;
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("road4.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		mp[u].push_back({v, w});
		mp[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[n+i];
		for(int j = 1; j <= n; j++)
		{
			int w;
			cin >> w;
			mp[n+i].push_back({j, w});
			mp[j].push_back({n+i, w});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	memset(co, 0x3f, sizeof co);
	dis[1] = 0;
	dis[0] = 0;
	vis[1] = true;
	pre[1] = 0;
	for(int i = 0; i < mp[1].size(); i++)
	{
		node y = mp[1][i];
		if(!vis[y.v])
		{
			if(co[y.v] > y.w + c[y.v])
			{
				co[y.v] = y.w + c[y.v];
				dis[y.v] = dis[1] + co[y.v];
				pre[y.v] = 1;
			}
		}
	}
	f();
	for(int i = 1; i <= n; i++)
	{
		ans = ans + dis[i] - dis[pre[i]];
		if(pre[i] >= n+1 && vis[pre[i]])
		{
			ans += dis[pre[i]] - dis[pre[pre[i]]];
			vis[pre[i]] = false;
		}
	}
	cout << ans;
	return 0;
}
