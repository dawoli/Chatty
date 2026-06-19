#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 510
#define T 18
#define mod 998244353
int a[N],p[N],c[N],dp[(1<<T)+10][T+2];
int f(int x)
{
	int cnt=0;
	while(x)
	{
		cnt+=x%2;
		x/=2;
	}
	return cnt;
}
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	int n,t,ans=0;
	cin>>n>>t>>s;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=n;i++) a[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18)
	{
		dp[0][0]=1;
		for(int i=0;i<=(1<<n)-2;i++)
		{
			int pp=f(i);
			for(int k=0;k<=n;k++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i&(1<<(j-1))) continue;
					if(c[j]<=k||a[pp+1]==0) dp[i|(1<<(j-1))][k+1]=(dp[i|(1<<(j-1))][k+1]+dp[i][k])%mod;
					else dp[i|(1<<(j-1))][k]=(dp[i|(1<<(j-1))][k]+dp[i][k])%mod;
				}
			}
		}
		for(int i=0;i<=n-t;i++) ans=(ans+dp[(1<<n)-1][i])%mod;
		cout<<ans;
	}
	else if(n==t)
	{
		int mc=*min_element(c+1,c+n+1),ma=*min_element(a+1,a+n+1);
		if(ma>=1&&mc>=1)
		{
			ans=1;
			for(int i=1;i<=n;i++) ans=ans*i%mod;
			cout<<ans;
		}
		else cout<<0;
		return 0;
	}
	return 0;
}

