#include <bits/stdc++.h>
using namespace std;

char a[1000][1000];
bool b[1000][1000];

bool out(int x, int y, int n, int m)
{
	return x > n || x < 1 || y > m || y < 1;
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	while (T --> 0)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int xs, ys, d;
		cin >> xs >> ys >> d;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
			}
		}
		int c = 1;
		b[xs][ys] = 1;
		while (k--)
		{
			if (
				(d == 0 && (a[xs][ys+1] == 'x' || out(xs, ys+1, n, m)))
				|| (d == 1 && (a[xs+1][ys] == 'x' || out(xs+1, ys, n, m)))
				|| (d == 2 && (a[xs][ys-1] == 'x' || out(xs, ys-1, n, m)))
				|| (d == 3 && (a[xs-1][ys] == 'x' || out(xs-1, ys, n, m)))
			) d = (d + 1) % 4;
			else
			{
				if (d == 0) ys++;
				else if (d == 1) xs++;
				else if (d == 2) ys--;
				else xs--;
				if (!b[xs][ys]) { c++; b[xs][ys]++; }
			}
		}
		cout << c << endl;
		memset(b, 0, sizeof(b));
	}
	return 0;
}
