#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1010, M = 200010;
int n, k, q, mp[M], x[M], l1[N], s[N][N*2], sum[12][N*2]; bool dp[12][N][N*2];
void solve()
{
	int tot = 0; memset(mp, 0, sizeof(mp));
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &l1[i]);
		for (int j = 1; j <= l1[i]; j++)
		{
			scanf("%d", &s[i][j]);
			if (!mp[s[i][j]]) mp[s[i][j]] = ++tot, x[tot] = s[i][j];
		}
	} memset(dp, 0, sizeof(dp)), memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) dp[0][i][1] = 1, sum[0][1]++;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int cnt = 0;
			for (int l = 2; l <= l1[j]; l++)
			{
				if (l > k) cnt -= sum[i-1][mp[s[j][l-k]]] - dp[i-1][j][mp[s[j][l-k]]];
				cnt += sum[i-1][mp[s[j][l-1]]] - dp[i-1][j][mp[s[j][l-1]]];
				if (cnt > 0) dp[i][j][mp[s[j][l]]] = 1, sum[i][mp[s[j][l]]]++;
//				printf("%lld %lld %lld %lld\n", i, j, mp[s[j][l]], dp[i][j][mp[s[j][l]]]);
			}
		}
	}
	while (q--)
	{
		int r, c; scanf("%d%d", &r, &c);
		int flag = 0;
		for (int i = 1; i <= n; i++) flag |= dp[r][i][mp[c]];
		printf("%d\n", flag);
	}
}

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	ll T; scanf("%lld", &T);
	while (T--) solve();
	return 0;
}
/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
2 4
3 4
6 6
1 1
7 7

*/
