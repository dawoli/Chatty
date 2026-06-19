#include<bits/stdc++.h>
using namespace std;
const int maxn=625;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m,k,x,y,d,b[maxn][maxn],ans=1;
		char a[maxn][maxn];
		memset(b,0,sizeof(b));
		cin>>n>>m>>k>>x>>y>>d;
		b[x][y]=1;
		for(int j=1;j<=n;j++)
		{
			for(int tem=i;tem<=m;tem++)
			{
				cin>>a[j][tem];
			}
		}
		for(int j=1;j<=k;j++)
		{
			if(d==0)
			{
				y++;
				if(a[x][y]=='x'||y>m)
				{
					d=(d+1)%4;
					y--;
				}
				else
				{
					if(b[x][y]==0)
					{
						ans++;
						b[x][y]=1;
					}
				}
			}
			else if(d==1) 
			{
				x++;
				if(a[x][y]=='x'||x>n)
				{
					d=(d+1)%4;
					x--;
				}
				else
				{
					if(b[x][y]==0)
					{
						ans++;
						b[x][y]=1;
					}
				}
			}
			else if(d==2)
			{
				y--;
				if(a[x][y]=='x'||y<1)
				{
					d=(d+1)%4;
					y++;
				}
				else
				{
					if(b[x][y]==0)
					{
						ans++;
						b[x][y]=1;
					}
				}
			}
			else if(d==3)
			{
				x--;
				if(a[x][y]=='x'||x<1)
				{
					d=(d+1)%4;
					x++;
				}
				else
				{
					if(b[x][y]==0)
					{
						ans++;
						b[x][y]==1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
