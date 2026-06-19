#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
const int dx[] = {0,1, 0,-1};
const int dy[] = {1,0,-1, 0};
int n,m,k,x,y,d;
char mp[N][N];
bool vst[N][N];
void mian()
{
	scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d); vst[x][y] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf(" %c", &mp[i][j]);
	while (k--)
	{
		int nx = x + dx[d],ny = y + dy[d];
		if (nx < 1 || nx > n || ny < 1 || ny > m) (++d) %= 4;
		else if (mp[nx][ny] == 'x') (++d) %= 4;
		else vst[x = nx][y = ny] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (vst[i][j]) ++ans,vst[i][j] = 0;
	printf("%d\n", ans);
}
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) mian();
	return 0;
}