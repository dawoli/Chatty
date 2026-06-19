#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,p,x,y,d,ans,nx,ny;
char a[1005][1005];
bool vis[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%lld\n",&t);
	for(ll i=1;i<=t;++i)
	{
		scanf("%lld %lld %lld\n",&n,&m,&p);
		scanf("%lld %lld %lld\n",&x,&y,&d);
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		for(ll j=1;j<=n;++j,getchar())for(ll k=1;k<=m;++k)a[j][k]=getchar();
		ans=1;
		for(ll q=1;q<=p;++q)
		{
			switch(d)
			{
				case 0:nx=x,ny=y+1;break;
				case 1:nx=x+1,ny=y;break;
				case 2:nx=x,ny=y-1;break;
				case 3:nx=x-1,ny=y;break;
				default:break;
			}
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&a[nx][ny]=='.')x=nx,y=ny,ans+=!vis[x][y],vis[x][y]=1;
			else d=(d+1)%4;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

