// Problem URL: https://www.luogu.com.cn/problem/P1025
// Finish Time: 2026/4/4 17:12:19 AC
// Start Time: 2026/4/4 16:54:11

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,k,ans=0;
void dfs(int sum,int m,int l)
{
	if(m<k&&sum>=n) return;
	if(m==k)
	{
		if(sum==n)ans++;
		return;
	}
	for(int i=l;i<=n;i++)
	{
		if(i>n-sum||n-sum-i!=0&&n-sum-i<i)continue;
		dfs(sum+i,m+1,i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	dfs(0,0,1);
	cout<<ans;
	return 0;
}