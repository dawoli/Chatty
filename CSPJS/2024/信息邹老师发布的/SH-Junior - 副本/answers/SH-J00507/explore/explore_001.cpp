#include <bits/stdc++.h>
using namespace std;
bool vis[1001][1001];
char a[1001][1001];
int c;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		c=0;
		int n,m,k;
		cin>>n>>m>>k;
		int x0,y0,d0,all=1;
		cin>>x0>>y0>>d0;
		int d=d0,x=x0,y=y0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				cin>>a[j][k];
				vis[j][k]=0;
			}
		}
		vis[x][y]=1;
		for(int j=0;j<k;j++)
		{
			int x1=x,y1=y;
			if(d==0)
			{
				y1++;
			}
			if(d==1)
			{
				x1++;
			}
			if(d==2)
			{
				y1--;
			}
			if(d==3)
			{
				x1--;
			}
	//		cout<<x1<<','<<y1<<' '<<x<<','<<y<<' '<<d<<endl;
			if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&a[x1][y1]!='x')
			{
				c=0;
				x=x1;
				y=y1;
				if(vis[x][y]==0)
				{
					all++;
					vis[x][y]=1;
				}
			}
			else
			{
				c++;
				if(c>=4)
				{
					cout<<all;
					return 0;
				}
				d=(d+1)%4;
			}
		}
		cout<<all<<endl;
	}
}
