#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
int ans;
char mp[1001][1001];
int vis[1001][1001];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		
		ans=1;
		for(int j=1;j<=n;j++)
		{
			for(int h=1;h<=m;h++)
			{
				cin>>mp[j][h];
				vis[j][h]=0;
			}
		}
		vis[x][y]=1;
		for(int j=1;j<=k;j++)
		{
			if(d==0)
			{
			
				if(mp[x][y+1]=='x' || y==m)
				{
					d=(d+1)%4;
				}
				else
				{	
					y++;
					if(vis[x][y]==0)
					{
						vis[x][y]=1;
						ans++;
					}
				}
			}
		else if(d==1)
			{
				
				if(mp[x+1][y]=='x' || x==n)
				{
					d=(d+1)%4;
				}
				else
				{
					x++;
					if(vis[x][y]==0)
					{
						vis[x][y]=1;
						ans++;
					}
				}
			}
			else if(d==2)
			{
				if(mp[x][y-1]=='x' || y==1)
				{
					d=(d+1)%4;
				}
				else
				{
					y--;
					if(vis[x][y]==0)
					{
						vis[x][y]=1;
						ans++;
					}
				}
				
			}
			else if(d==3)
			{
			
				if(mp[x-1][y]=='x' || x==1)
				{
					d=(d+1)%4;
				}
				else
				{
					x--;
					if(vis[x][y]==0)
					{
						vis[x][y]=1;
						ans++;
					}
				}
			}
			
		}		
		cout<<ans<<endl;
	}
	return 0;
}



