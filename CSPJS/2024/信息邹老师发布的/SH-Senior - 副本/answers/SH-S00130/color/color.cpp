#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 200010;
i64 t, n, a[N]; 
inline void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	i64 ans = 0;
	for (int S = 0; S < (1 << n); S++) {
		i64 lb = 0, lr = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			if (S >> i & 1) {
				cur += (a[i] == lb) * lb, lb = a[i];
			} else {
				cur += (a[i] == lr) * lr, lr = a[i];
			}
		}
		ans = max(ans, cur);
	}
	cout << ans << '\n';
}
inline void optimizeIO(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
}
int main(int argc, const char *argv[]) {
#ifndef LOCAL
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
#endif
	optimizeIO(), cin >> t;
	while (t--) solve();
	return 0;
} 
/*
I love yjy forever.
God bless no fst.
*/
/*
1
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
*/
