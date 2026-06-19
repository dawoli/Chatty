//duel
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 1e5 + 5;
ll n, a, ans, cnt[MAXN];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
    scanf("%lld", &n);
	for (ll i = 1; i <= n; i++){
		scanf("%lld", &a);
		cnt[a]++;
		ans = max(ans, cnt[a]);
	} 
	printf("%lld\n", ans);
	return 0;
} 
