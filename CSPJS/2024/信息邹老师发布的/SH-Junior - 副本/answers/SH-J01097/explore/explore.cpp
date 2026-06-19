#include <iostream>
#include <cstdio>
using namespace std;
int T,n,m,x,y,k,d,ans=1,nx,ny;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0},f[1005][1005];
char a[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k>>x>>y>>d;
		nx=x;
		ny=y;
		ans=1;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				f[i][j]=0;
			}
		}
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		f[x][y]=1;
		while(k--)
		{
			nx=x+dx[d];
			ny=y+dy[d];
			if(nx<1||nx>n||ny<1||ny>m)
			{
				d=(d+1)%4;
				continue;
			}
			if(a[nx][ny]=='x')
			{
				d=(d+1)%4;
				continue;
			}
			x=nx;
			y=ny;
			if(!f[x][y])
			{
				ans++;
				f[x][y]=1;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
