#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e3+5,mod=998244353;
int n,m,a[N],dp[N],ans,dp2[N],s,gg;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1),m=a[n];
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
			if(j>=a[i]) dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	dp[0]=0;
	for(int i=2;i<=m;i++) dp[i]=(dp[i]+dp[i-1])%mod;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>i) break;
			dp[i]=(dp[i]-1+mod)%mod;
		}
	}
	gg=4;
    for(int i=3;i<=n;i++){
    	s=gg;gg=(gg*2)%mod;
		s=(s-1+mod)%mod;
		s=(s-(i-1)+mod)%mod;
		ans=(ans+((s-dp[a[i]]+mod)%mod))%mod;
	}
	printf("%d\n",ans);
	return 0;
} 

