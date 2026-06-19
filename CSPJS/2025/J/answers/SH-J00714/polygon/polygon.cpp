#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int dp[2][10110];//dp[k]表示在当前小木棍中，长度和为k的选法，若k=10001则为k>10000 
int n,a[10110];
int ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	memset(dp,0,sizeof(dp));
	dp[1][0]=1;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 2;i<=n;i++){//枚举第i根小木棍作为最大值 
		for(int x = 0;x<=10001;x++)dp[i&1][x]=dp[i-1&1][x];
		
		for(int x = 0;x+a[i-1]<=10000;x++)
			dp[i&1][x+a[i-1]]=(dp[i&1][x+a[i-1]]+dp[i-1&1][x])%mod;

		for(int x = 10001;x+a[i-1]>=10001;x--)
			dp[i&1][10001]=(dp[i&1][10001]+dp[i-1&1][x])%mod;
		if(i==2)continue;  //这里也可以不特判，因为i=2一定没有可行解
		 
		for(int k = a[i]+1;k<=10001;k++)//枚举1~i-1小木棍长度总和 
			ans=(ans+dp[i&1][k])%mod;
	}
	cout<<ans;
}
