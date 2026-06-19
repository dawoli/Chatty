#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,sx,sy,sd;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[1050][1050];
bool v[1050][1050];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d%d",&n,&m,&k,&sx,&sy,&sd);
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		int x=sx,y=sy,d=sd;
		v[sx][sy]=1;
		for(int i=1;i<=k;i++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(mp[nx][ny]=='.')
			{
				x=nx,y=ny;
			}
			else
			{
				d=(d+1)%4;
			}
			v[x][y]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(v[i][j]) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}