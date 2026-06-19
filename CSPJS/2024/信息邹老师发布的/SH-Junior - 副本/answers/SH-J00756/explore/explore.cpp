#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, k;
int x, y, d, cnt;
char Map[1005][1005];
bool been[1005][1005];
int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &T);
	for (; T--; )
	{
		memset(been, 0, sizeof(been));
		scanf("%d%d%d", &n, &m, &k);
		scanf("%d%d%d", &x, &y, &d);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", Map[i] + 1);
		}
		been[x][y] = true;
		cnt = 1;
		for (int i = 1; i <= k; i++)
		{
			int x2, y2;
			x2 = x + step[d][0];
			y2 = y + step[d][1];
			if (Map[x2][y2] == 'x' || x2 < 1 || x2 > n || y2 < 1 || y2 > m)
			{
				d = (d + 1) % 4;
			}
			else
			{
				x = x2;
				y = y2;
				if (!been[x][y])
				{
					been[x][y] = true;
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
