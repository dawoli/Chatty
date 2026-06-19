#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, m, k, x, y, d, cnt, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char c[1005][1005];
bool b[1005][1005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		cnt = 0;
		for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) cin >> c[i][j], b[i][j] = 0;
		b[x][y] = 1;
		while (k--)
		{
			ll nx = x + dx[d], ny = y + dy[d];
			if (c[nx][ny] == '.') x = nx, y = ny, b[x][y] = 1;
			else d = (d + 1) % 4;
		}
		for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) cnt += b[i][j];
		cout << cnt << endl;
	}
} 
