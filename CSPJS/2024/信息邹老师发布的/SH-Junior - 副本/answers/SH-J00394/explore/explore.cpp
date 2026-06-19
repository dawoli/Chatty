#include<iostream>
#include<cstring>
using namespace std;
const int dir[4][2] = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};
bool f[1005][1005] , vis[1005][1005];
void solve()
{
	memset(f , false , sizeof(f));
	memset(vis , false , sizeof(vis));
	int n , m , k; cin >> n >> m >> k;
	int x , y , d; cin >> x >> y >> d;
	vis[x][y] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c; cin >> c;
			if (c == '.') f[i][j] = true;
		 } 
	}
	int cnt = 1;
	for (int i = 1; i <= k; i++)
	{
		int nx = x + dir[d][0] , ny = y + dir[d][1];
		if (f[nx][ny])
		{
			x = nx; y = ny;
			if (!vis[x][y]) cnt ++;
			vis[x][y] = true;
		}
		else d = (d + 1) % 4;
	}
	cout << cnt << endl;
}
int main()
{
	freopen("explore.in" , "r" , stdin);
	freopen("explore.out" , "w" , stdout);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
