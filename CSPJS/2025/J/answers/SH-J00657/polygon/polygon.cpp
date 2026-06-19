#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[5005],dp[5005][5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5005;j++)
			dp[i][j]=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=5005;j>=a[i];j--)
			if(j>(a[i]*2))	
				dp[i][j]+=dp[i-1][j-a[i]];
		for(int j=5005;j>=a[i];j--)
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
	}
	int ans=0;
	for(int i=1;i<=5005;i++){
		ans+=dp[n][i]%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
//计数dp啊，包的 
//dp[i][j]表示看到第i根木棍，和为j
//排序确定最大值 
//dp[i][j]+=dp[i-1][j-a[i]];
//10:30 ::洪文了，什么鬼东西啊，为什么算了半天式子后来错了啊！！！！
//果然是状态极差，头痛死了  
//11:45 ::好的，彻底放弃了 这下考砸了，肯定没一等，炸了孩子们 
