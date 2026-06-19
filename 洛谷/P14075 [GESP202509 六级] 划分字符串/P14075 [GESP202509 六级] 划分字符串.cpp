#include<bits/stdc++.h>
using namespace std;
int n,dp[100001],a[100001];
char c[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0]=a[1];
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+a[1];
		set<char> ct;
		ct.insert(c[i]);
		for(int j=i-1;j>=0;j--)
		{
			if(ct.count(c[j])) break;
			ct.insert(c[j]);
			dp[i]=max(dp[i],(j==0?0:dp[j-1])+a[i-j+1]);
		}
	}
	cout<<dp[n-1];
	return 0;
}