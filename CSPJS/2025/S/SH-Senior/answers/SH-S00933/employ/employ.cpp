#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 505;
const int MOD = 998244353;
int n, m, d[N], c[N], a[N], cnt;
bool fla = 1;
void solve() {
	cin >> n >> m;
	rep(i, 1, n) {
		char ch; cin >> ch;
		d[i] = ch - '0';
		if(d[i] == 0) fla = 0;
	}
	rep(i, 1, n) cin >> c[i];
	rep(i, 1, n) a[i] = i;
	if(fla) {
		int ans = 1;
		rep(i, 1, n) ans = ans * i % MOD;
		cout << ans << '\n';
	} else if(m == n) {
		bool flag = 1;
		rep(i, 1, n) if(d[i] != 1) flag = 0;
		int ans = 1;
		rep(i, 1, n) ans = ans * i % MOD;
		cout << (flag ? ans : 0) << '\n';
	} else {
		do {
			int rej = 0, acc = 0;
			rep(i, 1, n) {
				if(d[i] == 0 || rej >= c[a[i]]) {
					++ rej;
				} else {
					++ acc;
				}
			}
			if(acc >= m) {
	//			rep(i, 1, n) cout << a[i]; cout << '\n';
				++ cnt;
				cnt = (cnt + MOD) % MOD;
			}
		} while(next_permutation(a + 1, a + 1 + n));
		cout << cnt % MOD;	
	}
	return;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T --) solve();
	return 0;
}
