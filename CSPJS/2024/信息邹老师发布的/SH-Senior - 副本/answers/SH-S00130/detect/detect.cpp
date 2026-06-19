#include <bits/stdc++.h>
using namespace std;
const int N = 200010; 
using i64 = long long;
template <class T> 
struct Mess {
	vector<int> v;
	inline void insert(int x) {
		v.push_back(x);
	}
	inline void init(void) {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}
	inline int query(int x) {
		return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
 	}
};
struct Edge {
	int to, w;
}; 
vector<Edge> G[N];
int u, in[N], dp[N];
i64 t, n, m, L, V, d[N], v[N], a[N], p[N];
inline void solve(void) {
	cin >> n >> m >> L >> V;
	for (int i = 1; i <= 2 * n; i++) {
		in[i] = dp[i] = 0, G[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		cin >> d[i] >> v[i] >> a[i];
	}
	for (int i = 1; i <= m; i++) cin >> p[i];
	auto overspeed = [&](int i, int pos) -> bool {
		const i64 s = p[pos] - d[i];
		return v[i] * v[i] + 2 * a[i] * s > V * V;
	};
	Mess<int> M; 
	int ans1 = 0;
	vector<pair<int, int>> req;
	for (int i = 1; i <= n; i++) {
		int pos0 = lower_bound(p + 1, p + 1 + m, d[i]) - p;
		if (pos0 > m) continue;
		if (a[i] >= 0) {
			// find the first overspeed point.
			int L = pos0, R = m, mid;
			while (L < R) {
				mid = (L + R) >> 1;
				if (overspeed(i, mid)) {
					R = mid;
				} else {
					L = mid + 1;
				}
			}
			if (overspeed(i, L)) {
				M.insert(L - 1), M.insert(m);
				req.push_back({L, m}), ++ans1;
			}
		} else {
			// find the last overspeed point.
			int L = pos0, R = m, mid;
			while (L < R) {
				mid = (L + R + 1) >> 1;
				if (overspeed(i, mid)) {
					L = mid;
				} else {
					R = mid - 1;
				}
			}
			if (overspeed(i, L)) {
				M.insert(pos0 - 1), M.insert(L);
				req.push_back({pos0, L}), ++ans1;
			}
		}
	}
	M.init();
	const int siz = M.v.size();
	sort(req.begin(), req.end());
	for (int i = 2; i <= siz; i++) {
		G[i - 1].push_back({i, 0}), ++in[i];
	}
	for (auto &p : req) {
		int l = M.query(p.first - 1);
		int r = M.query(p.second);
		G[l].push_back({r, 1}), ++in[r]; 
	}
	queue<int> Q;
	for (int i = 1; i <= siz; i++) {
		if (in[i] == 0) Q.push(i);
	}
	while (!Q.empty()) {
		u = Q.front(), Q.pop();
		for (auto &edge : G[u]) {
			dp[edge.to] = max(dp[edge.to], dp[u] + edge.w);
			if (--in[edge.to] == 0) Q.push(edge.to);
		}
	}
	cout << ans1 << ' ' << m - dp[siz] << '\n';
}
inline void optimizeIO(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
}
int main(int argc, const char *argv[]) {
#ifndef LOCAL
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
#endif
	optimizeIO(), cin >> t;
	while (t--) solve();
	return 0;
} 
/*
I love yjy forever.
God bless no fst.
*/
