#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define PII pair<int, int>
#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define ROF(i, r, l) for (int i = (r); i >= (l); --)
#define allc(x) (x).begin(), (x).end()
#define SZ size()
#define FI first
#define SE second
using namespace std;
const int N = 1e6 + 5;
const int inf = 1e18;
int g[N], f[N], n, T, curmx, a[N], s[N];
signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		FOR (i, 1, n) {
			cin >> a[i];
			g[a[i]] = -inf;
			s[i] = s[i - 1];
			if (a[i] == a[i - 1]) {
				s[i] += a[i];
			}
		}
		curmx = -inf;
		FOR (i, 1, n) {
			curmx = max(curmx, f[i - 1] - s[i]);
			if (i > 1) {
				g[a[i - 1]] = max(g[a[i - 1]], f[i - 1] - s[i]);	
			}
			if (i != n) {
				f[i] = max(curmx, g[a[i + 1]] + a[i + 1]) + s[i];
			} else {
				f[i] = curmx + s[i];
			}
		}
		cout << f[n] << '\n';
	}
	return 0;
}
