#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=INT_MAX;
int e[10005][10005];
bool vis[10005];
void bfs(int x,int y,int num)
{
	if(e[x][y]==0)
	{
		if(x+1!=y)bfs(x+1,y,num);
		if(y+1!=x)bfs(x,y+1,num);
	}
	if(x==n&&y==n-1)
	{
		for(int i=1;i<=n;i++)if(vis[i])return ;
		ans=min(ans,num);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(e[x][y])
			{
				vis[x]=vis[y]=1;
				if(x+1!=y)bfs(x+1,y,num+e[x][y]);
				if(y+1!=x)bfs(x,y+1,num+e[x][y]);
				vis[x]=vis[y]=0;
			}
		}
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u1,v1,w;
		cin>>u1>>v1>>w;
		e[u1][v1]=w;
		e[v1][u1]=w;
	}
	for(int i=1;i<=k;i++)
	{
		int a[10005],c;
		cin>>c;
		for(int j=1;j<=n;j++)cin>>a[j];
		for(int j=1;j<=n;j++)
		{
			for(int t=1;t<=n;t++)
			{
				if(j==t)continue;
				e[j][t]=e[t][j]=min(e[j][t],c+a[j]+a[t]);
			}
		}
	}
	bfs(1,2,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<e[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
} 
