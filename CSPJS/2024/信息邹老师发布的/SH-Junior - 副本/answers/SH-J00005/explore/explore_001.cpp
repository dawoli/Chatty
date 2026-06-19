#include <bits/stdc++.h>
using namespace std;
const int q=1100;
int ste1[4]={0,1,0,-1};
int ste2[4]={1,0,-1,0};
char migong[q][q];
int vis[q][q];
int times;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>times;
	while(times>0)
	{
		int n,m,k;
		cin>>n>>m>>k;
		memset(migong,0,sizeof(migong));
		memset(vis,0,sizeof(vis));
		int x,y,dir;
		cin>>x>>y>>dir;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cin>>migong[i][j];
		}
		vis[x][y]++;
		while(k>0)
		{
			int nx=x+ste1[dir],ny=y+ste2[dir];
			if(migong[nx][ny]=='.')
			{
				x=nx;
				y=ny;
				vis[nx][ny]++;
			}
			else
				dir=(dir+1)%4;
			k--;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j]>0)
					ans++;
			}
		}
		cout<<ans<<endl;
		times--;
	}
}
