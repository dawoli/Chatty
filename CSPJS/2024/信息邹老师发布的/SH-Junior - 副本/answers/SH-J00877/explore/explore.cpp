#include <bits/stdc++.h>

using namespace std;

int a[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int L;
	cin >> L;
	while(L > 0)
	{
		L--;
		int n,m,k;
		int x,y,d;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		vector<vector<char>> v(n+2,vector<char>(m+2,'!'));
		vector<vector<bool>> path(n+2,vector<bool>(m+2,false));
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin >> v[i][j];
			}
		}
		path[x][y] = true;
		for(int i = 1;i <= k;i++)
		{
			int new_x = x + a[d][0];
			int new_y = y + a[d][1];
			if(v[new_x][new_y] == '.')
			{
				x = new_x;
				y = new_y;
				path[x][y] = true;
			}else{
				d = (d + 1) % 4;
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				if(path[i][j])
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
