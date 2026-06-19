#include<bits/stdc++.h>
using namespace std;
int flag[1010][1010];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int vis[1010][1010];
int ans=1e9;
int ans2=1e9;
void dfs(int x,int y,int n,int m,int dep,int dep2)
{
	if(x==n&&y==m)
	{
		if(dep2<=ans2)
		{
			ans2=dep2;
			ans=min(ans,dep);
		}
		return;
	}
	vis[x][y]=1;
	if(vis[x+1][y]==0&&flag[x+1][y]!=-1&&x+1<=n)
	{
		dep++;
		if(flag[x+1][y]==1)
		{
			dep2++;
		}
		dfs(x+1,y,n,m,dep,dep2);
		dep--;
		if(flag[x+1][y]==1)
		{
			dep2--;
		}
	}
	if(vis[x-1][y]==0&&flag[x-1][y]!=-1&&x-1>=1)
	{
		dep++;
		if(flag[x-1][y]==1)
		{
			dep2++;
		}
		dfs(x-1,y,n,m,dep,dep2);
		dep--;
		if(flag[x-1][y]==1)
		{
			dep2--;
		}
	}
	if(vis[x][y+1]==0&&flag[x][y+1]!=-1&&y+1<=m)
	{
		dep++;
		if(flag[x][y+1]==1)
		{
			dep2++;
		}
		dfs(x,y+1,n,m,dep,dep2);
		dep--;
		if(flag[x-1][y]==1)
		{
			dep2--;
		}
	}
	if(vis[x][y-1]==0&&flag[x][y-1]!=-1&&y-1>=1)
	{
		dep++;
		if(flag[x][y-1]==1)
		{
			dep2++;
		}
		dfs(x,y-1,n,m,dep,dep2);
		dep--;
		if(flag[x-1][y]==1)
		{
			dep2--;
		}
	}
}
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c;
				if(c=='.')
				{
					flag[i][j]=0;
				}
				else if(c=='$')
				{
					flag[i][j]=1;
				}
				else
				{
					flag[i][j]=-1;
				}
			}
		}
		dfs(1,1,n,m,0,0);
		cout<<ans2<<" "<<ans<<endl;
	}
}
