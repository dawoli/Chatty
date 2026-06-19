#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,c[100001];
vector<vector<int> > t;
int dfs(int u)
{
	if(t[u].empty())return c[u];
	if(t[u].size()==1&&t[t[u][0]].empty())return min(c[u],c[t[u][0]]);
	int ans=c[u];
	int ans2=0;
	for(auto i:t[u])
	{
		ans2+=dfs(i);
		if(ans2>ans)return ans;
	}
	return ans2;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	t.resize(n+1);
	for(int i=2;i<=n;i++)
	{
		int fa;
		cin>>fa;
		t[fa].push_back(i);
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	cout<<dfs(1);
	return 0;
}