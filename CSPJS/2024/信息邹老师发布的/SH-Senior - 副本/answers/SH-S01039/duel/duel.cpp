#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100010;
ll n, r[N], cnt[N], sum, ans;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) scanf("%lld", &r[i]), cnt[r[i]]++;
	ans = n, sum = 0;
	for(ll i = 1; i <= 100000; i++) {
		ll t = min(sum, cnt[i]);
		ans -= t;
		sum += cnt[i] - t;
	}
	printf("%lld\n", ans);
	return 0;
}
