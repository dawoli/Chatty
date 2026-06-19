#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,x,y,d,b[1005][1005],ans;
char a[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for (int g=1;g<=t;g++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		x--;
		y--;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			for (int j=0;j<m;j++)
			{
				b[i][j]=0;
			}
		}
		b[x][y]=1;
		ans=1;
		for (int i=1;i<=k;i++)
		{
			if (d==0)
			{
				if (y+1>=m)
				{
					d=(d+1)%4;
				}
				else if (a[x][y+1]=='x')
				{
					d=(d+1)%4;
				}
				else
				{
					y=y+1;
					if (b[x][y]==0)
					{
						b[x][y]=1;
						ans++;
					}
				}
			}
			else if (d==1)
			{
				if (x+1>=n)
				{
					d=(d+1)%4;
				}
				else if (a[x+1][y]=='x')
				{
					d=(d+1)%4;
				}
				else
				{
					x=x+1;
					if (b[x][y]==0)
					{
						b[x][y]=1;
						ans++;
					}
				}
			}
			else if (d==2)
			{
				if (y-1<0)
				{
					d=(d+1)%4;
				}
				else if (a[x][y-1]=='x')
				{
					d=(d+1)%4;
				}
				else
				{
					y=y-1;
					if (b[x][y]==0)
					{
						b[x][y]=1;
						ans++;
					}
				}
			}
			else
			{
				if (x-1<0)
				{
					d=(d+1)%4;
				}
				else if (a[x-1][y]=='x')
				{
					d=(d+1)%4;
				}
				else
				{
					x=x-1;
					if (b[x][y]==0)
					{
						b[x][y]=1;
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
