#include<bits/stdc++.h>
using namespace std;
char c[1010][1010];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[1010][1010];
int n,m;
bool chk(int x,int y)
{
	return x>=1 and x<=n and y>=1 and y<=m and c[x][y]=='.'; 
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int tt;cin>>tt;
	while(tt--)
	{
		memset(c,0,sizeof(c));
		memset(vis,0,sizeof(vis));
		int k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=m;j++)
				cin>>c[i][j];
		vis[1][1]=1;
		while(k--)
		{
			if(!chk(x+dir[d][0],y+dir[d][1]))d=(d+1)%4;
			else{
				x+=dir[d][0];
				y+=dir[d][1];
				vis[x][y]=1; 
			}
		}
		int ans=0;
		for(int i =1;i<=n;i++)
			for(int j = 1;j<=m;j++)
				ans+=vis[i][j];
		cout<<ans<<endl;
	}
}
