#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e4 + 5,M = 1e6 + 5,K = 15;
int c[K][N],f[N],vis2[K],cnt;
long long sum;
struct node{
	int x,y,w,f;
};
vector<node> g;
int find(int fa)
{
	if(f[fa] == fa)
		return fa;
	else
		return f[fa] = find(f[fa]);
}
bool cmp(node x,node y)
{
	return x.w + c[x.f][0] < y.w + c[y.f][0];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		f[i] = i;
	}
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		g.push_back({u,v,w,0});
	}
	int ans = 0;
	bool v = 0;
	for(int i = 1;i <= k;i++)
	{
		bool x = 1;
		cin >> c[i][0];
		if(c[i][0] != 0)
			x = 0;
		for(int j = 1;j <= n;j++)
		{
			cin >> c[i][j];
			if(c[i][j] != 0)
				x = 0;
		}
		if(x)
			v = 1,ans = 0;
	}
	if(v)
	{
		cout << ans << "\n";
		return 0;
	}
	for(int i = 1;i <= k;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			for(int h = j + 1;h <= n;h++)
			{
				g.push_back({j,h,c[i][j] + c[i][h],i});
			}
		}
	}
	sort(g.begin(),g.end(),cmp);
	for(int i = 0;i < g.size();i++)
	{
		int u = g[i].x,v = g[i].y;
		if(find(u) != find(v))
		{
			sum += g[i].w;
			if(!vis2[g[i].f])
				sum += c[g[i].f][0],vis2[g[i].f] = 1;
				f[f[u]] = f[v];
		}
	}
	cout << sum;
	return 0;
}
