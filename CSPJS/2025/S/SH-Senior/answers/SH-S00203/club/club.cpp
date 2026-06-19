# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> P;

const int N = 100010;
const int M = 210;
ll T, n, ans;
ll a[N][4], s[N];
ll cnt[4];
ll dp[2][M][M][M];
bool isA, isB;

void DFS(ll now, ll sum)
{
	if (now > n)
	{
		ans = max(ans, sum);
		return;
	}
	if (cnt[1] < n / 2) cnt[1]++, DFS(now + 1, sum + a[now][1]), cnt[1]--;
	if (cnt[2] < n / 2) cnt[2]++, DFS(now + 1, sum + a[now][2]), cnt[2]--;
	if (cnt[3] < n / 2) cnt[3]++, DFS(now + 1, sum + a[now][3]), cnt[3]--;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while (T--)
	{
		scanf("%lld", &n);
		isA = isB = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				scanf("%lld", &a[i][j]);
			}
			isA |= ((a[i][2] != 0) || (a[i][3] != 0)); 
		}
//		if (n <= 10) //20pts
//		{
//			cnt[1] = cnt[2] = cnt[3] = 0;
//			ans = 0;
//			DFS(1, 0);
//			printf("%lld\n", ans);
//			continue;
//		}
		if (!isA) //5pts
		{
			for (int i = 1; i <= n; i++) s[i] = a[i][1];
			sort(s + 1, s + n + 1, greater <ll> ());
			ll sum;
			sum = 0;
			for (int i = 1; i <= n / 2; i++) sum += s[i];
			printf("%lld\n", sum);
			continue;
		}
		memset(dp, 0, sizeof(dp));
		for (int p = 1; p <= n; p++)
		{
			for (int i = 0; i <= n / 2 && i <= p; i++)
			{
				for (int j = 0; j <= n / 2 && j <= p; j++)
				{
					ll k;
					k = p - i - j;
					if (k > n / 2) continue;
					if (i >= 1) dp[p & 1][i][j][k] = max(dp[p & 1][i][j][k], dp[(p & 1) ^ 1][i - 1][j][k] + a[p][1]);
					if (j >= 1) dp[p & 1][i][j][k] = max(dp[p & 1][i][j][k], dp[(p & 1) ^ 1][i][j - 1][k] + a[p][2]);
					if (k >= 1) dp[p & 1][i][j][k] = max(dp[p & 1][i][j][k], dp[(p & 1) ^ 1][i][j][k - 1] + a[p][3]);
//					cout<<p<<" "<<i <<" "<<j<<" "<<dp[p & 1][i][j][k]<<endl;
				}
			}
		}
		ans = 0;
		for (int i = 0; i <= n / 2; i++)
		{
			for (int j = 0; j <= n / 2; j++)
			{
				ll k;
				k = n - i - j;
				if (k > n / 2) continue;
				ans = max(ans, dp[n & 1][i][j][k]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
