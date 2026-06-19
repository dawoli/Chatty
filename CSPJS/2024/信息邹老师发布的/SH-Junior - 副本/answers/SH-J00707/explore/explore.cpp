#include <iostream>
#include <stdio.h>
using namespace std; 

int t;
int n, m, k;
int x0, y0, d0;
char a[1003][1003];
bool b[1003][1003];

void DFS(int x, int y, int dir, int time, int step)
{
	if (time == k)
	{
		printf("%d\n", step);
		return;
	}
	int dx = x, dy = y;
	if (dir == 0)
	{
		dy++;
	}
	else if (dir == 1)
	{
		dx++;
	}
	else if (dir == 2)
	{
		dy--;
	}
	else if (dir == 3)
	{
		dx--;
	}
	if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && a[dx][dy] == '.')
	{
		if (!b[dx][dy])
		{
			b[dx][dy] = true;
			DFS(dx, dy, dir, time + 1, step + 1);
		}
		else
		{
			DFS(dx, dy, dir, time + 1, step);
		}
	}
	else
	{
		DFS(x, y, (dir + 1) % 4, time + 1, step);
	}
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d%d", &n, &m, &k);
		scanf("%d%d%d", &x0, &y0, &d0);
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				cin >> a[j][k];
				b[j][k] = false;
			}
		}
		b[x0][y0] = true;
		DFS(x0, y0, d0, 0, 1);
	}
	return 0;
}

// 10s 20
