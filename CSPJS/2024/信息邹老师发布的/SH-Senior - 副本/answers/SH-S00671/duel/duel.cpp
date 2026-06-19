#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e5 + 5;
ll to[maxn], n, ans = 0, Maxn = 0;
ll max(ll a, ll b){
	if(a > b)
		return a;
	return b;
}
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++){
		ll x;
		scanf("%lld", &x);
		to[x]++;
		Maxn = max(Maxn, x);
	}
	for(ll i = 1; i <= Maxn; i++)
		ans = max(ans, to[i]);
	printf("%lld", ans);
	return 0;
}
