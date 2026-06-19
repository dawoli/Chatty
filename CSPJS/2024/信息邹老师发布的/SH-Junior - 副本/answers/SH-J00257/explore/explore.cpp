#include<bits/stdc++.h>
using namespace std;
int T,ans=0,n,m,k,x,y,d,mx,my;
char a[1005][1005];
int c[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int b=1;b<=T;b++)
	{
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=1000;i++)
		{
			for(int j=1;j<=1000;j++)
			{
				c[i][j]=0;
			}
		}
		c[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			if(d==0)
			{
				mx=x;
				my=y+1;
			}
			if(d==1)
			{
				mx=x+1;
				my=y;
			}
			if(d==2)
			{
				mx=x;
				my=y-1;
			}
			if(d==3)
			{
				mx=x-1;
				my=y;
			}
			if(mx>=1&&mx<=n&&my>=1&&my<=m&&a[mx][my]=='.')
			{
				x=mx;
				y=my;
				c[x][y]=1;
			}
			else
			d=(d+1)%4;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(c[i][j]==1)
				ans++;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}







