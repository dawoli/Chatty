#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
bool a[1010][1010]={false};//走过的格子 
bool c[1010][1010]={false};//是否可走 
char d[1010][1010]={};//输入的格子 
int main()
{
	freopen ("explore.in","r",stdin);
	freopen ("explore.out","w",stdout);
	int T,m,n,k,x,y,d;
	int sum=0;
	cin>>T;
	while(T)
	{
		cin>>n>>m>>k>>x>>y>>d;
		for (int j=0;j<n;j++)
		{
			for (int i=0;i<m;i++)
			{
				cin>>d[j][i];
				if (d[j][i]=='.')
				{
					c[j][i]=true;
				}
			}	
		}
		while (k)
		{
			a[x][y]=true;
			if (d=0)//向东 
			{
				if (c[x][y+1]==true)
				{
					y++;
					a[x][y+1]=true;
				}
				else 
				{
					d=(d+1)%4;
				}
			}
			if (d=1)//向南 
			{
				if (c[x+1][y]==true)
				{
					x++;
					a[x+1][y]=true;
				}
				else 
				{
					d=(d+1)%4;
				}
			}
			if (d=2)//向西 
			{
				if (c[x][y-1]==true)
				{
					y--;
					a[x][y-1]=true;
				}
				else 
				{
					d=(d+1)%4;
				}
			}
			if (d=3)//向北 
			{
				if (c[x-1][y]==true)
				{
					x--;
					a[x-1][y]=true;
				}
				else 
				{
					d=(d+1)%4;
				}
			}
			k--; 
		}
		for (int j=0;j<n;j++)//计算走过格数 
		{
			for (int i=0;i<m;i++)
			{
				if (a[j][i]==true)
				{
					sum++;
				}
			}	
		}
		cout<<sum;
		T--;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
