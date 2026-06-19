#include <bits/stdc++.h>
using namespace std;
int yh[1005][1005];
int a[500005];
int sum[500005];
int dp[500005];
struct node
{
	int l,r;
} qj[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cur=0;
	for (int i=1;i<=n;i++)	{cin>>a[i];sum[i]=sum[i-1]^a[i];}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			yh[i][j]=sum[j]^sum[i-1];
			if (yh[i][j]==k)
			{
				node temp;
				temp.l=i;
				temp.r=j;
				qj[++cur]=temp;
			}
		}
	}
	for (int i=1;i<=cur;i++)
	{
		dp[qj[i].r]=max(dp[qj[i].l-1]+1,dp[qj[i].r]);
		for (int j=1;j<=n;j++)	dp[j]=max(dp[j],dp[j-1]);
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}

