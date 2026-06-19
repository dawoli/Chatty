#include<bits/stdc++.h>
using namespace std;
int T,n,m,cnt,k,x,y,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},vis[1010][1010];
char mp[1010][1010];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k>>x>>y>>d;
		cnt=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
				vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		while(k--)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&mp[nx][ny]=='.')
			{
				if(vis[nx][ny]==0) cnt++;
				vis[nx][ny]=1;
				x=nx,y=ny;
			}
			else d=(d+1)%4;
		}
		cout<<cnt<<endl;
	}
}
