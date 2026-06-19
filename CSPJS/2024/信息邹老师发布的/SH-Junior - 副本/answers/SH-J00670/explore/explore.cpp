#include <bits/stdc++.h>
using namespace std;
int t,x,y,d,n,m,k,ans = 1;
char des[1005][1005];
bool vis[1005][1005];
int dfs(int x,int y,int d,int k)
{
	while(k--)
	{
		vis[x][y] = 1;
		int dx = x;
		int dy = y;
		if(d == 0) dy += 1;
		if(d == 1) dx += 1;
		if(d == 2) dy -= 1;
		if(d == 3) dx -= 1;
		if(des[dx][dy] == '.' && (1 <= dx && dx <= n) &&(1 <= dy && dy <= m))
		{
			if(vis[dy][dx] == 0)
			{
				ans++;
				vis[dy][dx] = 1;
			}
		}
		else{
			d = (d+1)%4;
		}
		return dfs(dx,dy,d,k);
	}
	return ans;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int j = 1; j <= n; j++)
		{
			for(int q = 1; q <= m; q++)
			{
				cin >> des[j][q];				
			}
		}
		if(k == 1)
		{
			if(des[x+1][y] == 'x' && des[x-1][y] == 'x' && des[x][y-1] == 'x' && des[x][y+1] == 'x')
				cout << 1;
			else
			{
				if((d == 0 && des[x][y+1] == '.' )||( d == 1 && des[x+1][y] == '.' )||( d == 2 && des[x][y-1] == '.') ||( d == 3 && des[x][y-1] == '.'))
					cout << 2;
				else
					cout << 1;
			}
		}
	}
	return 0;
}
