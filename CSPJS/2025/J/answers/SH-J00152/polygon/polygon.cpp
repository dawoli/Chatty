#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,cnt;
ll a[5010];
namespace A
{
	void dfs(ll i,ll sum,ll maxn,ll tot)
	{
		//cout<<i<<' '<<sum<<' '<<maxn<<' '<<tot<<'\n';
		if(i>n)
		{
			if(tot>=3&&sum>maxn*2)
				cnt=(cnt+1)%mod;
			return;
		}
		dfs(i+1,sum+a[i],max(maxn,a[i]),tot+1);
		dfs(i+1,sum,maxn,tot);
	}
	void solve()
	{
		dfs(1,0,0,0);
		cout<<cnt;
	}
}
namespace B
{
	void solve()
	{
		ll mul=1;
		for(int i=1;i<=n;i++)
		{
			mul*=2;
			mul%=mod;
		}
		mul-=1+n+n*(n-1)/2;
		mul=(mul+mod)%mod;
		cout<<mul;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20)
		A::solve();
	else
		B::solve();
	return 0;
} 
