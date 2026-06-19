#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ki,ans,p=998244353;
string x;
ll f[505];
ll g[505];
ll h[505];
void dfs(ll t,ll k)
{
	if(t==n+1)
	{
		if(k<=n-m)ans++;
		if(ans>=p)ans-=p;
	}
	else
	{
		for(ll i=1;i<=n;i++)
		{
			if(g[i]==0)
			{
				g[i]=1;
				if(f[i]<=k||h[t]==0)dfs(t+1,k+1);
				else dfs(t+1,k);
				g[i]=0;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>x;x="*"+x;
	for(ll i=1;i<=n;i++)h[i]=x[i]-'0';
	for(ll i=1;i<=n;i++)cin>>f[i];
	if(n==m)
	{
		ans=1;
		for(ll i=1;i<=n;i++)
		{
			if(f[i]==0||h[i]==0){cout<<0;return 0;}
			ans*=i;
			if(ans>=p)ans%=p;
		}
		cout<<ans;
	}
	else
	{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}
