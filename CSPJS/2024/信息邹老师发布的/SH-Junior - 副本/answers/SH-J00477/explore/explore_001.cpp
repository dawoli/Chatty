#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1010;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};
ll n, m, k, ret, vis[N][N][5], dis[N][N][5], is[N][N]; char s[N][N];
struct node { ll x, y, d; };
bool check(ll nx, ll ny, ll nd)
{
	if (nx < 1 || nx > n || ny < 1 || ny > m) return false;
	if (s[nx][ny] == 'x' || vis[nx][ny][nd]) return false;
	return true;
}
void bfs(ll sx, ll sy, ll sd)
{
	memset(dis, 0, sizeof(dis)), memset(vis, 0, sizeof(vis)), memset(is, 0, sizeof(is));
	queue<node> q; q.push((node){sx, sy, sd}), vis[sx][sy][sd] = 1;
	while (!q.empty())
	{
		node f = q.front(); q.pop();
		ll x = f.x, y = f.y, d = f.d;
//		printf("%lld %lld %lld\n", x, y, d);
		if (!is[x][y]) ret++, is[x][y] = 1;
		if (dis[x][y][d] >= k) continue;
		ll nx = x + dx[d], ny = y + dy[d], nd = d;
		if (check(nx, ny, nd)) q.push((node){nx, ny, nd}), vis[nx][ny][nd] = 1, dis[nx][ny][nd] = dis[x][y][d] + 1;
		else
		{
			nx = x, ny = y, nd = (nd + 1) % 4;
			if (check(nx, ny, nd)) vis[nx][ny][nd] = 1, dis[nx][ny][nd] = dis[x][y][d] + 1, q.push((node){nx, ny, nd});
		}
	}
}
void solve()
{
	ret = 0;
	scanf("%lld%lld%lld", &n, &m, &k);
	ll sx, sy, sd; scanf("%lld%lld%lld", &sx, &sy, &sd);
	for (ll i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	bfs(sx, sy, sd), printf("%lld\n", ret);
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ll T; scanf("%lld", &T);
	while (T--) solve();
	return 0;
}
