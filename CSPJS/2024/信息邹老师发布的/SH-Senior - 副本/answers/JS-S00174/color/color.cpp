//color
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 2e5 + 5;
ll t, n, a[MAXN], cnt[1000005];

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
    scanf("%lld", &t);
	while (t--){
		scanf("%lld", &n);
		for (ll i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
		}
		if (n > 20){
			for (ll i = 1; i <= n; i++){
				cnt[a[i]]++;
			}
			ll ans = 0;
			for (ll i = 1; i <= n; i++){
				ans = max(ans, (cnt[a[i]]-1)*a[i]);
			}
			printf("%lld\n", ans);
		} else{
			ll lr, lb, C, ans = 0; 
			for (ll i = 0; i < (1<<n); i++){
				lr = 0, lb = 0, C = 0;
				for (ll j = 0; j < n; j++){
				    if ((i>>j)&1){ // red
				    	if (lr>0 && a[lr]==a[j+1])
				    		C += a[lr];
						lr = j+1;
					} else{ // blue 
				    	if (lb>0 && a[lb]==a[j+1])
				    		C += a[lb];
						lb = j+1;
					}
				}
				ans = max(ans, C);
			}
			printf("%lld\n", ans);
		}
	} 
	return 0;
} 
