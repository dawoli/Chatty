#include<bits/stdc++.h>
using namespace std;
const int Mod_num=998244353;
//int dp[2][25001];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	int a[n+1],sum[n+1];
	sum[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int dp[2][sum[n]+1];//dp[i][j]表示前i个数中和为j的方法数 
	for(int i=1;i<=sum[n];i++) dp[0][i]=0;
	//for(int i=0;i<=n;i++) dp[i][0]=1;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		memset(dp[1],0,sizeof(dp[1]));
		dp[1][0]=1;
		int num=0;
		for(int j=1;j<=sum[i];j++){
			if(j>=a[i]) dp[1][j]=dp[0][j]+dp[0][j-a[i]];
			else dp[1][j]=dp[0][j];
			//cout<<dp[i][j]<<" ";
			dp[1][j]%=Mod_num;
			if(j>2*a[i]) num+=dp[0][j-a[i]];
			num%=Mod_num;
		}
		//cout<<endl;
		if(i>=3) ans+=num;
		ans%=Mod_num;
		for(int i=0;i<=sum[n];i++) dp[0][i]=dp[1][i];
	}
	cout<<ans;
	return 0;
}
