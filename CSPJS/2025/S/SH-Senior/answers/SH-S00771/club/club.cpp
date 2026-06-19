#include <bits/stdc++.h>
using namespace std;
int n;
long long aa, bb, cc;
long long ans = 0;
struct node
{
	int a, b, c;
}x[100010];
long long dp[210][210][210];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while(T --)
	{
		memset(dp, 0, sizeof(dp));
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i ++)
			cin >> x[i].a >> x[i].b >> x[i].c;
		for(int l = 1;l <= n;l ++)
		{
			for(int i = n / 2;i >= 0;i --)
			{
				for(int j = n / 2;j >= 0;j --)
				{
					for(int k = n / 2;k >= 0;k --)
					{
						aa = 0, bb = 0, cc = 0;
						if(i - 1 >= 0)
							aa = dp[i - 1][j][k] + x[l].a;
						if(j - 1 >= 0)
							bb = dp[i][j - 1][k] + x[l].b;
						if(k - 1 >= 0)
							cc = dp[i][j][k - 1] + x[l].c;
						dp[i][j][k] = max(max(dp[i][j][k], aa), max(bb, cc));
						ans = max(ans, dp[i][j][k]);
					}				
				}			
			}	
		}
		cout << ans << endl;
	}
	
	return 0;
}
