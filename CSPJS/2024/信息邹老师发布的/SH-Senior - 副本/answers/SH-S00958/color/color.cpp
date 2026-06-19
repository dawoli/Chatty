#include<bits/stdc++.h>
using namespace std;
const int N=2e3+9;
int T,n,a[N],dp[N][N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=1;j<i-1;j++){
				if(a[i]==a[i-1]) dp[i][j]=dp[i-1][j]+a[i];
				else dp[i][j]=dp[i-1][j];
				if(a[j]==a[i]) dp[i][i-1]=max(dp[i-1][j]+a[i],dp[i][i-1]);
				else dp[i][i-1]=max(dp[i][i-1],dp[i-1][j]);
			}
		}
		int ans=0;
		for(int i=1;i<n;i++)
			ans=max(ans,dp[n][i]);
		printf("%d\n",ans);
	}
}
