#include<bits/stdc++.h>
using namespace std;
int t,m,n,k,x,y,d,sum=1;
int v[1005][1005],a[1005][1005];
void move()
{
	int xx,yy;
	if(d==0)
	{
		xx=x,yy=y+1;
	}
	else if(d==1)
	{
		xx=x+1,yy=y;
	}
	else if(d==2)
	{
		xx=x,yy=y-1;
	}
	else if(d==3)
	{
		xx=x-1,yy=y;
	}
	if(xx>0&&xx<=n&&yy>0&&yy<=m&&v[xx][yy]==1)
	{
		if(a[xx][yy]==0)
		{
			sum++;
		}
		a[xx][yy]=1;
		x=xx,y=yy;
		return;
	}
	else
	{
		d=(d+1)%4;
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		cin>>n>>m>>k>>x>>y>>d;
		char c;
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=m;l++)
			{
				cin>>c;
				if(c=='.')
				{
					v[j][l]=1;
				}
				else
				{
					v[j][l]=0;
				}
			}
		}
		for(int j=1;j<=k;j++)
		{
			move();
		}
		cout<<sum<<endl;
	}
	return 0;
}
