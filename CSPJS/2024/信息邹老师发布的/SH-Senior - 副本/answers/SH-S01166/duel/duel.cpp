#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 10;
bool sub2 = true;
ll n, a[N], cnt1, cnt2;
ll cnt[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
		cnt[a[i]] ++;
		if (a[i] == 1) {
			cnt1 ++;
		} else if (a[i] == 2) {
			cnt2 ++;
		} else {
			sub2 = false;
		}
	}
	if (sub2) {
		ll dead = min(cnt1, cnt2);
		printf("%lld\n", n - dead);
		return 0;
	}
	ll ans = 0;
	for (int i = 1; i <= 100000; i ++) {
		ans = max(ans, cnt[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
