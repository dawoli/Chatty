#include <bits/stdc++.h>
using namespace std;
int a[2005], prevv[2005], n;
bool color[2005];
int dp[2005][2005];
int dp2[2005][2005];
int main ()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ii++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			bool f = 0;
			for (int j = i-1; j >= 1; j--)
			{
				if (a[j] == a[i])
				{
					prevv[i] = j;
					f = 1;
					break;
				}
			}
			if (f==0) prevv[i] = -1;		
		}
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		for (int k = 1; k <= n-1; k++)
		{
			for (int i = 1; i <= n-k; i++)
			{
				if (k==1)
				{
					if (a[i] == a[i+k]) dp2[i][i+k] = a[i];
				}
				else
				{
					int cnt = 0;
					for (int j = i; j <= n-k-1; j++)
					{
						cnt+=dp2[j][j+1];
					}
					dp2[i][i+k] = cnt;
				}
			}
		}
		for (int k = 1; k <= n-1; k++)
		{
			for (int i = 1; i <= n-k; i++)
			{
				int j = i+k;
				if (k==1)
				{
					if (a[i] == a[j]) dp[i][j] = a[i];
				}
				else if (k == 2)
				{
					if (a[i] == a[j]) dp[i][j] = a[i];
					else if (a[i] == a[i+1]) dp[i][j] = a[i];
					else if (a[i+1] == a[j]) dp[i][j] = a[i+1];
				}
				else
				{
					if (prevv[j] < i || dp[i+1][j] == a[j]+dp[i+1][j>0 ? prevv[j-1]:0] || dp[i][j-1] == a[j-1]+dp[i][j>0 ? prevv[j-1] : 0]) dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]/*max(dp[i+1][j], dp[i][j-1])*/;
					else dp[i][j] = max(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1], max(dp[prevv[j]+1][j-1], a[j]+dp2[prevv[j]+1][j-1])+dp[i][j>0 ? prevv[j-1] : 0]);
				}
			}			
		}
		cout << dp[1][n] << endl;
		//0~4pts
	}
	return 0;
}
