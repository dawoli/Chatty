#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,l,v,p[100005],cnt,J,ans,f[1000005];
struct car
{
	ll d,v,a;
	double l=-1,r=-1;
}c[100005];
struct detected_car
{
	ll id;
	double l,r;
}a[100005];
bool cmp(detected_car a,detected_car b)
{
	return a.r<b.r;
}
ll find(ll id)
{
	ll l=1,r=m,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(p[mid]>a[id].r) r=mid-1;
		else l=mid+1;
	}
	return l;
}
ll find1(ll id)
{
	ll l=1,r=m,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(p[mid]>c[id].r) r=mid-1;
		else l=mid+1;
	}
	return l-1;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		cnt=ans=J=0;
		scanf("%lld%lld%lld%lld",&n,&m,&l,&v);
		for(int i=1;i<=n;i++)
		{
			c[i].l=c[i].r=-1;
			scanf("%lld%lld%lld",&c[i].d,&c[i].v,&c[i].a);
			if(c[i].a>0)
			{
				if(c[i].v>v) 
				{
					c[i].l=c[i].d;
					c[i].r=l+1;
				}	
				else if(c[i].v*c[i].v+2*c[i].a*(l-c[i].d)<=v*v)
				{
					c[i].r=-1;
					c[i].l=-1;
				}
				else 
				{
					c[i].l=c[i].d+(v*v-c[i].v*c[i].v)*0.5/c[i].a+0.000000001;
					c[i].r=l+1;
				}
			}
			if(c[i].a==0&&c[i].v>v)
			{
				c[i].l=c[i].d;
				c[i].r=l+1;
			}
			if(c[i].a<0&&c[i].v>v)
			{
				c[i].l=c[i].d;
				c[i].r=min(1.0*l,c[i].d+(v*v-c[i].v*c[i].v)*0.5/c[i].a-0.000000001);
			}
		}
		for(int i=1;i<=m;i++)
			scanf("%lld",&p[i]);
		for(int i=1;i<=n;i++)
		{
			if(c[i].l==-1&&c[i].r==-1) continue;
			if(p[find1(i)]>=c[i].l)
			{
				a[++cnt].l=c[i].l;
				a[cnt].r=c[i].r;
			}		
		}
		printf("%lld ",cnt);
		sort(a+1,a+cnt+1,cmp);	
		for(int i=1;i<=cnt;i++)
		{
			if(p[J]>=a[i].l&&p[J]<=a[i].r) continue;
			J=find(i)-1;
			ans++;
		}
		printf("%lld\n",m-ans);
	}
	return 0;
}
