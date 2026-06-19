#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5; 
int T, n, a[maxn], sum[maxn], f[maxn][2], ans, c[maxn];
void dfs(int pos, int s[]) {
	if (pos == n + 1) {
		int res = 0;
		for (int i=1; i<=n; i++) {
			for (int j=i-1; j>=1; j--) {
				if (s[i] == s[j]) {
					res += (a[i] == a[j] ? a[i] : 0);
					break;
				}
			}
		}
		ans = max(ans, res);
		return ;
	}
	s[pos] = 1;
	dfs(pos + 1, s);
	s[pos] = 0;
	dfs(pos + 1, s);
}
void solve() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	ans = -1e15;
	dfs(1, c);
	cout << ans << endl;
	return ;
}
signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while (T --) {
		solve();
	} 
}
