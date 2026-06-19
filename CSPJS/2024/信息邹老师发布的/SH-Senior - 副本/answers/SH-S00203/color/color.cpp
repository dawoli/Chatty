#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
ll T,n,a[152];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		rep(i,1,n)scanf("%lld",&a[i]);
		if(n <= 21){
			ll pre1 = 0,pre2 = 0,ans = 0;
			rep(i,0,(1 << n) - 1){
				pre1 = pre2 = 0;
				ll sum = 0;
				rep(j,1,n){
					if((1 << (j - 1)) & i){
						if(pre2 == a[j])sum += pre2;
						pre2 = a[j]; 
					}
					else{
						if(pre1 == a[j])sum += pre1;
						pre1 = a[j]; 
					}
				}
//				cout << i << ":" << sum << endl;
				ans = max(ans,sum);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

