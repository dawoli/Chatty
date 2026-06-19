#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
int n,m;
ll L,V;
ll light[100010];
struct node
{
	ll d,v,a;
}car[100010];
struct node2
{
	ll l,r;
}line[100010];
ll cur=0;
bool cmp(node2 x,node2 y)
{
	if(x.r!=y.r)
	{
		return x.r<y.r;
	} 
	return x.l<y.l;
}
ll bound_(ll x)
{
	ll l=1,r=m;
	int ret=-1;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(light[mid]>=x)
		{
			ret=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return ret;
}
ll _bound(ll x)
{
	ll l=1,r=m;
	int ret=-1;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(light[mid]<=x)
		{
			ret=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ret;
}
void pus(int l,int r)
{
	node2 add;
	add.l=l,add.r=r;
	line[++cur]=add;
	return ;
}
void work2(ll d,ll v,ll a)
{
	if(d>light[m])
	{
		return ;
	}
	if(a>0)
	{
		if(v>V)
		{
			int x=bound_(d);
			pus(x,m);
			return ;
		}
		double y=(V-v)*1.0/a;
		double road=v*y+0.5*a*y*y+d;
		ll x;
		if(long(floor(road))==long(ceil(road)))
		{
			x=long(road)+1;
		}
		else
		{
			x=long(ceil(road));
		}
		ll z=bound_(x);
		if(z==-1)
		{
			return ;
		}
		pus(z,m);
		return ;
	}
	if(a==0)
	{
		if(v>V)
		{
			ll x=bound_(d);
			pus(x,m);
			return ;
		}
	}
	if(v<=V)
	{
		return ;
	}
	double y=(V-v)*1.0/a;
	double road=v*y+0.5*a*y*y+d;
	ll x;
	if(long(floor(road))==long(ceil(road)))
	{
		x=long(road)-1;
	}
	else
	{
		x=long(floor(road));
	}
	ll z=_bound(x);
	ll g=bound_(d);
	if(z<g)
	{
		return ;
	}
	pus(g,z);
	return ;
}
void work()
{
	cur=0;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++)
	{
		cin>>car[i].d>>car[i].v>>car[i].a;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>light[i];
	}
	for(int i=1;i<=n;i++)
	{
		work2(car[i].d,car[i].v,car[i].a);
	}
	sort(line+1,line+cur+1,cmp);
	ll ans=0;
	ll x=0;
	for(int i=1;i<=cur;i++)
	{
		if(x>=line[i].l&&x<=line[i].r)
		{
			continue;
		}
		ans++;
		x=line[i].r;
	}
	cout<<cur<<" "<<m-ans<<endl; 
}
signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		work();
	}
	return 0;
}
