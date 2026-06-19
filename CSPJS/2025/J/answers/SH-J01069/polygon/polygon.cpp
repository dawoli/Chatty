#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5009;
const int MOD=998244353;
ll n,st[N],ans=0;
ll C[N][N];
ll dp[N*N]={0};
ll cnt[N];
bool max1()
{
	ll mx=0;
	for(int i=1;i<=n;i++)
	  mx=max(mx,st[i]);
	return mx==1;
}
void inv()
{
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
		  C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>st[i];
	if(max1())
	{
		inv();
		for(int i=3;i<=n;i++)
		  ans=(ans+C[n][i])%MOD;
		cout<<ans;
		return 0;
	}
	if(n<=20)
	{
		ans=0;
		ll sum,mx;
		for(int p=0;p<(1<<n);p++)
		{
			sum=0,mx=0;
			for(int k=0;k<n;k++)
			{
				if((p>>k)&1)
				{
					sum+=st[k+1];
					mx=max(mx,st[k+1]);
				}
			}
			if(mx*2<sum)ans++;
		}
		cout<<ans;
	}
	else
	{
		sort(st+1,st+1+n);
		//ans=2^n-1-n-n*(n-1)/2-(dp[st[1]]+dp[st[2]]+...+dp[st[n]])
		ll V=0;
		dp[0]=1;
		for(int i=1;i<=n;i++)
		{
			V+=st[i];
			cnt[st[i]]++;
			for(ll j=V;j>0;j--)
			{
				if(j>=st[i])
				  dp[j]=(dp[j]+dp[j-st[i]])%MOD;
				else break;
			}
		}
		dp[0]=0;
		for(ll i=1;i<=V;i++)dp[i]=((dp[i]-cnt[i])%MOD+MOD)%MOD;
		for(ll i=1;i<=V;i++)dp[i]=(dp[i-1]+dp[i]);
		ans=1;
		for(int i=1;i<=n;i++)ans=(ans*2)%MOD;
		ans=((ans-1)%MOD+MOD)%MOD;
		ans=((ans-n)%MOD+MOD)%MOD;
		ans=((ans-(n*(n-1)/2))%MOD+MOD)%MOD;
		for(int i=1;i<=n;i++)ans=((ans-dp[st[i]])%MOD+MOD)%MOD;
		cout<<ans;
	}
	return 0;
}

