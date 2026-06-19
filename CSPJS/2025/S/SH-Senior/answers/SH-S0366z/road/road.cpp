#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=1e4+5,M=1e6+5;
typedef long long ll;
struct node{
	ll u,v,w;
	bool operator<(const node &b)const
	{
		return w<b.w;
	}
};
vector<node>e;
int f[N+15];
int find(int x)
{
	if(f[x]!=x) return f[x]=find(f[x]);
	return x;
}
void merge(int x,int y)
{
	f[find(x)]=find(y);
}
ll a[15][N];
ll u[M],v[M],w[M];
int c[15],b[15];
ll ans=2e18;
int n,m,k;
void solve()
{
	e.clear();
	ll sum=0;
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		e.push_back({u[i],v[i],w[i]});
	}
	for(int i=1;i<=k;i++)
	{
		if(b[i])
		{
			sum+=c[i];
			for(int j=1;j<=n;j++)
			{
				e.push_back({i+n,j,a[i][j]});
			}
		}
	}
	sort(e.begin(),e.end());
	for(int i=0;i<e.size();i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			sum+=e[i].w;
			merge(e[i].u,e[i].v);
			//cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
		}
	}
//	for(int i=1;i<=k;i++) cout<<b[i]<<" ";
//	cout<<endl<<sum<<endl;
	ans=min(ans,sum);
}
void dfs(int x)
{
	if(x>k)
	{
		solve();
		return;
	}
	dfs(x+1);
	b[x]=1;
	dfs(x+1);
	b[x]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	bool flag=true;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]) flag=false;
		for(int j=1;j<=n;j++) 
		{
			cin>>a[i][j];
		}
	}
	if(flag)
	{
		for(int i=1;i<=k;i++) b[i]=1;
		solve();
	}
	else dfs(1);
	cout<<ans<<endl;
	return 0;
}

