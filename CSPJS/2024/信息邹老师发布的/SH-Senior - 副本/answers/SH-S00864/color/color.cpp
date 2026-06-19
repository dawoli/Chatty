#include<bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 200005;
const int INF = 0x3f3f3f3f;
int n, a[N], mans = -INF;
//ºì0 À¶1 
void dfs(int u, int coll[30]) {
	if(u == n + 1) {
//		cout << "hei";
		int c[30]; memset(c, 0, sizeof(c));
		rep(i, 1, n) {
			int ok = 0, okid = 0;
			per(j, i - 1, 1)
				if(coll[j] == coll[i]) {
					ok = 1;
					okid = j;
					break;
				}
			if(ok == 0) c[i] = 0;
			else {
				if(a[i] == a[okid]) c[i] = a[i];
				else c[i] = 0;
			}
		}
		int ans = 0;
		rep(i, 1, n) ans += c[i];
		mans = max(mans, ans);
	}
	coll[u] = 0;
	dfs(u + 1, coll);
	coll[u] = 1;
	dfs(u + 1, coll);
}
void clear() {
	n = 0;
	memset(a, 0, sizeof(a));
}
void solve() {
	cin >> n; rep(i, 1, n) cin >> a[i];
	int col[30]; memset(col, 0, sizeof(col));
	dfs(1, col);
	cout << mans << '\n';
}
signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T = 1; cin >> T;
	while(T --) {
		clear();
		solve();
	}
	return 0;
} 
