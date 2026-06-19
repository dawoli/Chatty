#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
ll c[20];
ll a[20][10010];
ll f[10010];
ll ff(ll s)
{
	if(s==f[s])
		return s;
	return f[s]=ff(f[s]);
}
bool rf(ll x,ll y)
{
	ll fx=ff(x),fy=ff(y);
	if(fx!=fy)
	{
		f[fy]=fx;
		return 1;
	}
	return 0;
}

struct Node
{
	ll u,v,w;
	void in()
	{
		scanf("%lld%lld%lld",&u,&v,&w);
	}
}e[1000010];
bool cmp(Node x,Node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll cnt=n;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		e[i].in();
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		int last=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
			{
				if(last!=0)
				{
					bool flag=rf(last,j);
					if(flag)
						cnt--;
				}
				last=j;
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	ll sum=0;
	for(int i=1;i<=m;i++)
	{
		if(cnt==1)
			break;
		ll x=e[i].u,y=e[i].v;
		if(rf(x,y))
		{
			cnt--;
			sum+=e[i].w;
		}
	}
	cout<<sum;
	return 0;
}
