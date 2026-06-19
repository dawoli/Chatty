#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char mp[1005][1005];
int vis[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin>>n>>m>>k>>x>>y>>d;
		memset(vis,0,sizeof(vis));
		int cnt=1;
		for (int i=1;i<=n;i++)
		{
			for (int j = 1;j<=m;j++)
			{
				cin >> mp[i][j];
			}
		}
		vis[x][y]=1;
		for(int i = 1;i<=k;i++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]!='x')
			{
				x=nx;
				y=ny;
//				cout << "[DEBUG]"<<x << " "<<y<<endl;
				cnt+=(1-vis[nx][ny]);
				vis[nx][ny]=1;
//				cout << "cnt="<<cnt<<" vis[nx][ny]="<<vis[nx][ny]<<endl;
//				cnt++;
			}
			else
			{
				d=(d+1)%4;
//				cout << "[DEBUG]d="<<d<<endl;
			}
		}
		cout << cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
