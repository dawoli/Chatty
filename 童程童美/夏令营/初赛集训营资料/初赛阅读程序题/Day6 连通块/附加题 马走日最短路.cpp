#include <iostream>
using namespace std;
const int N = 105;
int n, stx, sty, edx, edy, ans = -1;
int dir[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
bool vis[N][N];
void dfs(int sx, int sy, int dis)
{
	if(sx == edx && sy == edy)
	{
		if(ans == -1 || dis < ans) 
			ans = dis;
		return;
	}	
	for(int i = 0; i < 8; ++i)
	{
		int x = sx+dir[i][0], y = sy+dir[i][1];
		if(!vis[x][y]x >= 1 && x <= n && y >= 1 && y <= n && )
		{
			vis[x][y] = true;
			dfs(x, y, dis+1);
			vis[x][y] = false;
		}
	}
}
int main()
{
	cin >> n >> stx >> sty >> edx >> edy;
	vis[stx][sty] = true;
	dfs(stx, sty, 0);
	cout << ans;
	return 0;
}
