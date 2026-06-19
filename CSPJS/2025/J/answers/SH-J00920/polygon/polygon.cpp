#include <cstdio>
#include <algorithm>

const int MOD = 998244353;

int n, cnt = 0;
int a[5010];

bool is_special = true;

void dfs(int tot, int maxx, int lst, int stick)
{
	if (stick >= 3 && tot > 2 * maxx)
	{
		cnt++;
		if (cnt >= MOD)
			cnt -= MOD;
	}
	for (int i = lst + 1; i <= n; ++i)
		dfs(tot + a[i], a[i], i, stick + 1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if (a[i] != 1)
			is_special = false;
	}
	if (is_special)
	{
		long long tmp = n * (n - 1) * (n - 2)) / 6;
		printf("%d", (tmp % MOD);
		return 0;
	}
	std::sort(a + 1, a + n + 1);
	dfs(0, 0, 0, 0);
	printf("%d", cnt);
	return 0;
}

