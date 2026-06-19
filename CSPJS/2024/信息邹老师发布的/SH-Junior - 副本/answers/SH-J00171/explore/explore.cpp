#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 9;
ll ans = 0, T, n, m, x_0, y_0, d_0, k;
ll vst[N][N];
char Map[N][N];
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
void move(ll x, ll y, ll d, ll k)
{
	if(k == 0)
		return ;
	ll nx = x + dx[d], ny = y + dy[d];
	if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && Map[nx][ny] == '.')
	{
		x = nx;
		y = ny;
		if(!vst[x][y])
		{
			vst[x][y] = 1;
			ans++;
		}
	}
	else d = (d + 1) % 4;
	move(x, y, d, k - 1);
}
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> k;
		cin >> x_0 >> y_0 >> d_0;
		ans++;
		vst[x_0][y_0] = 1;
		for(ll i = 1; i <= n; i++)
			for(ll j = 1; j <= m; j++)
				cin >> Map[i][j];
		move(x_0, y_0, d_0, k);
		cout << ans << endl;
		ans = 0;
		for(ll i = 1; i <= n; i++)
			memset(vst, 0, sizeof(vst));
	}
	return 0;
}
