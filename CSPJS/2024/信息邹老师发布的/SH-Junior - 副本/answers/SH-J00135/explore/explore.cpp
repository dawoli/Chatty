#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char g[1005][1005];
int vis[1005][1005];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0}; 
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{	
		cin>>n>>m>>k>>x>>y>>d;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>g[i][j];
				vis[i][j]=0;
			}
		}
		int ans=1;
		vis[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && g[nx][ny]=='.')
			{
				x=nx;
				y=ny;
				if(vis[nx][ny]==0)
				{
					vis[x][y]=1;
					ans++;
				}
			}
			else {
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
