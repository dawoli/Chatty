#include <bits/stdc++.h>
#define ui unsigned int
#define ull unsigned long long
#define ll long long
#define MXN 205
#define MMN 100005
ll t, n, a[MXN][4], b[MMN];
ll dp[MXN][MXN][MXN];
using namespace std;
void work(int i, int j, int k)
{
	ll nw = i + j + k;
	ll pos = 0;
	if(i)
		pos = max(pos, dp[i - 1][j][k] + a[nw][1]);
	if(j)
		pos = max(pos, dp[i][j - 1][k] + a[nw][2]);
	if(k)
		pos = max(pos, dp[i][j][k - 1] + a[nw][3]);
	dp[i][j][k] = pos;
}
bool cmp(int a, int b){return a > b;}
int main()
{
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while(t--)
	{
		memset(dp, 0, sizeof(dp));
		ll ans = 0;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++)
				scanf("%lld", &a[i][j]);
		if(n > 200)
		{
			for(int i = 1; i <= n; i++)
				b[i] = a[i][1];
			sort(b + 1, b + n + 1, cmp);
			for(int i = 1; i <= n / 2; i++)
				ans += b[i];
			printf("%lld\n", ans);
			continue;
		}
		for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
		for(int k = 0; k <= n; k++)
			if(i + j + k <= n && i + j + k)
				if(i <= n / 2 && j <= n / 2 && k <= n / 2)
					work(i, j, k);
		for(int i = 0; i <= n / 2; i++)
			for(int j = 0; j <= n / 2; j++)
				ans = max(ans, dp[i][j][n - i - j]);
		printf("%lld\n", ans);
	}
	return 0;
}
//the same person as SH-J00543 (LG UID: 1029108)
