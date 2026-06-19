#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define PII pair<int, int>
#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define ROF(i, r, l) for (int i = (r); i >= (l); --)
#define allc(x) (x).begin(), (x).end()
#define SZ size()
#define FI first
#define SE second
#define PB push_back
using namespace std;
const int N = 1e5 + 5;
int T, n, m, L, V, d[N], a[N], v[N], p[N];
vector<PII> seg, nseg;
bool check(int v0, int a, int s) {
	return v0 * v0 + 2 * a * s > V * V;
}
bool cmp(PII x, PII y) {
	return x.SE < y.SE;
}
signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m >> L >> V;
		int ans = 0, ans2 = 0;
		seg.clear();
		FOR (i, 1, n) {
			cin >> d[i] >> v[i] >> a[i];
			if (a[i] == 0) {
				if (v[i] > V) {
					seg.PB(MP(d[i], L));
				}
				continue;
			}
			if (a[i] < 0) {
				if (v[i] <= V) {
					continue;
				}
				int l = d[i], r = L, mid, res = d[i];
				while (l <= r) {
					mid = l + r >> 1;
					if (check(v[i], a[i], mid - d[i])) {
						res = mid;
						l = mid + 1;
					} else {
						r = mid - 1;
					}
				}
				seg.PB(MP(d[i], res));
			} else {
				if (v[i] > V) {
					seg.PB(MP(d[i], L));
					continue;
				}
				if (!check(v[i], a[i], L - d[i])) {
					continue;
				}
				int l = d[i], r = L, mid, res = L;
				while (l <= r) {
					mid = l + r >> 1;
					if (check(v[i], a[i], mid - d[i])) {
						res = mid;
						r = mid - 1;
					} else {
						l = mid + 1;
					}
				}
				seg.PB(MP(res, L));
			}
		}
		FOR (i, 1, m) {
			cin >> p[i];
		}
		nseg.clear();
		FOR (i, 0, (int)seg.SZ - 1) {
			seg[i].FI = lower_bound(p + 1, p + m + 1, seg[i].FI) - p;
			seg[i].SE = upper_bound(p + 1, p + m + 1, seg[i].SE) - p - 1;
			if (seg[i].FI > seg[i].SE || seg[i].SE > m) {
				continue;
			}
			nseg.PB(seg[i]);
			++ans;
		}
		sort(allc(nseg), cmp);
		if (!ans) {
			cout << ans << ' ' << m << '\n';
			continue;
		}
		int ls = nseg[0].SE;
		++ans2;
		FOR (i, 1, (int)nseg.SZ - 1) {
			if (nseg[i].FI > ls) {
				++ans2;
				ls = nseg[i].SE;
			}
		}
		cout << ans << ' ' << m - ans2 << '\n';
	}
	return 0;
}
