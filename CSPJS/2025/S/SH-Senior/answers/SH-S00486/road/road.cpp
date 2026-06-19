#include <bits/stdc++.h>
#define For(i, a, b) for (int i = (a); i <= (b); i ++)
#define foR(i, a, b) for (int i = (a); i >= (b); i --)
using namespace std;
int n, m, k, cnt;
struct edge {int u, v, w;}a[2000005], b[2000005];
int c[10005], aa[11][10005], fa[10015];
bool cmp (edge e1, edge e2) {return e1.w < e2.w;}
int find (int x) {return (fa[x] == x ? fa[x] : fa[x] = find (fa[x]) );}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	For (i, 1, n + 10) fa[i] = i;
	For (i, 1, m) scanf ("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	For (i, 1, k) {
		scanf ("%d", &c[i]);
		For (j, 1, n) scanf ("%d", &aa[i][j]);
	}
	long long ans = 1000000000000000000LL;
	if ( (n <= 1000 && m <= 100000 && k <= 5) || (k == 0) ) {
		sort (a + 1, a + m + 1, cmp);
		int S = 1 << k;
		For (i, 0, S - 1) {
			long long res = 0;
			cnt = m;
			For (j, 0, k - 1) {
				if (i & (1 << j) ) {
					res += c[j + 1];
					For (k, 1, n)
						a[++ cnt] = {j + 1 + n, k, aa[j + 1][k]};
				}
			}
			sort (a + 1, a + cnt + 1, cmp);
			For (i, 1, n + 10) fa[i] = i;
			For (i, 1, cnt) {
				int fx = find (a[i].u), fy = find (a[i].v);
				if (fx != fy) {
					fa[fx] = fy;
					res += a[i].w;
				}
			}
			ans = min (ans, res);
		}
	} else {
		cnt = m;
		For (i, 1, k) {
			For (j, 1, n) {
				if (aa[i][j] == 0) {
					For (k, 1, n) {
						if (j == k) continue;
						a[++ cnt] = {j, k, aa[i][k]};
					}
					break;
				}
			}
		}
		sort (a + 1, a + cnt + 1, cmp);
		ans = 0;
		For (i, 1, n + 10) fa[i] = i;
		For (i, 1, cnt) {
			int fx = find (a[i].u), fy = find (a[i].v);
			if (fx != fy) {
				fa[fx] = fy;
				ans += a[i].w;
			}
		}
	}
	printf ("%lld\n", ans);
	return 0;
}
