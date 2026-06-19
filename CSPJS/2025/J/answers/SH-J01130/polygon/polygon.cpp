#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 7, mod = 998244353;
int dp[N * N], a[N], n, mx, ans;
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mx = max(mx, a[i]);
	sort(a + 1, a + n + 1); 
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for(int j = mx * n;j >= a[i]; j--)
		{
			(dp[j] += dp[j - a[i]]) %= mod;
			if(j > a[i] * 2)
				(ans += dp[j - a[i]]) %= mod; 
		}
	cout << ans;
	return 0;
} 
// ÉÙÓðÅ£±Æ
