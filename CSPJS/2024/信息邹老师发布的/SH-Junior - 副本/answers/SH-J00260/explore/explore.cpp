#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,ans=0;
char mp[1005][1005];
bool vis[1005][1005]={0};
int dt[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; //{{0,1},{1,0},{0,-1},{-1,0}} {{1,0},{0,-1},{-1,0},{0,1}}
void dfs(int x,int y,int k)
{
	if(!k) return;
	k--;
	if(x+dt[d][0] >= 1 && x+dt[d][0] <= n && y+dt[d][1] >= 1 && y+dt[d][1] <= m && mp[x+dt[d][0]][y+dt[d][1]]!='x')
	{
		x+=dt[d][0],y+=dt[d][1];
		vis[x][y]=true;
		dfs(x,y,k);
	}
	else
	{
		d=(d+1)%4;
		dfs(x,y,k);
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		vis[x][y]=true;
		dfs(x,y,k);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j]) ++ans;
				vis[i][j]=0;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
}
