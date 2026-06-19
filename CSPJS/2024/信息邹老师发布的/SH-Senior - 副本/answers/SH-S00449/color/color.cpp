#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int t, n;
ll a[200005] = {0};
ll f[200005];
int lst[1000005] = {0};
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%lld", &a[i]);
			lst[a[i]] = 0;
			f[i] = 0;
		}
		int m = 0;
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] != a[i-1]){
				a[++m] = a[i];
			}else{
				ans += a[i];
			}
		}
		for(int i = 1;i <= m;i++){
			if(lst[a[i]])
				f[i] = max(f[i-1], f[lst[a[i]]+1]+a[i]);
			else
				f[i] = f[i-1];
			lst[a[i]] = i;
		}
		printf("%lld\n", ans+f[m]);
	}
	return 0;
}