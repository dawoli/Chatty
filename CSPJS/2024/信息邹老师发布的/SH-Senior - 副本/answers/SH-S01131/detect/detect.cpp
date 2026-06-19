#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5, inf = -1e10;
int T, n, m, L, V, p[maxn];
vector <int> dt[maxn];
struct car {
	double l, r, d, v, a;
	bool f1, f2, F;
	int amt;
	void scan() {
		amt = 0;
		f1 = f2 = F = 0;
		cin >> d >> v >> a;
		if (a <= 0 && v <= V) {
			l = r = inf;
			f1 = f2 = 0;
		}
		else if (a >= 0 && v > V) {
			l = d;
			r = L;
			f1 = f2 = 1;
		}
		else if (a < 0 && v > V) {
			l = d;
			r = (V*V - v*v) / (a + a) + d;
			f1 = 1, f2 = 0;
		}
		else {
			r = L;
			l = (V*V - v*v) / (a + a) + d;
			f1 = 0, f2 = 1;
		}
	}
}c[maxn];
bool check(int x) {
	for (auto v : dt[x]) {
		if ((c[v].amt-1) <= 0) return false;
	}
	return true;
}
void solve() {
	int ans = 0, sum = 0;
	cin >> n >> m >> L >> V;
	for (int i=1; i<=m; i++) dt[i].clear();
	for (int i=1; i<=n; i++) c[i].scan();
	for (int i=1; i<=m; i++) cin >> p[i];
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (c[i].f1 == 0) {
				if (c[i].l < p[j]) {
					if (c[i].f2 == 0) {
						if (p[j] < c[i].r) {
							if (c[i].F == 0) sum ++;
							dt[j].push_back(i);
							c[i].amt ++;
							c[i].F = 1;
						}
					}
					else {
						if (p[j] <= c[i].r) {
							if (c[i].F == 0) sum ++;
							dt[j].push_back(i);
							c[i].amt ++;
							c[i].F = 1;
						}
					}
				}
			}
			else if (c[i].f1 == 1) {
				if (c[i].l <= p[j]) {
					if (c[i].f2 == 0) {
						if (p[j] < c[i].r) {
							if (c[i].F == 0) sum ++;
							dt[j].push_back(i);
							c[i].amt ++;
							c[i].F = 1;
						}
					}
					else {
						if (p[j] <= c[i].r) {
							if (c[i].F == 0) sum ++;
							dt[j].push_back(i);
							c[i].amt ++;
							c[i].F = 1;
						}
					}
				}
			}
		}
	}
	for (int i=1; i<=m; i++) {
		if (dt[i].size() == 0) {
			ans ++;
			continue ;
		}
		if (check(i)) {
			ans ++;
			for (auto v : dt[i]) c[v].amt --;
		}
	}
	cout << sum << " " << ans << endl;
	return ;
}
signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while (T --) {
		solve();
	}
	return 0;
}
