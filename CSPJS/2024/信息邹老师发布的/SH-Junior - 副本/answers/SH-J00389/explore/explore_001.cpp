#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,vis[1010][1010];
char a[1010][1010];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		int sum=1;
		for(int i=1;i<=k;i++)
		{
			if(d==0)
			{
				y=y+1;
				if(x<1 || x>n || y<1 || y>m || a[x][y]=='x')
				{
					d=(d+1)%4;
					y=y-1;
				}
				else
				{
					if(vis[x][y]==0)
					{
						sum++;
					}
					vis[x][y]=1;
				}
				continue;
			}
			if(d==1)
			{
				x=x+1;
				if(x<1 || x>n || y<1 || y>m || a[x][y]=='x')
				{
					d=(d+1)%4;
					x=x-1;
				}
				else
				{
					if(vis[x][y]==0)
					{
						sum++;
					}
					vis[x][y]=1;
				}
				continue;
			}
			if(d==2)
			{
				y=y-1;
				if(x<1 || x>n || y<1 || y>m || a[x][y]=='x')
				{
					d=(d+1)%4;
					y=y+1;
				}
				else
				{
					if(vis[x][y]==0)
					{
						sum++;
					}
					vis[x][y]=1;
				}
				continue;
			}
			if(d==3)
			{
				x=x-1;
				if(x<1 || x>n || y<1 || y>m || a[x][y]=='x')
				{
					d=(d+1)%4;
					x=x+1;
				}
				else
				{
					if(vis[x][y]==0)
					{
						sum++;
					}
					vis[x][y]=1;
				}
				continue;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
