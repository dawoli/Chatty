#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 2e5 + 5;
const ll Maxn = 1e6 + 5;
ll a[maxn], n, Max = 0, T;
ll to[Maxn];
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &T);
	while(T--){
		memset(to, 0, sizeof(to));
		scanf("%lld", &n);
		for(ll i = 1; i <= n; i++){
			scanf("%lld", a + i);
			to[a[i]]++;
			Max = max(Max, a[i]);
		}
		ll ans = 0;
		for(ll i = 1; i <= Max; i++){
			if(to[i] > 0)
				ans += (to[i] - 1) * i;
		}
		cout << ans << endl;
	}
	return 0;
}
