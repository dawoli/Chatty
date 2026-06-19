#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 20005, M = 2e6 + 5;
int n, m, k, x, y, o, p1, p2, tmp, u[M], v[M], w[M], cnt, c2, c[N], f[N], a[15][N];
bool fl[N];
LL t, ans = 1e18;
int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
struct node
{
	int u, v, w, x;
} nd[M];
bool cmp(node x, node y)
{
	return x.w < y.w;
}
void ca()
{
//	for (int i = 1; i <= k; i++)
//		cout << fl[i];
//	cout << endl;
	t = c2 = 0;
	for (int i = 1; i <= k; i++)
	{
		if (y & (1 << (i - 1)))
		{
			t += c[i];
		}
	}
	for (int i = 1; i <= n + k; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= cnt && c2 != n + o - 1; i++)
	{
//		cout << nd[i].u << " " << nd[i].v << " " << nd[i].w << " " << nd[i].x << endl;
		if (nd[i].x && !(y & (1 << (nd[i].x - 1))))
		{
			continue;
		}
		if (find(nd[i].u) != find(nd[i].v))
		{
//			cout << nd[i].u << " " << nd[i].v << " " << nd[i].w << endl;
			c2++;
			f[find(nd[i].u)] = find(nd[i].v);
			t += nd[i].w;
		}
	}
	ans = min(ans, t);
}
//void dfs(int i, int j)
//{
//	if (i == k + 1)
//	{
//		ca(l);
//		return;
//	}
//	dfs(k + 1, l);
//	fl[k] = true;
//	dfs(k + 1, l + 1);
//}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		nd[++cnt].u = u[i], nd[cnt].v = v[i], nd[cnt].w = w[i];
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			nd[++cnt].u = n + i;
			nd[cnt].v = j;
			nd[cnt].w = a[i][j];
			nd[cnt].x = i;
		}
	}
	sort(nd + 1, nd + cnt + 1, cmp);
//	y = 1;
//	o = 1;
//	ca();
	for (; y < (1 << k); y++)
	{
		x = y, o = 0;
		while (x)
		{
			o += (x & 1);
			x /= 2;
		}
		ca();
	}
	cout << ans;
}
