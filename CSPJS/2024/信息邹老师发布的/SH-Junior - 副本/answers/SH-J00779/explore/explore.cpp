#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,d,x,y;
	char map[1005][1005];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int ans = 1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=m;j++)
				cin>>map[k][j];
		}
		for(int j=1;j<=k;j++)
		{
			if(d==0) 
			{
				if(x<=n && y+1<=m && map[x][y+1]=='.')
				{
					y+=1;
					ans++;
				}
				else
					d = (d+1)%4;
			}
			else if(d==1) 
			{
				if(x+1<=n && y<=m && map[x+1][y]=='.')
				{
					x+=1;
					ans++;
				}
				else
					d = (d+1)%4;
			}
			else if(d==2) 
			{
				if(x<=n && y-1>=0 && map[x][y-1]=='.')
				{
					y-=1;
					ans++;
				}
				else
					d = (d+1)%4;
			}
			else if(d==3) 
			{
				if(x-1>=0 && y<=m && map[x-1][y]=='.')
				{
					x-=1;
					ans++;
				}
				else
					d = (d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
