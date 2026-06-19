#include <bits/stdc++.h>
using namespace std;
struct node
{
	int to, val;
};

vector<node> g[10010];
bool used[10010];
int c[20], a[20][10010], x[1000010];
int n, m, k;
long long ans = 0;

//int find(int x)
//{
//	if(x == fa[x])
//		return x;
//	return fa[x] = find(x);
//}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	
	for(int i = 1, u, v, w;i <= m;i ++)
	{
		cin >> u >> v >> w;
		x[i] = w;
		g[u].push_back((node){v, w});
		g[v].push_back((node){u, w});
	}
	for(int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j ++)
		{
			cin >> a[i][j];
		}
	}
	
//	for(int i = 1;i <= n;i ++)
//	{
//		for(int j = 0;j < g[i].size();j ++)
//		{
//			int fx = find(i), fy = find(g[u][i].to);
//			if(fx == fy)
//				continue;
//			fa[fx] = fy;
//			cnt += g[u][i].val;
//			d[u][i] = g[u][i].val;
//		}
//	}
	sort(x + 1, x + 1 + m);
	for(int i = 1;i <= n - 1;i ++)
		ans += x[i];
		
	cout << ans << endl;
	return 0;
}
