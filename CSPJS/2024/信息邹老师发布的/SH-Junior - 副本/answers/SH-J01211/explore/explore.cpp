#include <iostream>
#include <cstdio>
using namespace std;
int t, m, n, k, sx, sy, tx, ty, d, cc;
char M[1005][1005];
int D[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
bool F[1005][1005];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d%d%d", &n, &m, &k, &sx, &sy, &d);
		F[sx][sy] = 1;
		for (int i = 1; i <= n; i++)
			scanf("%s", M[i] + 1);
		while (k--)
		{
			tx = sx + D[d][0];
			ty = sy + D[d][1];
			if (tx >= 1 && tx <= n && ty >= 1&& ty <= m && M[tx][ty] != 'x')
			{
				sx = tx;
				sy = ty;
				F[sx][sy] = 1;
			}
			else
				d = (d + 1) % 4;
			//cout << sx << ' ' << sy << endl;
		}
		cc = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (F[i][j])
				{
					cc++;
					F[i][j] = 0;
				}
		cout << cc << endl;
	}
	return 0;
}

