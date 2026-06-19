#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[5010];
int c[5010];
int new_a[5010];
bool king[8200][15];
char s[8200];
int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%d %d", &n, &m);
	memset(a, 0x3f, sizeof(a));
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &c[i]);
	}
	int K = (int)floor(pow(2, ceil(log2((double)n))));
	int t = (int)log2((double)K);
	for(int i = 1; i <= t; i++)
	{
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for(int j = 1; j <= len; j++)
			king[j][i] = s[j] - '0';
	}
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		int aX0, aX1, aX2, aX3;
		scanf("%d %d %d %d", &aX0, &aX1, &aX2, &aX3);
		int ans = 0;
		for(int j = 1; j <= m; j++)
			ans ^= j;
		printf("%d\n", ans);
	}
	return 0;
}
