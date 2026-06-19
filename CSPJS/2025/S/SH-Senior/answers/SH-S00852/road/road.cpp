#include <bits/stdc++.h>
using namespace std;
#define N 10020
int n,m,k;
long long ans=LLONG_MAX;
struct edge
{
	int u,v,w;
}a[1000001];
int c[11],d[11][N],r[11],s[11];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
bool cmp2(int x,int y)
{
	if(c[x]!=c[y]) return c[x]<c[y];
	return s[x]<s[y];
}
int fa[N];
int find(int x)
{
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
void kruskal(int x)
{
	memset(fa,0,sizeof fa);
	int cnt=0;
	vector<edge>e;
	bool v[k+1];
	for(int i=0;i<k;i++)
	{
		v[r[i+1]]=x&(1<<i);
		cnt++;
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++) e.push_back(a[i]);
	for(int i=1;i<=k;i++)
	{
		if(v[i])
		{
			sum+=c[i];
			for(int j=1;j<=n;j++) e.push_back({j,n+i,d[i][j]});
			fa[n+i]=n+i;
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<e.size();i++)
	{
		int f1=find(e[i].u);
		int f2=find(e[i].v);
		if(f1!=f2)
		{
			fa[f1]=f2;
			sum+=e[i].w;
		}
	}
	ans=min(ans,sum);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
			s[i]+=d[i][j]; 
		}
		r[i]=i;
	}
	kruskal(0);
	sort(r+1,r+1+k,cmp2);
	if(k==0)
	{
		cout<<ans;
		return 0;
	}
	for(int i=0;i<k;i++)
	{
		long long s=ans;
		for(int j=1;j<(1<<i);j++)
		{
			kruskal(j);
		}
		if(s==ans) break;
	}
	cout<<ans;
	return 0;
}
