/*#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define int long long int
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, v[M];
struct thing { int t, w; } th[N];
bool cmp(thing x, thing y) { return x.t < y.t; }
int sumw[N];
int get_sumw(int x, int y) { return sumw[y] - sumw[x - 1]; }
int f[N][N]; // f[i][j]:  前i个行李都送出，且满足第j~i个物品是最后送出，所需钱的最小值
int minf[N];
int min(int x, int y, int i, int j) {
	if (x > y && y > 0) return printf("(%d,%d)=%d->(%d,%d)=%d\n", i - 1, j, f[i - 1][j], i, j, y), y;
	return printf("(%d,%d)=%d->(%d,%d)=%d\n", i, j + 1, f[i][j + 1], i, j, x), x;
}
main() {
	freopen("1.in", "r", stdin);
	//freopen("package.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
		cin >> th[i].t >> th[i].w;
	sort(th + 1, th + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		sumw[i] = sumw[i - 1] + th[i].w;
	for (int i = 1; i <= n; i++) {
		f[i][i] = minf[i - 1] + v[th[i].w];
		for (int j = i - 1; j >= 1; j--)
			f[i][j] = min(f[i - 1][j] + k * (th[i].t - th[i - 1].t) * get_sumw(j, i - 1) + v[get_sumw(j, i)] - v[get_sumw(j, i - 1)],
						 f[i][j + 1] + k * (th[i].t - th[j].t) * th[j].w + v[get_sumw(j, i)] - v[get_sumw(j + 1, i)], i, j);
		for (int j = 1; j <= i; j++)
			minf[i] = min(minf[i], f[i][j]);
	}
	int ans = 1e18;
	for (int j = 1; j <= n; j++)
		ans = min(ans, f[n][j]);
	cout << ans << '\n';
	return 0;
}*/
