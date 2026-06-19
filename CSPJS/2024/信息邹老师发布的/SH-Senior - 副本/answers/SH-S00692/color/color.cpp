#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 2e5 + 10;
int t, n, last[2];
ll a[N], ans;
unordered_set<ll> s;
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		s.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
		    scanf("%lld", &a[i]);
		    s.insert(a[i]);
		}
		if (s.size() == n) {
			puts("0");
			continue;
		}
		ans = 0;
		for (ll i = 0; i <= (1 << n) - 1; i++) {
			ll res = 0;
			last[0] = last[1] = 0;
		    for (int j = 1; j <= n; j++)
		        if (i & (1LL << (j - 1))) { // red
		            if (a[j] == last[1])
		                res += a[j];
		        	last[1] = a[j];
				} else { // blue
					if (a[j] == last[0])
					    res += a[j];
					last[0] = a[j];
				}
			ans = max(ans, res);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
