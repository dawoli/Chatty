// Problem URL: https://www.luogu.com.cn/problem/P15801
// Start Time: 2026/3/21 18:17:08

#include <bits/stdc++.h>
#define p first
#define h second
using namespace std;
typedef long long int ll;
int n,ans=0,t[100005][2];
pair<int,int> dfs(int u,int h)
{
	if(u==0) return {1,h-1};
	if(t[u][0]==0&&t[u][1]==0)
	{
		ans++;
		return {3,h};
	}
	auto l=dfs(t[u][0],h+1);
	auto r=dfs(t[u][1],h+1);
	if(l.p==3&&r.p==3&&l.h==r.h)
	{
		ans++;
		return {3,h};
	}
	if(l.p==3&&r.p==2&&l.h==r.h)
	{
		ans++;
		return {2,h};
	}
	if((l.p==2||l.p==3)&&r.p==3&&l.h==r.h+1)
	{
		ans++;
		return {2,h};
	}
	return {0,h};
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>t[i][0]>>t[i][1];
	dfs(1,1);
	cout<<ans;
	return 0;
}