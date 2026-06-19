#include<bits/stdc++.h>
using namespace std;
int hx[4]={0,1,0,-1};
int hy[4]={1,0,-1,0};
char wh[1009][1009];
int wa[1009][1009];
int T,n,m,k;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++)
	{
		cin>>n>>m>>k;
		int x,y,d,ans=1;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>wh[i][j];
			}
		}
		for(int i=1;i<=k;i++)
		{
			int xx=x+hx[d],yy=y+hy[d];
			if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&wh[xx][yy]=='.') x=xx,y=yy,wa[xx][yy]=1;
			else
			{
				d+=1;
				d%=4;
			} 
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(wa[i][j]==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
