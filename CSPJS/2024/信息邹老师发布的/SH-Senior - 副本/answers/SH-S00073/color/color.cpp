#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, a[N], b[N], c[N], v[N];
long long sum = 0;
void dfs(int p)
{
	if (p > n)
	{
		long long ans = 0;
		for (int i = 2; i <= n; i++)
		{
			if (v[i] != v[i - 1])
			{
				for (int j = i - 1; j >= 1; j--)
				{
					if (v[i] == v[j])
					{
						if (a[i] == a[j]) ans += a[i];
					}
				}
			}
		}
		sum = max(sum, ans);
		return ;
	}
	if (b[a[p]] > 1)
	{
		dfs(p + 1);
		return ;
	}
	v[p] = 0;
	dfs(p + 1);
	v[p] = 1;
	dfs(p + 1); 
}
void solve()
{
	sum = 0;
	memset(v, -1, sizeof(v));
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, -1, sizeof(c));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[a[i]]++; 
	}
	if (n <= 15)
	{
		dfs(1);
		printf("%lld\n", sum);
		return ;
	}
	int pos = 1;
	for (int i = 1; i <= n; i++)
	{
		if (c[a[i]] != -1)
		{
			v[i] = c[a[i]];
			continue;
		}
		if (b[a[i]] >= 2)
		{
			v[i] = pos;
			c[a[i]] = pos;
			pos = (pos + 1) % 2;
			continue;
		}
	}
	dfs(1);
	printf("%lld\n", sum);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}
