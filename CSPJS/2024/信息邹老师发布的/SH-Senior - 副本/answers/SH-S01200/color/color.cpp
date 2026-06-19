#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
int t,n;
ll dp[2010][2010],a[N],f[N][12],mx,ans=0;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);mx=0;
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]),mx=max(mx,a[i]);
		ans=0;
		if(n<=2000) {
			memset(dp,-1,sizeof(dp));
			dp[1][0]=0;
			for(int i=1;i<=n;++i)
				for(int j=0;j<=2000;++j)
					if(dp[i][j]>=0) {
						if(a[i+1]==a[i]) dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i]);
						else dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
						if(a[i+1]==j) dp[i+1][a[i]]=max(dp[i+1][a[i]],dp[i][j]+j);
						else dp[i+1][a[i]]=max(dp[i+1][a[i]],dp[i][j]);
					}
			for(int j=0;j<=2000;++j)
				if(dp[n][j]>=0)
					ans=max(ans,dp[n][j]);
		}
		else if(mx<=10) {
			memset(f,-1,sizeof(f));
			f[1][0]=0;
			for(int i=1;i<=n;++i)
				for(int j=0;j<=10;++j)
					if(f[i][j]>=0) {
						if(a[i+1]==a[i]) f[i+1][j]=max(f[i+1][j],f[i][j]+a[i]);
						else f[i+1][j]=max(f[i+1][j],f[i][j]);
						if(a[i+1]==j) f[i+1][a[i]]=max(f[i+1][a[i]],f[i][j]+j);
						else f[i+1][a[i]]=max(f[i+1][a[i]],f[i][j]);
					}
			for(int j=0;j<=10;++j)
				if(f[n][j]>=0)
					ans=max(ans,f[n][j]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
