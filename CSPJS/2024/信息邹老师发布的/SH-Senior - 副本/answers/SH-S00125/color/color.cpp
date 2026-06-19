#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=2e5+5,maxa=1e6+5;
ll T,dp[maxn],a[maxn];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ll n,ans=0,amax=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			amax=max(amax,a[i]);
		}
		if(amax>10){
			memset(dp,0,sizeof(dp));
			for(ll i=2;i<=n;i++){
				for(ll j=0;j<i-1;j++) dp[i-1]=max(dp[i-1],dp[j]+(a[j]==a[i])*a[i]);
				for(ll j=0;j<i-1;j++) dp[j]+=(a[i]==a[i-1])*a[i];
			}
			for(ll i=0;i<n;i++) ans=max(ans,dp[i]);
			printf("%lld\n",ans);
		}
		else{
			memset(dp,0xc0,sizeof(dp));
			dp[0]=0;
			for(ll i=2;i<=n;i++){
				ll dplst=0;
				for(ll j=0;j<=amax;j++) dplst=max(dplst,dp[j]+(j==a[i])*a[i]);
				for(ll j=0;j<=amax;j++)
					dp[j]+=(a[i]==a[i-1])*a[i];
				dp[a[i-1]]=max(dp[a[i-1]],dplst);
			}
			for(ll i=0;i<=amax;i++) ans=max(ans,dp[i]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
