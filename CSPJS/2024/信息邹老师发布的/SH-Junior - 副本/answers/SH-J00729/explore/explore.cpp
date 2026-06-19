#include<bits/stdc++.h>
using namespace std;
int dx[10]={0,1,0,-1},dy[10]={1,0,-1,0},mp[1005][1005];
bool vi[1005][1005];
bool check(int n,int m,int x,int y)
{
	if(x>0&&x<=n&&y>0&&y<=m&&mp[x][y]!=1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d;
	char c;
	cin>>t;
	while(t--)
	{
		memset(vi,false,sizeof(vi));
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>c;
				if(c=='.')
				{
					mp[i][j]=0;
				}
				else
				{
					mp[i][j]=1;
				}
			}
		}
		for(int i=1;i<=k;i++)
		{
			vi[x][y]=1;
			if(check(n,m,x+dx[d],y+dy[d]))
			{
				x=x+dx[d];
				y=y+dy[d];
			}
			else
			{
				d=(d+1)%4;
			}
		}
		vi[x][y]=1;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vi[i][j]==1)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
