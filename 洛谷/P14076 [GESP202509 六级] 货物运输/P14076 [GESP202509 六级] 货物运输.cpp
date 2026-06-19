#include <bits/stdc++.h>
using namespace std;
#define int long long
struct side
{
	int t,l;
};
int n,sum,mx;
vector<side> g[100005];
int dfs(int f,int x)
{
	int ms=0;
	for(auto e:g[x])
	{
		int v=e.t,len=e.l;
		if(v==f) continue;
		ms=max(ms,dfs(x,v)+len);
	}
	mx=max(mx,ms);
	return ms;
}
signed main()//把int define了要用signed代替int
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u,v,l;
		cin>>u>>v>>l;
		g[u].push_back({v,l});
		g[v].push_back({u,l});
		sum+=l;
	}
	dfs(-1,1);
	cout<<sum*2-mx;
	return 0;
}