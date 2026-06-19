#include <cstdio>
#include <iostream>
using namespace std;
char a[1001][1001];
int b[1001][1001] = {};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n,m,k;
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) cin >> a[i][j];
		int l = 1;
		for (int i = 1; i <= k; i++)
		{
			if (d == 0)
			{
				if (y + 1 <= m && a[x][y + 1] == '.')
				{
					y++;
					if (b[x][y] != 3) b[x][y] = 3,l++;
				}
				else d = (d + 1) % 4;
			}
			else if (d == 1)
			{
				if (x + 1 <= n && a[x + 1][y] == '.')
				{
					x++;
					if (b[x][y] != 3) b[x][y] = 3,l++;
				}
				else d = (d + 1) % 4;
			}
			else if (d == 2)
			{
				if (y - 1 >= 1 && a[x][y - 1] == '.')
				{
					y--;
					if (b[x][y] != 3) b[x][y] = 3,l++;
				}
				else d = (d + 1) % 4;
			}
			else
			{
				if (x - 1 >= 1 && a[x - 1][y] == '.')
				{
					x--;
					if (b[x][y] != 3) b[x][y] = 3,l++;
				}
				else d = (d + 1) % 4;
			}
		}
		cout << l << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
