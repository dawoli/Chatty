#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	char ch[1003][1003];
	int a[1003][1003];
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int n,m,x,y,k,d,cnt=1;
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&x,&y,&d);
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=m;l++)
			{
				cin>>ch[j][l];
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=m;l++)
			{
				a[j][l]=0;
			}
		}
		a[x][y]=1;
		for(int q=1;q<=k;q++)
		{
			if(d==0) 
			{
				if(x>=1 && x<=n && y+1>=1 && y+1<=m && ch[x][y+1]=='.')
				{
					if(a[x][y+1]!=1) cnt++;
					a[x][y+1]=1;
					y+=1;
					continue;
				}
				else
				{
					d=1;
					continue;
				}
			}
			if(d==1) 
			{
				if(x+1>=1 && x+1<=n && y>=1 && y<=m && ch[x+1][y]=='.')
				{
					if(a[x+1][y]!=1) cnt++;
					a[x+1][y]=1;
					x+=1;
					continue;
				}
				else
				{
					d=2;
					continue;
				}
			}
			if(d==2) 
			{
				if(x>=1 && x<=n && y-1>=1 && y-1<=m && ch[x][y-1]=='.')
				{
					if(a[x][y-1]!=1) cnt++;
					a[x][y-1]=1;
					y-=1;
					continue;
				}
				else
				{
					d=3;
					continue;
				}
			}
			if(d==3) 
			{
				if(x-1>=1 && x-1<=n && y>=1 && y<=m && ch[x-1][y]=='.')
				{
					if(a[x-1][y]!=1) cnt++;
					a[x-1][y]=1;
					x-=1;
					continue;
				}
				else
				{
					d=0;
					continue;
				}
			}
		}
		printf("%d\n",cnt);	
	}
	return 0;
}
