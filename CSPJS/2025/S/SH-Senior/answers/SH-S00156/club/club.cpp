#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,maxn;
struct Node
{
	ll a[5];
}p[100010];
namespace A
{
	void dfs(ll i,ll x,ll y,ll z,ll sum)
	{
		if(x>n/2||y>n/2||z>n/2)
			return;
		if(i>n)
		{
			maxn=max(maxn,sum);
			return;
		}
		dfs(i+1,x+1,y,z,sum+p[i].a[1]);
		dfs(i+1,x,y+1,z,sum+p[i].a[2]);
		dfs(i+1,x,y,z+1,sum+p[i].a[3]);
	} 
	void solve()
	{
		maxn=0;
		dfs(1,0,0,0,0);
		cout<<maxn<<'\n';
	}
}
namespace B
{
	bool cmp(Node x,Node y)
	{
		return (x.a[1]-x.a[2])>(y.a[1]-y.a[2]);
	}
	void solve()
	{
		sort(p+1,p+n+1,cmp);
		ll sum=0;
		for(int i=1;i<=n/2;i++)
			sum+=p[i].a[1];
		for(int i=n/2+1;i<=n;i++)
			sum+=p[i].a[2];
		cout<<sum<<'\n';
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>p[i].a[j];
		if(n<=30)
			A::solve();
		else
			B::solve();
	}
	return 0;
}
