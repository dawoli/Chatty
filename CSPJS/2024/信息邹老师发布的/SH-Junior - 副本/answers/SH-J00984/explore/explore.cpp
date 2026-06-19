#include <bits/stdc++.h>
using namespace std;

int T, n, m, l;
int sx, sy, sd;
int ans[10] = {};
bool b[1010][1010] = {};
bool a[1010][1010] = {};
char c;

int main ()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);	
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		ans[i] = 1;
		memset(a, false, sizeof(a));
		memset(b, false, sizeof(b));
		cin >> n >> m >> l;
		cin >> sx >> sy >> sd;
		a[sx][sy] = true;
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				cin >> c;
				if (c == 'x')
					b[j][k] = false;
				else if (c == '.')
					b[j][k] = true;
			}
		}
		for (int j = 1; j <= l; j++)
		{
			if (sd == 0)
			{
				if (sy + 1 <= m && b[sx][sy + 1])
				{
					sy++;
					if (!a[sx][sy])
					{
						a[sx][sy] = true;
						ans[i]++;
					}
				}
				else
					sd = (sd + 1) % 4;
			}
			else if (sd == 1)
			{
				if (sx + 1 <= n && b[sx + 1][sy])
				{
					sx++;
					if (!a[sx][sy])
					{
						a[sx][sy] = true;
						ans[i]++;
					}
				}
				else
					sd = (sd + 1) % 4;
			}
			else if (sd == 2)
			{
				if (sy - 1 >= 1 && b[sx][sy - 1])
				{
					sy--;
					if (!a[sx][sy])
					{
						a[sx][sy] = true;
						ans[i]++;
					}
				}
				else
					sd = (sd + 1) % 4;
			}
			else if (sd == 3)
			{
				if (sx - 1 >= 1 && b[sx - 1][sy])
				{
					sx--;
					if (!a[sx][sy])
					{
						a[sx][sy] = true;
						ans[i]++;
					}
				}
				else
					sd = (sd + 1) % 4;
			}
		}
	}
	for (int i = 1; i <= T; i++)
		cout << ans[i] << endl;
	return 0;
}
