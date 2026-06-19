#include <bits/stdc++.h> 
using namespace std;
#define ll long long

ll dp[205][205][205];
ll arr[100005][4], n, ans = 0;
vector<ll> v;

void dfs(ll dep, ll cho1, ll cho2, ll cho3, ll summ)
{
	if (dep == n + 1)
	{
		ans = max(ans, summ);
		return;
	}
	if (cho1 < n / 2)dfs(dep + 1, cho1 + 1, cho2, cho3, summ + arr[dep][1]);
	if (cho2 < n / 2)dfs(dep + 1, cho1, cho2 + 1, cho3, summ + arr[dep][2]);
	if (cho3 < n / 2)dfs(dep + 1, cho1, cho2, cho3 + 1, summ + arr[dep][3]);
	return;
}


void solve()
{
	ans = 0;
	cin >> n;
	for (int i = 1 ; i <= n; i++)
	{
		cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
		v.push_back(arr[i][1]);
	}
	if (n <= 10) dfs(1, 0, 0, 0, 0);
	else if (n <= 200)
	{
		memset(dp, 0, sizeof dp);
		for (ll t = 1; t <= n; t++)
		{
			for (ll i = 0; i <= min(t, n / 2); i++)
			{
				for (ll j = 0; j <= min(t, n / 2); j++)
				{
					for (ll k = 0; k <= min(t, n / 2); k++)
					{
						if (i + j + k == t)
						{
							if (i != 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + arr[t][1]);
							if (j != 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + arr[t][2]);
							if (k != 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + arr[t][3]);
							ans = max(ans, dp[i][j][k]);
						}
					}
				}
			}
		}
	}
	else
	{
		sort(v.begin(), v.end());
		for (int i = n / 2 + 1; i <= n; i++)
		{
			ans += v[i];
		}
	}
	cout << ans << endl;
	return;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
