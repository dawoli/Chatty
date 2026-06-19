#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
struct edge
{
	int u,v,w;
	bool operator <(edge x) const
	{
		return w<x.w;
	}
}e0[1100001],e[11001];
int n,m,k,c[11],a[10011],s[10011];
int gb(int x,int b){return (x>>(b-1))&1;}
int find(int x)
{
	if(a[x]==x)return x;
	return a[x]=find(a[x]);
}
void U(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return;
	if(s[x]>s[y])swap(x,y);
	s[y]+=s[x];
	a[x]=y;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e0[i].u>>e0[i].v>>e0[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>e0[m+(i-1)*n+j].w;
			e0[m+(i-1)*n+j].u=n+i;
			e0[m+(i-1)*n+j].v=j;
		}
	}
	sort(e0+1,e0+m+n*k+1);
	int ans=1e18,sum0=0,cur=0;
	for(int j=1;j<=n+k;j++)
	{
		a[j]=j;
		s[j]=1;
	}
	for(int i=1;i<=m+n*k;i++)
	{
		if(e0[i].u>n)goto flag;
		if(find(e0[i].u)==find(e0[i].v))continue;
		sum0+=e0[i].w;
		U(e0[i].u,e0[i].v);
		flag:
		e[++cur]=e0[i];
	}
	ans=min(ans,sum0);
	sort(e0+1,e0+cur+1);
	for(int i=1;i<(1<<k);i++)
	{
		int sum=0;
		for(int j=1;j<=k;j++)
		{
			if(gb(i,j))sum+=c[j];
		}
		for(int j=1;j<=n+k;j++)
		{
			a[j]=j;
			s[j]=1;
		}
		for(int j=1;j<=cur;j++)
		{
			if(e[j].u>n)
			{
				if(!gb(i,e[j].u-n))continue;
			}
			if(find(e[j].u)==find(e[j].v))continue;
			sum+=e[j].w;
			U(e[j].u,e[j].v);
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
}