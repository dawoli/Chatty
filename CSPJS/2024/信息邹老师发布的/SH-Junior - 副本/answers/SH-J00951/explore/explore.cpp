#pragma optimize(2)
#include <bits/stdc++.h>
using namespace std;

int t , n , m , k , x , y , d , ans;
char a[1005][1005];
int dx[] = {0 , 1 , 0 , -1};
int dy[] = {1 , 0 , -1 , 0};
bool vis[1005][1005];

void dfs(int xx , int yy , int dd , int kk)
{
	if(kk == 0)
	{
		return;
	}
	int nx = xx + dx[d];
	int ny = yy + dy[d];
	if(a[nx][ny] != '.' || nx > n || ny > m)
	{
		d = (d + 1) % 4;
		dfs(xx , yy , d , kk - 1);
	}
	else
	{
		if(vis[nx][ny] == 0)
	    {
		    ans++;
		    vis[nx][ny] = 1; 
	    }
	    dfs(nx , ny , d , kk - 1);
	}
	
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin >> t;
	while(t--)
	{
		ans = 1;
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= m ; j++)
			{
				vis[i][j] = 0;
				cin >> a[i][j];
			}
		}
		vis[x][y] = 1;
		dfs(x , y , d , k);
		cout << ans;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
