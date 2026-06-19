#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
using namespace std;
namespace IANYEYZ {
	int n, m, k;
	struct edge {
		int u, v, w;
		bool operator<(edge o) {
			return w < o.w;
		}
	}e[1000010];
	struct city {
		int c; vector<int> v;
		void read() {
			cin >> c; v.resize(n + 1);
			rep (i, 1, n) {
				cin >> v[i];
			}
		}
	}c[1000010];
	int f[10010];
	int find(int x) {
		return x == f[x] ? x : f[x] = find(f[x]);
	}
	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		f[fx] = fy;
	}
	void solve() {
		cin >> n >> m >> k;
		rep (i, 1, m) {
			cin >> e[i].u >> e[i].v >> e[i].w;
		}
		rep (i, 1, k) {
			c[i].read();
		}
		if (k == 0) {
			rep (i, 1, n) f[i] = i;
			sort(e + 1, e + m + 1); int ans = 0;
			rep (i, 1, m) {
				int fu = find(e[i].u), fv = find(e[i].v);
				if (fu != fv) {
					ans += e[i].w;
					f[fu] = fv;
				}
			}
			cout << ans << "\n";
		}
	}
}
int main() {
	cin.tie(0) -> ios :: sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	IANYEYZ::solve();
}
