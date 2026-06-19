#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 10010
#define M 2000010
#define T 20
struct stu
{
	int u,v,w,ww;
};
stu p[M];
bool cmp(stu x,stu y)
{
	return x.w<y.w;
}
int m,fa[N];
void init(int n)
{
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int u)
{
	if(fa[u]==u) return u;
	else return fa[u]=find(fa[u]);
}
int mst(int n)
{
	init(n);
	sort(p+1,p+m+1,cmp);
	int c=0,t=0;
	for(int i=1;i<=m;i++)
	{
		int u=p[i].u,v=p[i].v,w=p[i].w;
		u=find(u);
		v=find(v);
		if(u==v) continue;
		fa[u]=v;
		c++;
		t+=w;
		if(c==n-1) return t;
	}
}
int cc[T],dd[T];
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,t,fl=0;
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++) cin>>p[i].u>>p[i].v>>p[i].w;
	for(int i=1;i<=t;i++)
	{
		cin>>cc[i];
		if(cc[i]!=0) fl=1;
		for(int j=1;j<=n;j++)
		{
			p[++m].u=i+n;
			p[m].v=j;
			cin>>p[m].w;
			p[m].ww=p[m].w;
		}
	}
	int ans=1e16,lim=0;
	if(fl==0) lim=(1<<t)-1;
	for(int i=lim;i<=(1<<t)-1;i++)
	{
		memset(dd,0,sizeof(dd));
		int cur=0,nd=0;
		for(int j=1;j<=t;j++)
		{
			if(i&(1<<(j-1)))
			{
				cur+=cc[j];
				dd[j]=1;
				nd++;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(p[j].u<=n) continue;
			if(dd[p[j].u-n]==0) p[j].w=1e16;
			else p[j].w=p[j].ww;
		}
		ans=min(ans,cur+mst(n+nd));
	}
	cout<<ans;
	return 0;
}

