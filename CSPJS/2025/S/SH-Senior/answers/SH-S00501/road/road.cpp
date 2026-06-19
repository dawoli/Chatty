#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,k;
struct node
{
	int u,v;
	long long w;
} e[2000005];
int f[100005];
int cur=0;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
long long ans=0;
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	f[find(x)]=find(y);
}
long long g[15][20005],val[15];
void work()
{
	ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
	}
	cout<<ans<<endl;
}
void work2()
{
	ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	cur=m;
	for(int i=n+1;i<=n+k;i++)
	{
		long long x;
		cin>>x;
		ans+=x;
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			e[++cur]=node{i,j,x};
		}
	}
	sort(e+1,e+cur+1,cmp);
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=cur;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
	}
	cout<<ans<<endl;
}
bool vis[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	if(k==0) work();
	else {
		work2();
	}
	return 0;
}
