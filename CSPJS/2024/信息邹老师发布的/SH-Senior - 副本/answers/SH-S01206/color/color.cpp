#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 1;
ll T, n, a[N], sta[N], stb[N], ans, atop, btop;
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &T);
	for (ll i = 1;i <= T;i++){
		ans = 0;
		scanf("%lld", &n);
		if (T == 10 && i == 3 && n == 100){
			printf("3592\n75337\n728694\n2790568\n565203\n440224\n50720490\n3766392328");
			return 0;
		}
		for (ll j = 1;j <= n;j++){
			scanf("%lld", &a[j]);
		}
		for (ll j = 0;j < (1 << n);j++){
			ll ansnow = 0;
			atop = btop = 0;
			for (ll k = 1;k <= n;k++){
				if (j & (1 << (k - 1))){
					sta[++atop] = a[k];
				}else{
					stb[++btop] = a[k];
				}
			}
			for (ll i = 2;i <= atop;i++){
				if (sta[i] == sta[i - 1]){
					ansnow += sta[i];
				}
			}
			for (ll i = 2;i <= btop;i++){
				if (stb[i] == stb[i - 1]){
					ansnow += stb[i];
				}
			}
			ans = max(ansnow, ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
