#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=200010;
const ll MaxK=1000010;
ll T,n,m;
ll a[MaxN];
ll b[MaxK];
ll c[MaxK];
ll s[MaxN];
ll p[MaxN];
ll dp[MaxN];
int main(){
	ll rx;
	//*/
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	//*/
	scanf("%lld",&T);
	for(ll t=1;t<=T;t++){
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
			scanf("%lld",a+i);
		for(ll i=1;i<=n;i++){
			dp[i]=dp[i-1];
			s[i]=s[i-1]+(a[i]==a[i-1])*a[i];
			if(c[a[i]]<t){
				c[a[i]]=t;
			}else{
				rx=b[a[i]];
				if((rx==i-1)||(rx==i-2))
					dp[i]=dp[i-1]+a[i];
				else
					dp[i]=max(dp[i],dp[rx+1]+a[i]+s[i]-s[rx]);
			}
			b[a[i]]=i;
		}
		printf("%lld\n",dp[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
