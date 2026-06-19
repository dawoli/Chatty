// Problem URL: https://www.luogu.com.cn/problem/P10111
// Finish Time: 2026/3/14 17:33:37 AC
// Start Time: 2026/3/7 19:04:19

// Categories: 动态规划
#include <bits/stdc++.h>
#define MAXN 1001
using namespace std;
typedef long long int ll;
int n,a[MAXN],b[MAXN],c[MAXN],s[MAXN],dp[MAXN][3][MAXN],ans;
int play(int x,int y)
{
	if(x==0) return y==2?2:y==0?1:0;
	if(x==1) return y==0?2:y==1?1:0;
	if(x==2) return y==1?2:y==2?1:0;
	return 0;
}
void work(int i,int k,int c)
{
	dp[i][0][k]=max(max(dp[i-1][0][k],dp[i-1][1][k-1]),dp[i-1][2][k-1])+play(0,c)*a[i];
	dp[i][1][k]=max(max(dp[i-1][0][k-1],dp[i-1][1][k]),dp[i-1][2][k-1])+play(1,c)*a[i];
	dp[i][2][k]=max(max(dp[i-1][0][k-1],dp[i-1][1][k-1]),dp[i-1][2][k])+play(2,c)*a[i];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<n;i++) s[i]=s[i-1]+b[i];
	for(int i=1;i<=n;i++)
	{
		ans=INT_MIN;
		for(int k=0;k<i;k++)
		{
			work(i,k,c[i]);
			ans=max(ans,max(dp[i][0][k],max(dp[i][1][k],dp[i][2][k]))-s[k]);
		}
	}
	cout<<ans;
	return 0;
}