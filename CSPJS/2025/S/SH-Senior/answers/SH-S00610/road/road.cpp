#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define ROF(i, r, l) for (int i = (r); i >= (l); --i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define SZ(v) (int)((v).size())
#define allc(v) (v).begin(), (v).end()
#define popc(x) __builtin_popcount((x))
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
template <typename A, typename B>
void chkmax(A &x, B y) {
	x = (x > y) ? x : y;
}
template <typename A, typename B>
void chkmin(A &x, B y) {
	x = (x < y) ? x : y;
}
bool Meb;
namespace lyl {
	const int N = 1e6 + 5;
	const int M = 1e6 + 5;
	const ll inf = 1e18;
	struct edge {
		int u, v;
		ll w;
		bool operator < (const edge &t) const {
			return w < t.w;
		}
	} e1[M], e2[M], e3[N];
	int n, m, k, f[N], tot;
	ll ans, c[N], a[N];
	bool flag[N];
	int find(int x) {
		return f[x] == x ? x : f[x] = find(f[x]);
	}
	void merge(int x, int y) {
		f[find(x)] = find(y);
	}
	ll calc(int p) {
		ll res = 0;
		FOR (i, 1, n + k) f[i] = i;
		int c1 = 1, c2 = 1, cnt = n + popc(p);
		while (cnt > 1){
			if (c1 > m || (c2 <= tot && e2[c2].w < e3[c1].w)) {
				int u = e2[c2].u, v = e2[c2].v;
				ll w = e2[c2].w;
				++c2;
				if (!flag[u - n] || find(u) == find(v)) continue;
				res += w;
				merge(u, v);
				--cnt;
			} else {
				int u = e3[c1].u, v = e3[c1].v;
				ll w = e3[c1].w;
				++c1;
				if (find(u) == find(v)) continue;
				res += w;
				merge(u, v);
				--cnt;
			}
		}
		return res;
	}
	void solve() {
		ans = inf;
		cin >> n >> m >> k;
		FOR (i, 1, m) {
			cin >> e1[i].u >> e1[i].v >> e1[i].w;
		}
		sort(e1 + 1, e1 + m + 1);
		FOR (i, 1, n) f[i] = i;
		tot = 0;
		FOR (i, 1, m) {
			int u = e1[i].u, v = e1[i].v; ll w = e1[i].w;
			if (find(u) == find(v)) continue;
			merge(u, v);
			e3[++tot] = (edge){u, v, w};
		}
		m = tot;
		tot = 0;
		FOR (i, 1, k) {
			cin >> c[i];
			FOR (j, 1, n) {
				cin >> a[j];
				e2[++tot] = (edge){i + n, j, a[j]};
			}
		}
		sort(e2 + 1, e2 + tot + 1);
		FOR (p, 0, (1 << k) - 1) {
			ll sum = 0;
			FOR (i, 0, k - 1) {
				if ((p >> i) & 1) {
					flag[i + 1] = 1;
					sum += c[i + 1];
				} else {
					flag[i + 1] = 0;
				}
			}
			ll v = sum + calc(p);
			chkmin(ans, v);
		}
		cout << ans << '\n';
	}
};
bool Mbe;
int main() {
	 freopen("road.in", "r", stdin);
	 freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	lyl::solve();
//	 cerr << "Space: " << abs(&Meb - &Mbe) / 1024.0 / 1024.0 << "MB\n";
	// cerr << "Time: << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
 	return 0;
}
