#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[500005];
int s[500005];
int dp[500005];
map<int, int> pos;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	s[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] ^ a[i];
	}
	dp[0] = 0;
	pos.clear();
	pos[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		int need = s[i] ^ k;
		if (pos.count(need))
		{
			dp[i] = max(dp[i], dp[pos[need]] + 1);
		}
		pos[s[i]] = i;
	}
	printf("%d\n", dp[n]);
	return 0;
}
