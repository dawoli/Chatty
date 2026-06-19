#include <bits/stdc++.h>
using namespace std;
int t,dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int l = 0;l < t;l++)
	{
		int n,m,k,x,y,d,cnt = 1;
		char g[1010][1010]; 
		map<pair<int,int>,bool> st;
		cin >> n >> m >> k >> x >> y >> d;
		st[{x,y}] = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin >> g[i][j];
			}
		}
		for(int i = 0;i < k;i++)
		{
			int nx = x + dx[d],ny = y + dy[d];
			if(nx < 1 || nx > n || ny < 1 || ny > m)
			{
				d = (d + 1) % 4;
				continue;
			}
			if(g[nx][ny] == 'x')
			{
				d = (d + 1) % 4;
				continue;
			}
			x = nx;
			y = ny;
			if(!st[{nx,ny}])
			{
				st[{nx,ny}] = 1;
				cnt++;
			}			
		}
		cout << cnt << endl;
	}
	return 0;
}
