#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
int t, a[1005][1005];
bool vis[1005][1005];
char c[1005][1005];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		memset(c, 0, sizeof(c));
		int ans=0;
		int n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>c[i][j];
			}
		}
		vis[x][y]=1;
		while(k--)
		{
			int xx=x+dx[d];
			int yy=y+dy[d];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && c[xx][yy] == '.')
			{
				x = xx;
				y = yy;
				vis[x][y] = 1;
			}
			else d=(d+1)%4;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j]) ans++;
			}
		}
		cout<< ans<< endl;
	}
	return 0;
}
