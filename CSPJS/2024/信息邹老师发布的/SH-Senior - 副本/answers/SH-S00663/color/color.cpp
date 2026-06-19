#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int dp[2][2][200010],a[200010];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		dp[0][1][1] = dp[0][0][1] = 0;
		bool now = 0;
		for(int i = 1;i < n;i++)
		{
			for(int j = 0;j < i;j++)
			{
				dp[!now][1][j] = max(dp[!now][1][j],dp[now][1][j] + a[i] * (a[i] == a[i + 1]));
				dp[!now][0][j] = max(dp[!now][0][j],dp[now][0][j] + a[i] * (a[i] == a[i + 1]));
				dp[!now][1][i] = max(dp[!now][1][i],dp[now][0][j] + a[j] * (a[j] == a[i + 1]));
				dp[!now][0][i] = max(dp[!now][0][i],dp[now][1][j] + a[j] * (a[j] == a[i + 1]));
			}
			memset(dp[now],0,sizeof(dp[now]));
			now = !now;
		}
		int ans = 0;
		for(int i = 1;i < n;i++) ans = max(ans,max(dp[now][1][i],dp[now][0][i]));
		cout << ans << endl;
		memset(dp[now],0,sizeof(dp[now]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
