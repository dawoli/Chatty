#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,sx,sy,d,ans;
char mp[1005][1005];
bool vis[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=1;
		memset(vis,false,sizeof(vis));
		cin>>n>>m>>k>>sx>>sy>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		vis[sx][sy]=true;
		for(int i=1;i<=k;i++)
		{
			int nx,ny;
			if(d==0)
			    nx=sx,ny=sy+1;
			else if(d==1)
			    nx=sx+1,ny=sy;
			else if(d==2)
			    nx=sx,ny=sy-1;
			else
			    nx=sx-1,ny=sy;
			if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x')
			    d=(d+1)%4;
			else
			{
				sx=nx,sy=ny;
				ans+=1-vis[sx][sy];
				vis[sx][sy]=true;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
