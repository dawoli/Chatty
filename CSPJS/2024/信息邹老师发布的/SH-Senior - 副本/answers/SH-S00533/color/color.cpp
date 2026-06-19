#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 2005,M = 1e5 + 5;
int t,n,a[M],dp[N][N][2],f[N][2],g[N];
map<int,int> mp;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while (t--)
	{
		memset(f,0,sizeof(f));
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		f[1][0] = f[1][1] = 0;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j < i; j++)
			{
				if (j == 1)
				{
					dp[i][j][0] = f[i - 1][1] + (a[i] == a[i - 1]? a[i]:0);
					dp[i][j][1] = f[i - 1][1] + (a[i] == a[i - 2]? a[i]:0);
				}
				else
				{
					dp[i][j][0] = dp[i - 1][j - 1][0] + (a[i] == a[i - 1]? a[i]:0);
					dp[i][j][1] = dp[i - 1][j - 1][0] + (a[i] == a[i - j - 1]? a[i]:0);
				}
				f[i][0] = max(f[i][0],dp[i][j][0]);
				f[i][1] = max(f[i][1],dp[i][j][1]);
//					cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
			}
		cout << max(f[n][0],f[n][1]) << endl; 
	}
	return 0;
}

