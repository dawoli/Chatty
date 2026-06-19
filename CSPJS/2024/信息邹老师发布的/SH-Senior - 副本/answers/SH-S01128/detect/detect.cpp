#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1e5+2;
int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
struct node
{
	int l,r;
	friend bool operator < (node a,node b)
	{
		return a.r==b.r?a.l<b.l:a.r<b.r;
	}
}b[N];
int n,m,cnt,L,V,d[N],v[N],a[N],p[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read(),m=read(),L=read(),V=read();
		for(int i=1;i<=n;i++)
			d[i]=read(),v[i]=read(),a[i]=read();
		for(int i=1;i<=m;i++)
			p[i]=read();
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(v[i]<=V)
					continue;
				int tl=lower_bound(p+1,p+1+m,d[i])-p;
				if(tl==m+1)
					continue;
				b[++cnt]={tl,m};
			}
			if(a[i]>0)
			{
				int pl=d[i];
				if(v[i]<=V)
					pl+=(V*V-v[i]*v[i])/(2*a[i])+1;
				int tl=lower_bound(p+1,p+1+m,pl)-p;
				if(tl==m+1)
					continue;
				b[++cnt]={tl,m};
			}
			if(a[i]<0)
			{
				if(v[i]<=V)
					continue;
				int pr=d[i]+(V*V-v[i]*v[i])/(2*a[i])+1;
				int tl=lower_bound(p+1,p+1+m,d[i])-p,tr=lower_bound(p+1,p+1+m,pr)-p-1;
				if(tl>tr)
					continue;
				b[++cnt]={tl,tr};
			}
		}
		sort(b+1,b+1+cnt);
		int now=0,ans=m;
		for(int i=1;i<=cnt;i++)
			if(b[i].l>now)
				ans--,now=b[i].r;
		printf("%d %d\n",cnt,ans);
	}
}
