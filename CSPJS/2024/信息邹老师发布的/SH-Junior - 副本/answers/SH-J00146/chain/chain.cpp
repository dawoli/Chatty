#include <bits/stdc++.h>
using namespace std;
int t, n, k, q, r, c, lst, l[100005], s[1005][2005];
bool b[200005], f;
bool dfs(int a, int m, int st)
{
	if (st == 0 && s[a][m] == c)
	{
		return true;
	}
	if (st == 0)
	{
		return false;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == a)
		{
			continue;
		}
		for (int j = 1; j <= l[i]; j++)
		{
			if (s[i][j] == s[a][m])
			{
				for (int o = j; o <= min(j + k - 1, l[i]); o++)
				{
					if (dfs(i, o, st - 1))
						return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		memset(b, 0, sizeof(b));
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++)
		{
			lst = -1e9;
			cin >> l[i];
			for (int j = 1; j <= l[i]; j++)
			{
				cin >> s[i][j];
				if (lst + k - 1 >= j)
					b[s[i][j]] = true;
				if (s[i][j] == 1)
				{
					lst = j;
				}
				
			}
		}
		for (int i = 1; i <= q; i++)
		{
			cin >> r >> c;
			if (r == 1)
			{
				cout << b[c] << endl;
			}
			else
			{
				f = false;
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= l[i]; j++)
					{
						f |= dfs(i, j, r);
						if (f) break;
					}
					if (f) break;
				}
				cout << f << endl;
			}
		}
	}
}
