#include <bits/stdc++.h>

using namespace std;

int ans = 0, b[200010], a[200010], n;

void dfs(int d)
{
	if (d == n + 1)
	{
		int cnt = 0;
		for (int i = 2; i <= n; i ++ )
		{
			for (int j = 1; j <= i - 1; j ++ )
			{
				if (b[j] == b[i] && a[j] == a[i])
				{
					cnt += a[i];
				}
			}
		}
		ans = max(ans,cnt);
		return;
	}
	b[d] = 0;
	dfs(d + 1);
	b[d] = 1;
	dfs(d + 1);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t -- )
	{
		memset(b, 0, sizeof b);
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%d", &a[i]);
		} 
		ans = 0;
		dfs(1);
		printf("%d\n", ans);
	}
	
	return 0;
}
