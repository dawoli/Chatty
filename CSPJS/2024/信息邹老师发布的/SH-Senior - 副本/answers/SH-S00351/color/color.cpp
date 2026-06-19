#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int M = 1e6 + 10;
int t,n,a[N],c[N],d[M],c1[N],ans;
bool b[N];
void init(){
	for(int i = 1; i <= n; i++){
		c[i] = d[a[i]] = 0;
		c1[i] = 0;
		b[i] = false;
	}
	ans = 0;
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		init();
		for(int i = 1; i <= n; i++){
			scanf("%lld",&a[i]);
		}
		for(int i = n; i >= 1; i--){
			c[i] = d[a[i]];
			d[a[i]] = i;
		}
		for(int i = 1; i <= n; ){
			b[i] = true;
			if(c[i]){
				i = c[i];
			}else{
				i++;
			}
		}
		int cl0 = 0,cl1 = 0;
		for(int i = 1; i <= n; i++){
			if(b[i]){
				c1[i] = cl1;
				cl1 = i;
			}else{
				c1[i] = cl0;
				cl0 = i;
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[c1[i]] == a[i]){
				ans += a[i];
			}
		}
		printf("%lld\n",ans);
	}
    return 0;
}
