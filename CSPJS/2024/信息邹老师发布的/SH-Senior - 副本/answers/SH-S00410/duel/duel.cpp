#include<bits/stdc++.h>
using namespace std;
long long mon[100010],dp[100010];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>mon[i];
		dp[mon[i]]++;
	}
	for(int i=1;i<100010;i++)
	{
		dp[i]=max(dp[i-1],dp[i]);
	}
	cout<<dp[100009];
	return 0;
}
