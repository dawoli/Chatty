#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,dp[2][10010],f[2][10010],a[5010],ans=1,s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n),f[0][0]=1;
	for(int w=1;w<=n;w++)scanf("%d",&a[w]),ans=2*ans%mod;
	sort(a+1,a+n+1),ans=(ans-1+mod)%mod;
	for(int w=1;w<=n;w++){
		for(int x=0;x<=10000;x++){
			dp[w&1][x]=dp[(w&1)^1][x],f[w&1][x]=f[(w&1)^1][x];
			if(x>=a[w]&&x<=2*a[w])dp[w&1][x]=(dp[w&1][x]+f[(w&1)^1][x-a[w]])%mod;
			if(x>=a[w])f[w&1][x]=(f[w&1][x]+f[(w&1)^1][x-a[w]])%mod;
		}
	}
	for(int x=0;x<=10000;x++)s=(s+dp[n&1][x])%mod;
	printf("%d",(ans-s+mod)%mod);
	return 0;
}
