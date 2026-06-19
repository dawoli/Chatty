# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1010;
ll T, n, m, k, ix, iy, id, ans;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};
bool vis[N][N];
char ch[N][N];

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%lld", &T);
	while (T--)
	{
		memset(vis, false, sizeof(vis));
		scanf("%lld%lld%lld", &n, &m, &k);
		scanf("%lld%lld%lld", &ix, &iy, &id);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> ch[i][j];
			}
		}
		vis[ix][iy] = true;
		ans = 1;
		while (k--)
		{
			ll tx, ty;
			tx = ix + dx[id];
			ty = iy + dy[id];
			if (tx < 1 || tx > n || ty < 1 || ty > m) {id = (id + 1) % 4; continue;}
			if (ch[tx][ty] == 'x') {id = (id + 1) % 4; continue;}
			ix = tx, iy = ty;
			ans += (!vis[ix][iy]);
			vis[ix][iy] = true;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
