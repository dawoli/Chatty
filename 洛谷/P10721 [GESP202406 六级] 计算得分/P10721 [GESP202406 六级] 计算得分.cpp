// Problem URL: https://www.luogu.com.cn/problem/P10721
// Finish Time: 2026/2/25 11:20:06 WA
// Start Time: 2026/2/25 09:49:54

// Categories: 动态规划
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[21],dp[100001/3],cnt=0,i=1;
char s[100001];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		s[i]=getchar();
	s[m+1]=' ';
	s[m+2]=' ';
	s[m+3]=' ';
	for(int i=1;i<=n;i++)
		for(int j=i;j<=m/3+5;j++)
			dp[j]=max(dp[j],dp[j-i]+a[i]);
	while(i<m)
	{
		if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
		{
			cnt++;
			i+=3;
		}
		else
		{
			ans+=dp[cnt];
			cnt=0;
			i++;
		}
	}
	if(cnt!=0) ans+=dp[cnt];
	cout<<ans;
	return 0;
}