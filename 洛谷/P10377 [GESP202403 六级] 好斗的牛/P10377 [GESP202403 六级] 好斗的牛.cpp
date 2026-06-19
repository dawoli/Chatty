// Problem URL: https://www.luogu.com.cn/problem/P10377
// Finish Time: 2026/2/27 13:15:16 AC
// Start Time: 2026/2/27 12:40:13

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,a[10],b[10],ans=INT_MAX;
bitset<10> vis;
void dfs(int x,int d,int f)
{
	if(x>=n)
	{
		ans=min(ans,d);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(x==0)dfs(x+1,1,i);
		else dfs(x+1,d+max(a[i],b[f])+1,i);
		vis[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}