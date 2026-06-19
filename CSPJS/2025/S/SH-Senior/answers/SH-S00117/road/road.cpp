#include <bits/stdc++.h>
using namespace std;

const int N=1e4+7,M=1e4+1e6+7,K=17;

struct Edge
{
	int u,v,w;
	bool operator<(const Edge &B) const
	{
		return w<B.w;
	}
};

int n,m,k;
Edge e[M],e2[M];
int f[N];
int a[K][N];
int c[K];

int find(int x)
{
	if (f[x]==x)
		return x;
	f[x]=find(f[x]);
	return f[x];
}

long long cost(int x)
{
	long long ret=1LL*c[x];
	for (int i=1;i<=n+1;i++)
		f[i]=i;
	for (int i=1;i<=n;i++)
		e2[m+i]={i,n+1,a[x][i]};
	sort(e2+1,e2+m+n+1);
	int i=0,cnt=0;
	
	while (cnt<n&&i<m+n)
	{
		i++;
		int u=e2[i].u;
		int v=e2[i].v;
		int w=e2[i].w;
		if (find(u)==find(v))
			continue;
		f[find(u)]=find(v),cnt++,ret+=w;
	}
	if (cnt<n)
		return 9e18;
	return ret;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	long long ans=0;
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++)
		f[i]=i;
	for (int i=1;i<=m;i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i=1;i<=m;i++)
		e2[i]={e[i].u,e[i].v,e[i].w};
	for (int i=1;i<=k;i++)
	{
		cin >> c[i];
		for (int j=1;j<=n;j++)
			cin >> a[i][j];
	}

	sort(e+1,e+m+1);
	int i=0,cnt=0;
	while (cnt<n-1&&i<m)
	{
		i++;
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		if (find(u)==find(v))
			continue;
		f[find(u)]=find(v),ans+=w;
		cnt++;
	}
	if (cnt<n-1)
		ans=9e18;
	for (int i=1;i<=k;i++)
		ans=min(ans,cost(i));
	cout << ans << endl;
	return 0;
}
