#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int c[1005],d[1005];
const long long mod=998244353;
long long dp[300005][22];
long long ans=0;
int lowbit(int x)
{
	return x&-x;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		d[i]=c-'0';
	}
	for(int i=0;i<n;i++) cin>>c[i];
	dp[0][0]=1;
	for(int s=0;s<(1<<n);s++)
	{
		int t=s;
		int cnt=0;
		while(t>0)
		{
			cnt++;
			t-=lowbit(t);
		}
		for(int i=0;i<=cnt;i++)
		{
			for(int j=0;j<n;j++)
			{
				if((s&(1<<j))) continue;
				if(c[j]<=i||d[cnt+1]==0) dp[(s|(1<<j))][i+1]=(dp[s][i]+dp[(s|(1<<j))][i+1])%mod;
				else dp[(s|(1<<j))][i]=(dp[s][i]+dp[(s|(1<<j))][i])%mod;
			}
		}
	}
	for(int j=0;j<=n-m;j++)
	{
		ans=(ans+dp[(1<<n)-1][j])%mod;
	}
	cout<<ans<<endl;
	return 0;
}
