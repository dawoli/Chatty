#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, c[15], a[15][10005], fa[10005], flag, ans;
struct T{
	int x, y, w;
	bool operator< (T o) {return w < o.w;}
} e[2000005];
int f(int x)
{
	return fa[x] == x ? x : (fa[x] = f(fa[x]));
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> e[i].x >> e[i].y >> e[i].w;
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if (c[i]) flag = 1;
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	if (!flag) for (int i = 1; i <= k; i++)
	{
		int p = 0;
		for (int j = 1; j <= n; j++) if (!a[i][j]) {p = j; break;}
		for (int j = 1; j <= n; j++) if (j != p) e[++m] = {p, j, a[i][j]};
	}
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		if (f(e[i].x) == f(e[i].y)) continue;
		fa[f(e[i].y)] = f(e[i].x), ans += e[i].w;
	}
	cout << ans;
	return 0;
}
