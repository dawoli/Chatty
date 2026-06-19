#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int k,t,d,m,n,x0,y0,d0;
char mp[1005][1005];
bool vis[1005][1005];
int solve(int x,int y,int d)
{
	memset(vis,0,sizeof(vis));
	int nx,ny,nd,cx=x,cy=y,cd=d,times=k;
	int ans=1; vis[x][y]=1;
	while(times--)
	{
		if(cd==0) nx=cx,ny=cy+1;
		if(cd==1) nx=cx+1,ny=cy;
		if(cd==2) nx=cx,ny=cy-1;
		if(cd==3) nx=cx-1,ny=cy;
		if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&mp[nx][ny]=='.')
		nd=cd;
		else nx=cx,ny=cy,nd=(cd+1)%4;
		cx=nx,cy=ny,cd=nd;
		if(!vis[cx][cy]) ans++,vis[cx][cy]=1;
	}
	return ans;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
		cin >> mp[i][j];
		cout << solve(x0,y0,d0) << '\n';
	}
	return 0;
}
