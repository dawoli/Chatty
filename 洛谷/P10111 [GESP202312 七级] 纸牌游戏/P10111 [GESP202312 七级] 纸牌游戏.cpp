// Problem URL: https://www.luogu.com.cn/problem/P10111
// Start Time: 2026/3/7 19:04:19

// Categories: 动态规划
#include <bits/stdc++.h>
#define MAXN 1001
using namespace std;
typedef long long int ll;
int n,a[MAXN],b[MAXN],c[MAXN],dp[MAXN],ans=INT_MIN;
bool win(int x,int y)
{
	if(x==0) return y==2;
	if(x==1) return y==0;
	if(x==2) return y==1;
	return 0;
}
int change(int y)
{
	if(y==0)return 1;
	if(y==1)return 2;
	if(y==2)return 0;
	return -1;
}
void solve(int fst,int start,int t)
{
	int p=fst;
	for(int i=start;i<=n;i++)
	{
		int nch=0,ch;
		if(win(p,c[i]))nch=2*a[i];
		else if(p==c[i])nch=a[i];
		ch=2*a[i]-b[t+1];
		if(nch>ch)dp[i]=dp[i-1]+nch;
		else if(ch>nch)dp[i]=dp[i-1]+ch,t++,p=change(p);
		else
		{
			dp[i]=dp[i-1]+ch;
			solve(change(p),i+1,t+1);
			solve(p,i+1,t);
			return;
		}
	}
	ans=dp[n]>ans?dp[n]:ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	solve(0,1,0);
	solve(1,1,0);
	solve(2,1,0);
	cout<<ans;
	return 0;
}