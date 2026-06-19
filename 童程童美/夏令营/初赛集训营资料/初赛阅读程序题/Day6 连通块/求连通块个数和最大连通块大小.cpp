#include<bits/stdc++.h>
using namespace std;
#define N 105
struct Node
{
	int x, y;
};
int n, m, a[N][N], areaCnt, maxArea;
bool vis[N][N]; 
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int bfs(int sx, int sy)
{
	int ct = 0;
	queue<Node> que;
	vis[sx][sy] = true;
	que.push(Node{sx,sy});
	while(que.empty() == false)
	{
		Node u = que.front();
		que.pop();
		ct++;
		for(int i = 0; i < 4; ++i)
		{
			int x = u.x + dir[i][0], y = u.y + dir[i][1];
			if(x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && a[x][y] == 1)
			{
				vis[x][y] = true;
				que.push(Node{x,y});
			}
		}
	}
	return ct;
}
int main()
{
 	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(a[i][j] == 1 && !vis[i][j]) 
			{
				maxArea = max(maxArea, bfs(i, j));
				areaCnt++; 
			}
	cout << areaCnt << ' ' << maxArea;
	return 0;
}
