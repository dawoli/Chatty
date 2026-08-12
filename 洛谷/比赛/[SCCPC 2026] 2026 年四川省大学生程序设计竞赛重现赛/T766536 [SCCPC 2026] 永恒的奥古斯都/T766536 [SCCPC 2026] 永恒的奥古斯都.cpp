// Problem URL: https://www.luogu.com.cn/problem/T766536?contestId=330334
// Start Time: 2026/6/21 15:43:37

#include <bits/stdc++.h>
#define MOD 998244353
#define MAXN 200005
using namespace std;
int n,c[MAXN],fa[MAXN];
vector<int> g[MAXN],a;
long long p0[MAXN],p1[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n;++i)
	{
		cin>>c[i];
		p0[i]=p1[i]=1;
	}
	for(int i=1; i<n;++i)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	fa[1]=0;
	a.push_back(1);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int v:g[u])
		{
			if(v==fa[u]) continue;
			fa[v]=u;
			a.push_back(v);
			q.push(v);
		}
	}
	for(int i=n-1;i>=0;--i)
	{
		int u=a[i];
		long long dp0_u,dp1_u;
		if(c[u]==1)
		{
			dp0_u=(p0[u]+p1[u])%MOD;
		}
		else
		{
			dp0_u=p0[u];
		}
		dp1_u=(2*p1[u])%MOD;
		if(u!=1)
		{
			int p=fa[u];
			p0[p]=(p0[p]*dp0_u)%MOD;
			p1[p]=(p1[p]*dp1_u)%MOD;
		}
		else
		{
			cout<<dp0_u<<'\n';
		}
	}
	return 0;
}