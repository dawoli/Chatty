#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
const int N=505,M=18,mod=998244353;
int n,m,c[N],bin[N],fac[N],ans,dp[(1<<M)+5][M+1];
char s[N];
vector<int>vec[M+5];
void solveBF()
{
	for(int i=0;i<(1<<n);i++) vec[__builtin_popcount(i)].pb(i);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(auto lst:vec[i-1])
		{
			for(int j=0;j<n;j++)
			{
				if(lst&(1ll<<j)) continue;
				for(int k=0;k<i;k++)
				{
					if(s[i]=='0'||c[j+1]<=i-1-k) dp[lst^(1ll<<j)][k]=(dp[lst^(1ll<<j)][k]+dp[lst][k])%mod;
					else dp[lst^(1ll<<j)][k+1]=(dp[lst^(1ll<<j)][k+1]+dp[lst][k])%mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++) ans=(ans+dp[(1ll<<n)-1][i])%mod;
	cout<<ans;
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;i++) cin>>c[i],bin[c[i]]++;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ans=fac[n];
	if(m==n)
	{
		bool flg=0;
		for(int i=1;i<=n;i++) flg|=(s[i]=='0'),flg|=(c[i]==0);
		if(!flg) cout<<ans;
		else cout<<0;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++) bin[i]+=bin[i-1];
		int nw=0,res=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				if(nw<bin[i-1]) res=res*(bin[i-1]-nw)%mod;
				else res=0;
				nw++;
			}
		}
		res=res*fac[n-nw]%mod;
		cout<<(ans-res+mod)%mod;
		return 0;
	}
	if(n<=18)
	{
		solveBF();
		return 0;
	}
	cout<<0;
	return 0;
}
