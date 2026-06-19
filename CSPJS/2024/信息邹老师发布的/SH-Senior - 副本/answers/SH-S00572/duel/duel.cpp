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
const int N = 1e5 + 5;
int n, cnt[N], a[N];
signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n) {
		cin >> a[i];
		++cnt[a[i]];
	}
	int ans = 0;
	FOR (i, 1, N - 5) {
		ans = cnt[i] + max(0LL, ans - cnt[i]);
	}
	cout << ans << '\n';
	return 0;
}
