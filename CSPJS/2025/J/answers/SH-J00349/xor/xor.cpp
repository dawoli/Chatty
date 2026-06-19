#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
int n,k; 
int a[N],dp[N];
int solve(int u,int v)
{
	int x=a[u],ct=0;
	for(int i=u+1;i<=v;i++)
	{
		if(x==k)
		{
			ct++;
			x=0;
		}
		x^=a[i];
	}
	if(x==k)ct++;
	return ct;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(int j=1;j<=i-1;j++)
		{
			dp[i]=max(dp[i],dp[j]+solve(j,i));
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}//#Shang4Shan3Ruo6Shui4

