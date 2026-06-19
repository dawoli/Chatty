#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
int ans=1;
char a[1010][1010];
int vis[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int now)
{
	if(now==d)
	{
		return ;
	}
	int tx=x+dx[d];
	int ty=y+dy[d];
	while(tx<1||tx>n||ty<1||ty>m||a[tx][ty]=='x')
	{
		d=(d+1)%4;
		tx=x+dx[d];
		ty=y+dy[d];
	}
	if(vis[tx][ty]==0)
	{
		ans++;
	}
	vis[tx][ty]=1;
	dfs(now+1);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=1;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++);
			{
				cin>>a[i][j];
			}
		}
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}
