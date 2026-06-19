#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-') f=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=x*10+ch-48,ch=getchar();
	return x*f;
}
const int N=100005;
ll t,n,m;
ll a[N],b[N],c[N];
struct node
{
	ll s,id,ty;
} s[N*2];
ll ans,sa,sb,sc;
ll vis[N],now;
bool cmp(node a,node b)
{
	return a.s>b.s;
}

void solve()
{
	ans=0;
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
	}
	sa=sb=sc=m=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>=b[i]&&a[i]>=c[i]) ++sa,ans+=a[i],vis[i]=1;
		else if(b[i]>=a[i]&&b[i]>=c[i]) ++sb,ans+=b[i],vis[i]=2;
		else if(c[i]>=b[i]&&c[i]>=a[i]) ++sc,ans+=c[i],vis[i]=3;
	}
//	cout<<sa<<" "<<sb<<" "<<sc<<"\n";
	if(sa>n/2)
	{
		for(int i=1;i<=n;++i)
		{
			if(vis[i]!=1) continue;
			s[++m].s=b[i]-a[i];s[m].id=i;s[m].ty=2;
			s[++m].s=c[i]-a[i];s[m].id=i;s[m].ty=3;
		}
		sort(s+1,s+1+m,cmp);
		now=1;
		while(sa>n/2)
		{
			while(now<=m)
			{
				if(vis[s[now].id]==1)
				{
					vis[s[now].id]=s[now].ty,ans+=s[now].s,--sa;
					break;
				}
				++now;
			}
		}
	}
	else if(sb>n/2)
	{
		for(int i=1;i<=n;++i)
		{
			if(vis[i]!=2) continue;
			s[++m].s=a[i]-b[i];s[m].id=i;s[m].ty=1;
			s[++m].s=c[i]-b[i];s[m].id=i;s[m].ty=3;
		}
		sort(s+1,s+1+m,cmp);
		now=1;
		while(sb>n/2)
		{
			while(now<=m)
			{
				if(vis[s[now].id]==2)
				{
					vis[s[now].id]=s[now].ty,ans+=s[now].s,--sb;
					break;
				}
				++now;
			}
		}
	}
	else if(sc>n/2)
	{
		for(int i=1;i<=n;++i)
		{
			if(vis[i]!=3) continue;
			s[++m].s=b[i]-c[i];s[m].id=i;s[m].ty=2;
			s[++m].s=a[i]-c[i];s[m].id=i;s[m].ty=1;
		}
		sort(s+1,s+1+m,cmp);
		now=1;
		while(sc>n/2)
		{
			while(now<=m)
			{
				if(vis[s[now].id]==3)
				{
					vis[s[now].id]=s[now].ty,ans+=s[now].s,--sc;
					break;
				}
				++now;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--) solve();
	return 0;
}
