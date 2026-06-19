#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
bool end = 0;
char a[1145][1411];
bool vis[1145][1411];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void dfs(int x,int y,int d,int p)
{
	if(p > k)
	{
		end = 1;
		return;
	}
	if(end)return;
	int nx = x + dx[d],ny = y + dy[d];
	if(nx > n || nx < 1 || ny < 1 || ny > m || a[nx][ny] == 'x')
	{
		d = (d+1) % 4;
		dfs(x,y,d,p+1);
	}
	else vis[nx][ny] = 1;
	dfs(nx,ny,d,p+1);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout); 
	int T;
	cin >> T;
	int cur = 1;
	while(T--)
	{
		cin >> n >> m >> k >> x >> y >> d;
		end = 0;
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				cin >> a[i][j];
		vis[x][y] = 1;
		dfs(x,y,d,1);
		int ans = 0;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				ans += vis[i][j];
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
  
