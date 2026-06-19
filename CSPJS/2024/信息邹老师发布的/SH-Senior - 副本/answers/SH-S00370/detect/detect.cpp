#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, m, len, V, d[N], v[N], a[N], p[N], vi, si;
pair<int, int> vec[N], st[N];

inline bool cmp(pair<int, int>& x, pair<int, int>& y) {
	return x.first == y.first ? x.second > y.second : x.first < y.first;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n >> m >> len >> V;
		vi = si = 0;
		int cnt = 0, ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", d + i, v + i, a + i);
		for (int i = 1; i <= m; i++)
			scanf("%d", p + i);
		for (int i = 1; i <= n; i++) {
			int L = 0, R = -1;
			if (a[i] > 0) {
				R = m;
				if (v[i] > V)
					L = lower_bound(p + 1, p + m + 1, d[i]) - p;
				else {
					int d0 = (V * V - v[i] * v[i]) / (2 * a[i]) + d[i];
					L = lower_bound(p + 1, p + m + 1, d0) - p;
					if (p[L] == d0)
						L++;
				}
			}
			else if (v[i] > V) {
				L = lower_bound(p + 1, p + m + 1, d[i]) - p;
				if (a[i] < 0) {
					int d0 = ceil((double)(v[i] * v[i] - V * V) / (2 * -a[i]) + d[i]);
					R = lower_bound(p + 1, p + m + 1, d0) - p - 1;
				}
				else
					R = m;
			}
			if (L <= R) {
				cnt++;
				vec[++vi] = make_pair(L, R);
			}
		}
		sort(vec + 1, vec + vi + 1, cmp);
		for (int i = 1; i <= vi; i++) {
			while (si && st[si].second >= vec[i].second)
				si--;
			st[++si] = vec[i];
		}
		int r = 0;
		for (int i = 1; i <= si; i++) {
			if (st[i].first > r) {
				ans++;
				r = st[i].second;
			}
		}
		cout << cnt << ' ' << m - ans << "\n";
	}
	return 0;
}

