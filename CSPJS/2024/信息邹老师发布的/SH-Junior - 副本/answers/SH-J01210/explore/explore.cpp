#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d, newx, newy, ans;
char ch[10][1010][1010];
bool vst[10][1010][1010];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		ans = 1;
		cin >> n >> m >> k >> x >> y >> d;
		vst[i][x][y] = 1;
		for (int j = 1; j <= n; j++) for (int l = 1; l <= m; l++) cin >> ch[i][j][l];
		for (int j = 1; j <= k; j++)
		{
			if (d == 0)
			{
				newx = x;
				newy = y + 1;
			}
			if (d == 1)
			{
				newx = x + 1;
				newy = y;
			}
			if (d == 2)
			{
				newx = x;
				newy = y - 1;
			}
			if (d == 3)
			{
				newx = x - 1;
				newy = y;
			}
			if (newx >= 1 and newx <= n and newy >= 1 and newy <= m and ch[i][newx][newy] == '.')
			{
				if (vst[i][newx][newy] == 0) ans++;
				vst[i][newx][newy] = 1;
				x = newx;
				y = newy;
			}
			else d = (d + 1) % 4;
		}
		cout << ans << endl;
	}
	return 0;
}
