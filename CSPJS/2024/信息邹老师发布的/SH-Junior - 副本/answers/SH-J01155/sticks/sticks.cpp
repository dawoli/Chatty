#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, n;
ll cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
inline ll calc(ll x) {
	ll res = 0;
	while (x) {
		res += cnt[x % 10];
		x /= 10;
	}
	return res;
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &n);
		if (n == 1) {
			printf("-1\n");
			continue;
		}
		if (n <= 27) {
			ll x = 1;
			while (calc(x) != n) {
				x ++;
			}
			printf("%lld\n", x);			
		} else {
			ll r = n % 7;
			ll k = (n - r) / 7;
			if (r == 0) {
				for (ll i = 1; i <= k; i ++)
					printf("8");
			} else if (r == 1) {
				printf("10");
				for (ll i = 1; i <= k - 1; i ++)
					printf("8");
			} else if (r == 2) {
				printf("1");
				for (ll i = 1; i <= k; i ++)
					printf("8");
			} else if (r == 3) {
				printf("200");
				for (ll i = 1; i <= k - 2; i ++)
					printf("8");
			} else if (r == 4) {
				printf("20");
				for (ll i = 1; i <= k - 1; i ++)
					printf("8");
			} else if (r == 5) {
				printf("2");
				for (ll i = 1; i <= k; i ++)
					printf("8");
			} else if (r == 6) {
				printf("6");
				for (ll i = 1; i <= k; i ++)
					printf("8");
			}
			printf("\n");
		}
	}
	return 0;
}
