#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans=1;
int x,y,d;
int f[1010][1010];
char mp[1010][1010];
bool pd()
{
	if(d==0)
	{
		if(mp[x][y+1]=='x' || (y+1)>m)
		{
			return false;
		}
	}
	if(d==1)
	{
		if(mp[x+1][y]=='x' || (x+1)>n)
		{
			return false;
		}
	}
	if(d==2)
	{
		if(mp[x][y-1]=='x' || (y-1)<1)
		{
			return false;
		}
	}
	if(d==3)
	{
		if(mp[x-1][y]=='x' || (x-1)<1)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T=0;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=1;
		memset(f,0,sizeof(f));
		f[x][y]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		for(int i=1;i<=k;i++)
		{
			if(pd())
			{
				if(d==0)
				{
					y++;
				}
				if(d==1)
				{
					x++;
				}
				if(d==2)
				{
					y--;
				}
				if(d==3)
				{
					x--;
				}	
				if(f[x][y]==0)
				{
					f[x][y]=ans+1;
					ans=max(f[x][y],ans);
				}
			}
			else
			{
				d+=1;
				d=d%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
