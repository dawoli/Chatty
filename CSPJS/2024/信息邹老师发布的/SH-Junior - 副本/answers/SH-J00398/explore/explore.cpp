#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
bool vis[N][N], dx[N][N];
int dir[9] = {0, 1, 1, 0, 0, -1, -1, 0}, k;

void dfs(int x, int y, int d, int stp)
{
	vis[x][y] = 1;
	if(stp == k) return;
	int nx = x + dir[d * 2], ny = y + dir[d * 2 + 1];
	if(dx[nx][ny]) dfs(nx, ny, d, stp + 1);
	else dfs(x, y, (d + 1) % 4, stp + 1);
}

void solve()
{
	memset(vis, 0, sizeof(vis));
	memset(dx, 0, sizeof(dx));
	
	int n, m;
	cin >> n >> m >> k;
	int x, y, d;
	cin >> x >> y >> d;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for(int j = 1; j <= m; j++)
		{
			if(s[j - 1] == '.') dx[i][j] = 1;
		}
	}
	
	dfs(x, y, d, 0);
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++) ans += vis[i][j];
	}
	
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int t;
	cin >> t;
	
	while(t--) solve();
}
