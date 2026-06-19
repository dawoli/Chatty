#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int int
#define ll long long
#define ull unsigned long long
#define ld long double
#define FOR(i, n, m) for(int i = (n); i <= (m); i ++)
#define ROF(i, n, m) for(int i = (n); i >= (m); i --)
#define REP(i, n) for(int i = 0; i < (n); i ++)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define FI(v) v.first
#define SE(v) v.second
#define SZ(v) int(v.size())
#define BG(v) v.begin()
#define ED(v) v.end()
#define ALL(v) BG(v), ED(v)
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define SHOW(x) #x << " = " << x << " "
template < typename A , typename B >
inline bool chmax(A & x, B y) { return (x < y ? (x = y, true) : false); }
template < typename A , typename B >
inline bool chmin(A & x, B y) { return (x > y ? (x = y, true) : false); }
const int N = 1e4 + 15;
const int M = 12;
const int INF = 1e9 + 7;
const ll LNF = 1e18;
int n, m, k;
int c[M], a[M][N], id[M][N];
int f[N], h[M];
int find(int u) {
	if(f[u] == u) return u;
	return f[u] = find(f[u]);
}
struct Edge {
	int u, v, w;
	bool operator < (const Edge & A) const {
		return w < A.w;
	}
} F[N]; int tot;
vector<Edge> e; 
inline int get(int u) {
	return a[u][id[u][h[u]]];
}
void solve() {
	cin >> n >> m >> k;
	REP(_, m) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	FOR(u, 1, n) f[u] = u;
	sort(ALL(e)); int cnt = n;
	ll ans = 0;
	for(auto h : e) {
		int u = find(h.u), v = find(h.v);
		if(u == v) continue;
		cnt --;
		F[++ tot] = h;
		f[v] = u;
		ans += h.w;
		if(cnt == 1) break;
	}
	F[++ tot] = {0, 0, INF};
	REP(i, k) {
		cin >> c[i];
		FOR(u, 1, n) cin >> a[i][u];
		FOR(u, 1, n) id[i][u] = u;
		sort(id[i] + 1, id[i] + n + 1, [&] (int x, int y) {
			return a[i][x] < a[i][y];
		});
		a[i][0] = INF;
	}
	REP(S, 1 << k) if(S) {
		ll res = 0;
		REP(i, k) if(S >> i & 1) res += c[i];
		FOR(u, 1, n + k) f[u] = u;
		FOR(i, 0, k) h[i] = 1;
		REP(i, k) if(! (S >> i & 1)) h[i] = n + 1;
		int cnt = n + __builtin_popcount(S);
		while(cnt > 1) {
			int pos = 0;
			REP(i, k) if(get(i) < get(pos)) pos = i;
			if(get(pos) < F[h[k]].w) {
				int u = find(n + pos + 1), v = find(id[pos][h[pos]]);
				int w = get(pos); h[pos] ++;
				if(u == v) continue;
				cnt --;
				f[v] = u;
				res += w;
			}
			else {
				auto H = F[h[k]]; h[k] ++;
				int u = find(H.u), v = find(H.v), w = H.w;
				if(u == v) continue;
				f[v] = u;
				cnt --;
				res += w;
			}
		}
		chmin(ans, res);
	}
	cout << ans << endl;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}