#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e3+10;
long long t,n,a[Maxn],dp[Maxn][Maxn],ans,i,j;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof(dp)); ans=0;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=2;i<=n;i++)
		for(j=0;j<i-1;j++){
			if(a[j]==a[i]){
				dp[i][i-1]=max(dp[i][i-1],dp[j][i-1]+a[i]);
				dp[i-1][i]=max(dp[i-1][i],dp[i-1][j]+a[i]);
			}
			else{
				dp[i][i-1]=max(dp[i][i-1],dp[j][i-1]);
				dp[i-1][i]=max(dp[i-1][i],dp[i-1][j]);
			}
			if(a[i]==a[i-1]){
				dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i]);
				dp[j][i]=max(dp[j][i],dp[j][i-1]+a[i]);
			}
			else{
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				dp[j][i]=max(dp[j][i],dp[j][i-1]);
			}
		}
		for(i=0;i<n;i++)
		ans=max(ans,max(dp[n][i],dp[i][n]));
		cout<<ans<<endl;
	}
	return 0;
}
