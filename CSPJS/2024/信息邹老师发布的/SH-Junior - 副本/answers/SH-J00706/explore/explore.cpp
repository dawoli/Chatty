#include <iostream>
#include <cstdio>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
void func()
{
	int n, m, k, x, y, d;
	cin >> n >> m >> k >> x >> y >> d;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			vis[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	vis[x][y] = 1;
	while (k--)
	{
	    int xx = x, yy = y;
	    if (d == 0) yy++;
		if (d == 1) xx++;
		if (d == 2) yy--;
		if (d == 3) xx--;
		if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] != 'x') x = xx, y = yy;
		else d = (d + 1) % 4;
		vis[x][y] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans += vis[i][j];
		}
	}
	cout << ans << "\n";
}
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
    int t;
	cin >> t;
	while (t--) func();	
}
