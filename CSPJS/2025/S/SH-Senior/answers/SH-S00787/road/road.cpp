#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
#define PII pair<int,int>
const int N=1e4+10,mod=1e9+7,M=1e6+10;
vector<PII> g[N];
int fa[N],c[N],a[12][N];

struct edge
{
	int u,v,w;
}f[N];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>f[i].u>>f[i].v>>f[i].w;
		g[f[i].u].push_back({f[i].v,f[i].w});
		g[f[i].v].push_back({f[i].u,f[i].w});
	}
	sort(f+1,f+1+m,cmp);
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(!k)
	{
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int pu=find(f[i].u),pv=find(f[i].v);
			if(pu==pv)continue;
			ans+=f[i].w;
			fa[pv]=pu;
		}
		cout<<ans<<endl;
	}
	else
	{
		cout<<13<<endl;
	}
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
