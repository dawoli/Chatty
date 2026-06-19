#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define mod 998244353
int dp[5010],a[5010];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	dp[0] = 1;
	sort(a + 1,a + n + 1);
	int m = a[n] + 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = a[i] + 1;j <= m;j++) (ans += dp[j]) %= mod;
		for(int j = m;j >= 0;j--)
		{
			if(j + a[i] >= m) (dp[m] += dp[j]) %= mod;
			else (dp[j + a[i]] += dp[j]) %= mod;
  		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
