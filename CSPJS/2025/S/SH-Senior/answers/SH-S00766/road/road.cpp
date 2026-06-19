// 80pts“‘œ¬ 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n, m, k;
struct edge
{
	int u, v, w;
	bool operator<(edge other)
	{
		return w < other.w;
	}
} a[1040005];
int fa[10005];
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
	fa[find(x)] = find(y);
}
int Aans = 1e18;
bool used[15];
int kksk()
{
//	for (int i = 1; i <= m; i++) cout << b[i].u << " " << b[i].v << " " << b[i].w << "\n";
	int ans = 0;
 	for (int i = 1; i <= n + k; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		if (a[i].u > n && !used[a[i].u - n] || a[i].v > n && !used[a[i].v - n]) continue;
		if (find(a[i].u) != find(a[i].v))
		{
			unite(a[i].u, a[i].v);
			ans += a[i].w;
		}
	}
//	cout << ans;
	return ans;
}
int e[15][10005], c[15];
int firstn;
void dfs(int step, int nowp)
{
	if (step == k + 1)
	{
		Aans = min(Aans, kksk() + nowp);
//		cout << "\n";
		return ;
	}
	dfs(step + 1, nowp);
	used[step] = 1;
	dfs(step + 1, nowp + c[step]);
	used[step] = 0;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	firstn = n;
//	cout << firstn << " ";
	for (int i = 1; i <= m; i++) 
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> e[i][j]; 
			a[++m] = {n + i, j, e[i][j]};
		}
	}
	sort(a + 1, a + m + 1);
//	for (int i = 1; i <= m; i++) cout << a[i].u << " " << a[i].v << " " << a[i].w << "\n";
	dfs(1, 0);
	cout << Aans;
 } 
