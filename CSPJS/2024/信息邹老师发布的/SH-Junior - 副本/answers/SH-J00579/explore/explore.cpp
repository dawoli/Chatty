#include<bits/stdc++.h>
using namespace std;
int vis[1005][1005];
char dis[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		long long k,ans=0;
		int x,y,d,n,m;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>dis[i][j];
				vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			long long sx,sy;
			if(d==0) sx=x,sy=y+1;
			else if(d==1) sx=x+1,sy=y;
			else if(d==2) sx=x,sy=y-1;
			else sx=x-1,sy=y;
			if(1<=sx&&sx<=n && 1<=sy&&sy<=m && dis[sx][sy]=='.')
			{
				vis[sx][sy]=1;
				x=sx;
				y=sy;
			}
			else d=(d+1)%4;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
