#include<bits/stdc++.h>
using namespace std;
const int N=200009, V=1000009;
int T,n,a[N],b[N],rec[V],last[N];
long long sum[N],dp[4][N];
void work() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n==1) { printf("0\n"); return; }
	for (int i=1;i<=1000005;i++) rec[i]=0;
	for (int i=1;i<=n;i++) {
		last[i]=rec[a[i]];
		rec[a[i]]=i;
	}
	for (int i=2;i<=n;i++) {
		b[i]=((a[i]==a[i-1])?a[i]:0);
		sum[i]=sum[i-1]+b[i];
		//cout<<b[i]<<" "<<sum[i]<<endl;
	}
	dp[1][2]=dp[2][2]=0, dp[0][2]=dp[3][2]=b[2];
	for (int i=3;i<=n;i++) {
		dp[0][i]=max(dp[0][i-1],dp[2][i-1])+b[i];
		dp[3][i]=max(dp[1][i-1],dp[3][i-1])+b[i];
		dp[1][i]=max(dp[0][i-1],dp[2][i-1]);
		dp[2][i]=max(dp[1][i-1],dp[3][i-1]);
		int p=last[i];
		if (p==i-1) p=last[p];
		if (p) {
			dp[1][i]=max(dp[1][i],dp[2][p+1]+(sum[i-1]-sum[p+1])+a[i]);
			dp[2][i]=max(dp[2][i],dp[1][p+1]+(sum[i-1]-sum[p+1])+a[i]);
		}
		//for (int j=0;j<4;j++) cout<<dp[j][i]<<" "; cout<<endl;
	}
	long long ans=0;
	for (int i=0;i<4;i++) ans=max(ans,dp[i][n]);
	printf("%lld\n",ans);
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while (T--) work();
	return 0;
}
