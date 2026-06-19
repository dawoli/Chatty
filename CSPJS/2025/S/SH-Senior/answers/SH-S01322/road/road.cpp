#include<bits\stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans;
int f[10005],c[15],p[15],a[15][10005];
struct Node{int u,v,w;}e[2000005];
bool cmp(Node a,Node b){return a.w<b.w;}
void init()
{
	for(int i=1;i<=n;++i) f[i]=i;
}
int get(int i)
{
	if(f[i]==i) return f[i];
	else return f[i]=get(f[i]);
}
void conn(int u,int v)
{
	f[get(u)]=get(v);
}
bool isconn(int u,int v)
{
	return get(u)==get(v);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;++i) cin>>e[i].u>>e[i].v>>e[i].w;
	bool flag=1;
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		if(c[i]) flag=0;
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
			if(!a[i][j]) p[i]=j;
		}
	}
	
	if(k==0)
	{
		sort(e+1,e+m+1,cmp);
		int cnt=0;
		for(int i=1;i<=m;++i)
		{
			if(!isconn(e[i].u,e[i].v)) conn(e[i].u,e[i].v),cnt++,ans+=e[i].w;
			if(cnt==n-1) break;	
		}
		cout<<ans;
	}
	else if(flag)
	{
		int tmp=m;
		for(int i=1;i<=k;++i)
			for(int j=1;j<=n;++j)
			{
				if(j==p[i]) continue;
				e[++tmp].u=p[i],e[tmp].v=j,e[tmp].w=a[i][j];
			}
		sort(e+1,e+tmp+1,cmp);
		int cnt=0;
		for(int i=1;i<=m;++i)
		{
			if(!isconn(e[i].u,e[i].v)) conn(e[i].u,e[i].v),cnt++,ans+=e[i].w;
			if(cnt==n-1) break;	
		}
		cout<<ans;
	}
	return 0;
}
