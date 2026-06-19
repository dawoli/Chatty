#include <bits/stdc++.h>

using namespace std;

const int N = 100009, M = 204;

int n, f[M][M][M];

void solve_BF()
{
	cin >> n; int ans = 0;
	for (int i = 1; i <= n; ++ i)
	{
		int a, b, c; cin >> a >> b >> c;
		for (int j = 0; j <= i && j <= n / 2; ++ j)
			for (int k = 0; k <= i - j && k <= n / 2; ++ k)
			{
				if (i - j - k > n / 2) continue;
				f[i][j][k] = 0;
				if (j > 0) f[i][j][k] = f[i - 1][j - 1][k] + a;
				if (k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + b);
				if (j + k < i) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + c);
				//cout << i << " " << j << ' ' << k << " " << f[i][j][k] << endl;
				if (i == n) ans = max(ans, f[i][j][k]);
			}
	}
	cout << ans << endl;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; cin >> t;
	while (t --) solve_BF();
	return 0;
 } 
