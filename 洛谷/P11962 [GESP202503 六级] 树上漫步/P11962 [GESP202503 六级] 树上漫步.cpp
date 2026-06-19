#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a[200001];
bitset<200001> f;
int s=0;
void dfs(int u,int fa)
{
	for(int i=0;i<a[u].size();i++)
		if(a[u][i]!=fa)
		{
			f[a[u][i]]=!f[u];
			if(f[a[u][i]])s++;
			dfs(a[u][i],u);
		}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(f[i])cout<<s<<' ';
		else cout<<n-s<<' ';
	return 0;
}