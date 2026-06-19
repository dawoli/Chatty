#include<bits/stdc++.h>
using namespace std;
int T,N,A[200005],dp[2][2005][2005],maxdp[2][2][2005],ans;
bool flag[2005];
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	for(;T;T--) {
		scanf("%d",&N);
		memset(maxdp[0],0,sizeof(maxdp[0]));
		memset(maxdp[1],0,sizeof(maxdp[1]));
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=2000;i++) memset(dp[0][i],0,sizeof(dp[0][i]));
		for(int i=1;i<=2000;i++) memset(dp[1][i],0,sizeof(dp[1][i]));
		ans=0;
		for(int i=1;i<=N;i++) {
			scanf("%d",&A[i]);
			for(int j=1;j<=2000;j++) {
				if(flag[A[i]]) dp[1][A[i]][j]=max(dp[0][A[i]][j]+A[i],dp[0][maxdp[0][1][j]][j]);
				else dp[1][A[i]][j]=dp[0][maxdp[0][1][j]][j];
				if(dp[1][A[i]][j]>dp[1][maxdp[1][1][j]][j]) maxdp[1][1][j]=A[i];
				if(dp[1][A[i]][j]>dp[1][A[i]][maxdp[1][0][A[i]]]) maxdp[1][0][A[i]]=j;
				ans=max(dp[1][A[i]][j],ans);
			}
			for(int j=1;j<=2000;j++) {
				if(j==A[i]) continue;
				if(flag[A[i]]) dp[1][j][A[i]]=max(dp[0][j][A[i]]+A[i],dp[0][j][maxdp[0][0][j]]);
				else dp[1][j][A[i]]=dp[0][j][maxdp[0][0][j]];
				if(dp[1][j][A[i]]>dp[1][j][maxdp[1][0][j]]) maxdp[1][0][j]=A[i];
				if(dp[1][j][A[i]]>dp[1][maxdp[1][1][A[i]]][A[i]]) maxdp[1][1][A[i]]=j;
				ans=max(dp[1][j][A[i]],ans);
			}
			flag[A[i]]=true;
			for(int j=1;j<=2000;j++) {
				maxdp[0][0][j]=maxdp[1][0][j];
				maxdp[0][1][j]=maxdp[1][1][j];
				dp[0][A[i]][j]=dp[1][A[i]][j];
				dp[0][j][A[i]]=dp[1][j][A[i]];
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
