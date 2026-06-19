#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
const int N = 1e3 + 5;
int d[N], v[N], a[N], p[N], vis[N], g[N][N], c[N], ch[N], cc, ans = 1e9, vv[N];
bool check(int p, int v, int V, int a, int d, double t) {
	if(a > 0 && v <= V && p - t > eps) return true;
	if(a > 0 && v > V && p >= d) return true;
	if(a < 0 && v > V && p >= d && t - p > eps) return true;
	return false;
}
void dfs(int x, int m, int s, int n) {
	if(s >= ans) return;
	if(x > m) {
		for(int i = 1; i <= n; i++) vv[i] = 0;
		for(int i = 1; i <= cc; i++)
			for(int j = 1; j <= c[ch[i]]; j++) vv[g[ch[i]][j]] = 1;
		int flag = 1;
		for(int i = 1; i <= n; i++)
			if(!vv[i] && vis[i]) flag = 0;
		if(flag) ans = s;
		return;
	}
	dfs(x + 1, m, s, n);
	ch[++cc] = x; dfs(x + 1, m, s + 1, n); --cc;
} 
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		int n, m, L, V, cnt = 0;
		cin >> n >> m >> L >> V;
		for(int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
		for(int i = 1; i <= m; i++) cin >> p[i];
		sort(p + 1, p + m + 1);
		for(int i = 1; i <= n; i++) {
			if(a[i] == 0) {
				if(v[i] > V) {
					vis[i] = 1;
					for(int j = 1; j <= m; j++)
						if(p[j] >= d[i]) g[j][++c[j]] = i;
				}
			}
			else {
				double t = 1.0 * (V * V - v[i] * v[i]) / (2 * a[i]);
				for(int j = 1; j <= m; j++)
					if(check(p[j], v[i], V, a[i], d[i], t + d[i])) {
						vis[i] = 1;
						g[j][++c[j]] = i;
					}
			}
			if(vis[i]) cnt++;
		}
		cc = 0; dfs(1, m, 0, n);
		cout << cnt << " " << n - ans << "\n";
		for(int i = 1; i <= n; i++) vis[i] = 0, vv[i] = 0;
		for(int i = 1; i <= m; i++) c[i] = 0;
	}
	return 0;
}
