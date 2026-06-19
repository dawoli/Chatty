#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define int long long
const int mod=998244353;
int qpow(int x,int y)
{
	if(y==0)return 1;
	int t=qpow(x,y>>1);
	t*=t;
	t%=mod;
	if(y&1)t*=x;
	return t%mod;
}
int n,m,a[501],cnt[501],dp[2][501][501],inv[501],fact[501];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for(int i=1;i<=500;i++)inv[i]=qpow(i,mod-2);
	fact[0]=1;
	for(int i=1;i<=500;i++)fact[i]=fact[i-1]*i%mod;
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i-1;j++)
		{
			for(int k=0;k<=i-1;k++)
			{
				dp[1][j+1][k]+=dp[0][j][k]*(cnt[j]-i+k+1)%mod;
				dp[1][j+((s[i]-'0')^1)][k+1]+=dp[0][j][k];
			}
		}
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=i;k++)
			{
				dp[0][j][k]=dp[1][j][k]%mod;
				dp[1][j][k]=0;
			}
		}
		for(int j=0;j<=i;j++)
		{
			for(int k=s[i]-'0';k<=i;k++)
			{
				int c;
				int t=cnt[j];
				if(j!=0)t-=cnt[j-1];
				for(int l=0;l<=t;l++)
				{
					if(l==0)c=1;
					else
					{
						c*=t-l+1;
						c%=mod;
						c*=inv[l];
						c%=mod;
					}
					if(k+l<=i)dp[1][j][k]+=dp[0][j][k+l]*c%mod*fact[k-(s[i]-'0')]%mod;
				}
			}
		}
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=i;k++)
			{
				dp[0][j][k]=dp[1][j][k]%mod;
				dp[1][j][k]=0;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)ans+=dp[0][i][0];
	cout<<ans%mod<<endl;
}
//end of my season
//not afoed