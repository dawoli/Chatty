#include <bits/stdc++.h>
using namespace std;

// RTF 原始注释中包含转义字节（已保留原始转义序列）
// n: ...
// a[i]: ...
// b[i]: ...
// c[i]: ...
// sum[i]: ...
// dp[i][j][k]: ...

long long n,a[1005],b[1005],c[1005],sum[1005],dp[1005][3][1005]={},ans=0;

int main()
{
	// 初始化
	sum[0]=0;
	// 读取 n
	cin>>n;

	// 读取 a[i]
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}

	// 读取 b[i] 并计算前缀和 sum
	for(int i=1; i<=n-1; i++)
	{
		cin>>b[i];
		sum[i]=sum[i-1]+b[i]; // sum[i] = b[1]+b[2]+...+b[i]
	}

	// 读取 c[i]
	for(int i=1; i<=n; i++)
	{
		cin>>c[i];
	}

	// 动态规划
	for(int i=1; i<=n; i++)
	{
		for(int k=0; k<i; k++)
		{
			if(c[i]==0)
			{
				dp[i][0][k]=max(max(dp[i-1][0][k],dp[i-1][1][k-1]),dp[i-1][2][k-1])+a[i];
				dp[i][1][k]=max(max(dp[i-1][0][k-1],dp[i-1][1][k]),dp[i-1][2][k-1])+2*a[i];
				dp[i][2][k]=max(max(dp[i-1][0][k-1],dp[i-1][1][k-1]),dp[i-1][2][k]);
			}
			else if(c[i]==1)
			{
				dp[i][0][k]=max(max(dp[i-1][0][k],dp[i-1][1][k-1]),dp[i-1][2][k-1]);
				dp[i][1][k]=max(max(dp[i-1][0][k-1],dp[i-1][1][k]),dp[i-1][2][k-1])+a[i];
				dp[i][2][k]=max(max(dp[i-1][0][k-1],dp[i-1][1][k-1]),dp[i-1][2][k])+2*a[i];
			}
			else
			{
				dp[i][0][k]=max(max(dp[i-1][0][k],dp[i-1][1][k-1]),dp[i-1][2][k-1])+2*a[i];
				dp[i][1][k]=max(max(dp[i-1][0][k-1],dp[i-1][1][k]),dp[i-1][2][k-1]);
				dp[i][2][k]=max(max(dp[i-1][0][k-1],dp[i-1][1][k-1]),dp[i-1][2][k])+a[i];
			}
		}
	}

	for(int k=0; k<=n-1; k++)
	{
		ans=max(ans,max(dp[n][0][k],max(dp[n][1][k],dp[n][2][k]))-sum[k]);
	}

	cout<<ans<<endl;
	return 0;
}
