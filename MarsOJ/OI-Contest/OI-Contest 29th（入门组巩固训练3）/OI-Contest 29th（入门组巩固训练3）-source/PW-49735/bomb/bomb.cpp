#include <bits/stdc++.h>
using namespace std;
int T;
int n,m,sx,sy,ex,ey;
char a[80][80];
bool vis[80][80];
int dis[80][80];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
struct node
{
	int x,y;
};
int bfs()
{
	queue<node> q;
	q.push({sx,sy});
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		int x=now.x,y=now.y;
		if(x==ex&&y==ey) 
		{
			return dis[x][y];
		}
		int nx,ny;
		for(int i=0;i<4;i++)
		{
			nx=x+dx[i];ny=y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m||vis[nx][ny]||a[nx][ny]=='*') continue;
			vis[nx][ny]=true;q.push({nx,ny});
			dis[nx][ny]=dis[x][y]+1;
		}
	}
	return -1;
}
int main()
{
	freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    ios::sync_with_stdio(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		sx=1,sy=1,ex=n,ey=m;
		if(n==1)
		{
			string x;
			cin>>x;
			int cnt1=0;
			for(int i=0;i<m;i++)
			{
				if(x[i]=='$') cnt1++;
			}
			cout << cnt1 << " " << m-1 << "\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++) cin>>a[i][j];
			}
			int ans=bfs();
			cout << 0 << " " << ans << "\n";
		}
	}
	return 0;
}