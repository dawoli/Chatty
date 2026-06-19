#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],a2[1010][1010];
int movex[4]={0,1,0,-1};
int movey[4]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long sum=0;
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m,k;
		cin>>n>>m>>k;
		int x,y,x_1,y_1,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c;
				if(c=='x') a[i][j]=0;
				else if(c=='.') a[i][j]=1;
			}
		}
		a2[x][y]=1;
		while(k--)
		{
			x_1=x+movex[d];
			y_1=y+movey[d];
			if(a[x_1][y_1]==1&&(x_1>=1&&x_1<=n)&&(y_1>=1&&y_1<=m))
			{
				x=x_1;
				y=y_1;
				a2[x][y]=1;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a2[i][j]==1)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
		sum=0,x=0,y=0,x_1=0,y_1=0,d=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=0;
				a2[i][j]=0;
			}
		}
	}
	return 0;
}
