#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cassert>
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
using std::cin; using std::cout; using std::min; using std::max;
const int maxN = 100007;
const double EPS = 1e-8;
struct car {
	int d, v, a, l, r;
} c[maxN];
int p[maxN], maxl[maxN];
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		memset(maxl, 0, sizeof(maxl));
		int n, m, L, V;
		cin >> n >> m >> L >> V;
		rep(i, 1, n)
			cin >> c[i].d >> c[i].v >> c[i].a;
		rep(i, 1, m)
			cin >> p[i];
		int ans = 0;
		rep(i, 1, n) {
			int a = c[i].a, d = c[i].d, v = c[i].v, &l = c[i].l, &r = c[i].r;
			double posl = 1e7, posr = -1e3;
			if (a == 0) {
				if (v > V)
					posl = d - EPS, posr = L + EPS;
			}
			else if (a > 0) {
				if (v > V)
					posl = d - EPS, posr = L + EPS;
				else {
					double s = double(V*V - v*v) / 2 / a + d;
					if (s + EPS <= L)
						posl = s + EPS, posr = L + EPS;
				}
			}
			else {
				if (v > V) {
					posl = d - EPS;
					double s = double(V*V - v*v) / 2 / a + d;
					if (s + EPS < L)
						posr = s - EPS;
					else
						posr = L + EPS;
				}
			}
			l = std::lower_bound(p+1, p+m+1, int(ceil(posl))) - p;
			r = std::upper_bound(p+1, p+m+1, int(floor(posr))) - p - 1;
			if (l <= r) {
				ans++;
				maxl[r] = max(maxl[r], l);
//				printf("%d %d\n", l, r);
			}
//			printf("%.9f %.9f %d %d\n", posl, posr, l, r);
		}
		cout << ans << " ";
		int cur = 0, num = 0;
		rep(i, 1, m)
			if (maxl[i] > cur) {
				num++;
				cur = i;
			}
		cout << m - num << "\n";
	}
	return 0;
}
