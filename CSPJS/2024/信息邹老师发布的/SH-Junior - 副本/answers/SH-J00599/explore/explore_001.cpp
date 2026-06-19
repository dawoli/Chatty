#include <bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,t,d,a[1050][1050],vis[1050][1050],ans;
char q;
void solve1()
{
	if(d==0)
	{
		if(a[x][y+1]==1)
		{
			cout <<2 <<endl;
			return;
		}
		else
		{
			cout <<1 <<endl;
			return;
		}
	}
	else if(d==1)
	{
		if(a[x+1][y]==1)
		{
			cout <<2 <<endl;
			return;
		}
		else
		{
			cout <<1 <<endl;
			return;
		}
	}
	else if(d==2)
	{
		if(a[x][y-1]==1)
		{
			cout <<2 <<endl;
			return;
		}
		else
		{
			cout <<1 <<endl;
			return;
		}
	}
	else
	{
		if(a[x-1][y]==1)
		{
			cout <<2 <<endl;
			return;
		}
		else
		{
			cout <<1 <<endl;
			return;
		}
	}
}
void solve2()
{
	ans++;
	vis[x][y]=1;
	for(int i=1;i<=k;i++)
	{
		if(d==0)
		{
			if(a[x][y+1]==1)
			{
				if(vis[x][y+1]==0)
				{
					ans++;
				}
				vis[x][y+1]=1;
				y+=1;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		else if(d==1)
		{
			d=(d+1)%4;
		}
		else if(d==2)
		{
			if(a[x][y-1]==1)
			{
				if(vis[x][y-1]==0)
				{
					ans++;
				}
				vis[x][y-1]=1;
				y-=1;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		else
		{
			d=(d+1)%4;
		}
	}
	cout <<ans <<endl;
	return;
}
void solve3()
{
	ans++;
	vis[x][y]=1;
	for(int i=1;i<=k;i++)
	{
		if(d==0)
		{
			if(a[x][y+1]==1)
			{
				if(vis[x][y+1]==0)
				{
					ans++;
				}
				vis[x][y+1]=1;
				y+=1;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		else if(d==1)
		{
			if(a[x+1][y]==1)
			{
				if(vis[x+1][y]==0)
				{
					ans++;
				}
				vis[x+1][y]=1;
				x+=1;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		else if(d==2)
		{
			if(a[x][y-1]==1)
			{
				if(vis[x][y-1]==0)
				{
					ans++;
				}
				vis[x][y-1]=1;
				y-=1;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		else
		{
			if(a[x-1][y]==1)
			{
				if(vis[x-1][y]==0)
				{
					ans++;
				}
				vis[x-1][y]=1;
				x-=1;
			}
			else
			{
				d=(d+1)%4;
			}
		}
	}
	cout <<ans <<endl;
	return;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >>t;
	while(t--)
	{
		cin >>n >>m >>k;
		cin >>x >>y >>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin >>q;
				if(q=='.')
				{
					a[i][j]=1;
				}
				else if(q=='x')
				{
					a[i][j]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				vis[i][j]=0;
			} 
		} 
		ans=0;
		if(k==1)
		{
			solve1();
		}
		else if(n==1)
		{ 
			solve2();
		}
		else 
		{
			solve3(); 
		}
	}
	return 0; 
}
