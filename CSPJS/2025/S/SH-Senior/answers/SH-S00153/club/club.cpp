#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 205;
int t, n, ans, x, a[N][4], b[N], f[M][M][M];
bool f1 = true, f2 = true;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] || a[i][3]) f1 = false;
			if (a[i][3]) f2 = false;
		}
		
		if (f1)
		{
			for (int i = 1; i <= n; i++)
				b[i] = a[i][1];
			sort(b + 1, b + n + 1, greater <int>());
			for (int i = 1; i <= n / 2; i++)
				ans += b[i];
			cout << ans << endl;
		}
		else if (f2)
		{
			for (int i = 1; i <= n; i++)
			{
				ans += a[i][2];
				b[i] = a[i][1] - a[i][2];
			}
			sort(b + 1, b + n + 1, greater <int>());
			for (int i = 1; i <= n / 2; i++)
			{
				ans += b[i];
			}
			cout << ans << endl;
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j <= min(n / 2, i); j++)
				{
					for (int k = max(i - j - n / 2, 0); k <= min(n / 2, i - j); k++)
					{
						int l = i - j - k;
						f[i][j][k] = 0;
						if (j) f[i][j][k] = f[i - 1][j - 1][k] + a[i][1];
						if (k) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][2]);
						if (l) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][3]);
						ans = max(ans, f[i][j][k]);
					}
				}
			}
			cout << ans << endl;
		}
	}
}
