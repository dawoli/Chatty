#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lb(i) (i & -i)

const int N = 200005, M = 1e6 + 5;
int T, n, a[N], t[M];

inline void upd(int i, int x) {
	while (i <= 1e6 + 2) {
		t[i] += x;
		i += lb(i);
	}
}

inline int qry(int i) {
	int res = 0;
	while (i) {
		res += t[i];
		i -= lb(i);
	}
	return res;
}

signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) scanf("%lld", a + i);
		upd(1, -1e12), upd(1e6 + 1, 1e12);
		int m = 0;
		for (int i = 1; i < n; i++) {
			int x = max(m, qry(a[i + 1]) + a[i + 1]);
			if (a[i] == a[i + 1]) {
				upd(1, a[i]), upd(1e6 + 2, -a[i]);
				m += a[i];
			}
			m = max(m, x);
			x = max(0ll, x - qry(a[i]));
			upd(a[i], x), upd(a[i] + 1, -x);
			//for (int i = 0; i <= 13; i++) cout << f[i] << ' ';
			//cout << "    " << m << '\n';
		}
		int ans = 0;
		for (int i = 1; i <= 1e6 + 1; i++) ans = max(ans, qry(i));
		printf("%lld\n", ans);
	}
	return 0;
}
/*
1
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13

*/
