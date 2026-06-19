#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, n, tot, ans;
ll a[100100][5];
ll b[100100];
ll typ[100100];
ll num[5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		ans = 0;
		scanf("%lld", &n);
		for (ll i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
			if (a[i][0] >= max(a[i][1], a[i][2])) {
				typ[i] = 0;
			} else {
				if (a[i][1] >= a[i][2]) {
					typ[i] = 1;
				} else {
					typ[i] = 2;
				}
			}
			num[typ[i]]++;
			ans += a[i][typ[i]];
		}
		for (ll o = 0; o < 3; o++) {
			if (num[o] > n / 2) {
				tot = 0;
				for (ll i = 1; i <= n; i++) {
					if (typ[i] == o) {
						ll x = a[i][o] - a[i][0];
						ll y = a[i][o] - a[i][1];
						ll z = a[i][o] - a[i][2];
						if (x < 0 || y < 0 || z < 0) {
							assert(0);
						}
						ll mx = max(max(x, y), z);
						b[++tot] = (x ^ y ^ z ^ mx);
					}
				}
				sort(b + 1, b + tot + 1);
				tot = 0;
				while (num[o] > n / 2) {
					ans -= b[++tot];
					num[o]--;
				}
			}
			num[o] = 0;
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
