#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d,c;
	cin>>t;
	for (int e=1;e<=t;e++)
	{
		c=1;
		cin>>n>>m>>k>>x>>y>>d;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		for (int i=1;i<=k;i++)
		{
			int x_=x,y_=y;
			if (d==0)
			{
				y_=y+1;
			}
			else if (d==1)
			{
				x_=x+1;
			}
			else if (d==2)
			{
				y_=y-1;
			}
			else if (d==3)
			{
				x_=x-1;
			}
			if (1<=x_&&x_<=n&&1<=y_&&y_<=m&&a[x][y]=='.')
			{
				x=x_;
				y=y_;
				c++;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}
