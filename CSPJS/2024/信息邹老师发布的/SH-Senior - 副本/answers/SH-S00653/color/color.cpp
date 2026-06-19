#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e3+5;
int T,n,a[N];
LL dp[N][2][N],ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
        	for(int j=0;j<i;j++){
        		dp[i+1][0][j]=max(dp[i+1][0][j],dp[i][0][j]);
        		if(a[i+1]==a[i]) dp[i+1][0][j]=max(dp[i+1][0][j],dp[i][0][j]+a[i]);
        		dp[i+1][1][i]=max(dp[i+1][1][i],dp[i][0][j]);
        		if(a[i+1]==a[j]) dp[i+1][1][i]=max(dp[i+1][1][i],dp[i][0][j]+a[j]);
        		dp[i+1][1][j]=max(dp[i+1][1][j],dp[i][1][j]);
        		if(a[i+1]==a[i]) dp[i+1][1][j]=max(dp[i+1][1][j],dp[i][1][j]+a[i]);
        		dp[i+1][0][i]=max(dp[i+1][0][i],dp[i][1][j]);
        		if(a[i+1]==a[j]) dp[i+1][0][i]=max(dp[i+1][0][i],dp[i][1][j]+a[j]);
			}
		}
		for(int i=0;i<n;i++) ans=max(ans,max(dp[n][0][i],dp[n][1][i]));
		printf("%lld\n",ans);
	}
	return 0;
}
