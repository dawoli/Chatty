#include<bits/stdc++.h>
using namespace std;
int n,m,k=0,x=1,y=1,z=0;
int a[12][12],b[120];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	k=b[1];
	sort(b+1,b+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++)
	{
		if((x-z==1 && y==1)| (x==1 && y==1))
		{
			a[x][y]=b[i];
			y++;
		}

		if(y+1>m)
		{
			a[x+1][y]=b[i];
			x++;
			z=x-1;
		}
		if(x-z==1 && y==m)
		{
			a[x][y-1]=b[i];
			y--;
		}
		if(y-1<0)
		{
			a[x+1][y]=b[i];
			x++;
			z=x-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==k)
			{
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}
