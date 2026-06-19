#include<bits/stdc++.h>
using namespace std;
int T,n;
long long dp[3005][3005],A[400005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
		if(n<=2000){
			memset(dp,0,sizeof(dp));
			A[0]=-1000;
			for(int i=0;i<n;i++)
				for(int j=0;j<=i;j++){
					dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(A[i+1]==A[i]?A[i]:0));
					dp[i+1][i]=max(dp[i+1][i],dp[i][j]+(A[i+1]==A[j]?A[j]:0));
				}
			long long maxx=0;
			for(int j=0;j<=n;j++) maxx=max(maxx,dp[n][j]);
			printf("%lld\n",maxx);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
