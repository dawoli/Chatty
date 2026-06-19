#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[1005][1005] = {}, b[1005][1005] = {};
int k;
int x, y, d;
char c;
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int sum;
	cin >> t;
	for (int i = 0; i < t; i++)    // O(2*n*m+k)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		sum = 0;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; i++)    //O(n*m)
		{
			for (int j = 1; j <= m; j++)    //O(m)
			{
				cin >> c;
				if (c == 'x') a[i][j] = 1;
			}
		}
		b[x][y] = 1;
		for (int i = 0; i < k; i++)    //O(k)
		{
			if ((d == 0 && (a[x][y + 1] || y == m)) || (d == 1 && (a[x + 1][y] || x == n)) || (d == 2 && (a[x][y - 1] || y == 1)) || (d == 3 && (a[x - 1][y] || x == 1)))
			{
				d++;
				d %= 4;
				continue;
			}
			switch (d)
			{
				case 0: y++; break;
				case 1: x++; break;
				case 2: y--; break;
				case 3: x--; break;
			}
			b[x][y] = 1;
		}
		for (int i = 1; i <= n; i++)    //O(n*m)
		{
			for (int j = 1; j <= m; j++)
			{
				if (b[i][j]) sum++;
			}
		}
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
