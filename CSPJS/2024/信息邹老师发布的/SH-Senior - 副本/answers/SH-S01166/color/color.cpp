#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll T, n, a[N];
bool vis[N];
// vis: 0/1 = red/blue

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%lld", &a[i]);
		}
		ll ans = 0;
		for (ll i = 0; i < (1ll << n); i ++) {
			for (int j = 0; j < n; j ++) {
				if (i & (1ll << j)) vis[j+1] = 0;
				else vis[j+1] = 1;
			}
			ll res = 0, right_red = 0, right_blue = 0;
			for (int j = 1; j <= n; j ++) {
				if (vis[j] == 0) {
					if (a[j] == right_red) res += a[j];
					right_red = a[j];
				} else {
					if (a[j] == right_blue) res += a[j];
					right_blue = a[j];
				}
			}
			ans = max(ans, res);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
