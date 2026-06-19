#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long a[5005], n, cnt[5005], dp[5005], ans;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	memset(cnt, 0, sizeof cnt);
	memset(dp, 0, sizeof dp);
	cnt[a[1] + a[2]] = 1;
	for(int i = 3; i <= n; i++)
	{
		for(int j = 5001; j >= 1; j--)
		{
			dp[j] = cnt[j] + cnt[j+1];
		}
		ans = (ans + dp[a[i]+1]) % mod;
		for(int j = 1; j <= 5001; j++)
		{
			long long tmp = j + a[i];
			if(cnt[j] != 0 && tmp <= 5000)
			{
				cnt[tmp] += cnt[j];
				cnt[tmp] %= mod;
			}
			else if(cnt[j] != 0 && tmp > 5000)
			{
				cnt[5001] += cnt[j];
				cnt[5001] %= mod;
			}
		}
		for(int j = 1; j < i; j++)
		{
			long long tmp = a[j] + a[i];
			if(tmp <= 5000)
			{
				cnt[tmp]+=1;
				cnt[tmp] %= mod;
			}
			else
			{
				cnt[5001]+=1;
				cnt[5001] %= mod;
			}
		}
	}
	cout << ans % mod;
	return 0;
}
