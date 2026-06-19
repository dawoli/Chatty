#include <bits/stdc++.h>
#define int unsigned long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1005;
const int M = 1000005;
const int INF = LONG_LONG_MAX / 2;
int n, m, k, we[M], c[11], a[11][11], dis[N][N];
struct edge{
	int u, v, w;
	friend bool operator < (edge x, edge y) {
		return x.w < y.w;
	}
} e[M], e1[M];
int fa[N], fa1[N];
int getfa(int x) {
	if(x != fa[x]) return fa[x] = getfa(fa[x]);
	return x;
}
void merge(int x, int y) {
	int xx = getfa(x), yy = getfa(y);
	if(xx != yy) fa[yy] = xx;
}
int getfa1(int x) {
	if(x != fa1[x]) return fa1[x] = getfa1(fa1[x]);
	return x;
}
void merge1(int x, int y) {
	int xx = getfa1(x), yy = getfa1(y);
	if(xx != yy) fa1[yy] = xx;
}
edge newedge(int u, int v, int w) {
	edge tmp;
	tmp.u = u, tmp.v = v, tmp.w = w;
	return tmp;
}
int calc(int x) {
	if(x == 0) return 1;
	int t = 0;
	while(x) {
		x /= 2;
		++ t;
	}
	return t;
}
int ecnt;
bool fla = 1;
void solve() {
	cin >> n >> m >> k;
	rep(i, 1, n) rep(j, 1, n) dis[i][j] = INF;
	rep(i, 1, n) dis[i][i] = 0;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
		e[++ ecnt] = newedge(u, v, w); 
	}
	rep(i, 1, k) {
		cin >> c[i];
		if(c[i] != 0) fla = 0;
		rep(j, 1, n) {
			cin >> a[i][j];
		}
	}
	if(k == 0) {
		int cnt = 0, ans = 0;
		sort(e + 1, e + 1 + m);
		rep(i, 1, n) fa[i] = i;
		rep(i, 1, ecnt) {
			int xx = getfa(e[i].u), yy = getfa(e[i].v);
			if(xx == yy) continue;
			merge(xx, yy);
			++ cnt; ans += e[i].w;
			if(cnt == n - 1) break;
		}
		cout << ans;
	} else {
		if(fla) {
			int cnt = 0, ans = 0;
			rep(i, 1, k) 
				rep(j, 1, n) 
					if(a[i][j] == 0) 
						rep(k, 1, n) e[++ ecnt] = newedge(j, k, a[i][k]);
			sort(e + 1, e + 1 + ecnt);
			rep(i, 1, n) fa[i] = i;
			rep(i, 1, ecnt) {
				int xx = getfa(e[i].u), yy = getfa(e[i].v);
				if(xx == yy) continue;
				merge(xx, yy);
				++ cnt; ans += e[i].w;
				if(cnt == n - 1) break;
			}
			cout << ans;
		} else {
//			cout << "orz";
			int t = calc(k);
			int ans = INF;
			rep(i, 0, pow(2, k) - 1) {
				int cnt = 0, ans1 = 0;
				rep(_, 1, ecnt) e1[_] = e[_];
				int e1cnt = ecnt;
				rep(j, 1, n) fa1[j] = j;
				if(i != 0) {
					rep(j, 1, t) {
						if(t == j) {
							if(i & 1) {
								rep(s, 1, n) e1[++ e1cnt] = newedge(j, s, a[j][s]);
								ans1 += c[j];
							}
						} else {
							if((i >> (t - j)) & 1) {
								rep(s, 1, n) e1[++ e1cnt] = newedge(j, s, a[j][s]);
								ans1 += c[j];
							}	
						}
					}	
				}
//				cout << i << ' ' << ans1 << '\n';
				sort(e1 + 1, e1 + 1 + e1cnt);
				if(i == 2) {
					rep(jj, 1, e1cnt) {
//						cout << jj << ':' << e1[jj].u << ' ' << e1[jj].v << ' ' << e1[jj].w << ' ' << '\n';
					}
				}
				rep(s, 1, e1cnt) {
					if(e1[s].u == e1[s].v) continue;
					int xx = getfa1(e1[s].u), yy = getfa1(e1[s].v);
					if(xx == yy) continue;
					merge1(xx, yy);
					++ cnt; ans1 += e1[s].w;
//					if(i == 2) cout << s << ':' << e1[s].w << '\n';
					if(cnt == n - 1) break;
				}
				ans = min(ans, ans1);
//				cout << i << ' ' << ans1 << '\n';
 			} 
 			cout << ans << '\n';
		}
	}
	return;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T --) solve();
	return 0;
}
