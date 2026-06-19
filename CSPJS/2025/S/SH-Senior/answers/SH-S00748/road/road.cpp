#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, k, u, v, w, c, a;
long long cur, cnt, ans, f[5000001];
struct node
{
	long long a, b, l;
}x[5000001];
void init()
{
	for (int i = 1; i <= n; i++)
		f[i] = i;
}
bool cmp(node a, node b)
{
	return a.l < b.l;
}
int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
} 
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		x[++cur] = {u, v, w};
		x[++cur] = {v, u, w};
	}
	for (int i = 1; i <= k; i++) 
	{
		cin >> c; 
		for (int j = 1; j <= n; j++)
		{
			cin >> a;
			x[++cur] = {i + n, j, a};
			x[++cur] = {j, i + n, a};
		}
	}
	init();
	sort(x + 1, x + cur + 1, cmp);
	for (int i = 1; i <= cur; i++)
	{
		int xu = x[i].a, xv = x[i].b;
		if (f[xu] != f[xv])
		{
			++cnt;
			ans += x[i].l;
			f[xv] = find(xu);
		}
		if (cnt == n - 1) break;
	}
	cout << ans;
	return 0;
}
