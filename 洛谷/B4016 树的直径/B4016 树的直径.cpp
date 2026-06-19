#include<bits/stdc++.h>
using namespace std;
int n,mx,d[100001];
vector<int> t[100001];
void dfs(int u,int fa)
{
	for(int v:t[u])
	{
		if(v==fa) continue;
		d[v]=d[u]+1;
		if(d[v]>d[mx]) mx=v;
		dfs(v,u);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	dfs(1,0);
	d[mx]=0;
	dfs(mx,0);
	cout<<d[mx];
	return 0;
}