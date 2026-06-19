#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[15];
int g[15][15];
int gg[15][15];
int ans[105][15][15];
int n,k,q;
void init()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			g[i][j]=gg[i][j]=0;
			for(int o=0;o<=100;o++)
			{
				ans[o][i][j]=0;
			}
		}
	}	
}
int dfs(int s,int x,int y)
{
	if(ans[s][x][y])
	{
		return ans[s][x][y];
	}
	if(s==1)
	{
		ans[s][x][y]=(g[x][y]>0)+1;
		return (g[x][y]>0)+1;
	}
	int ret=0;
	for(int i=0;i<10;i++)
	{
		if(g[x][i]>1)
		{
			ret=max(ret,dfs(s-1,i,y));
		}
	}
	ans[s][x][y]=ret;
	return ret;
}
void work()
{
	cin>>n>>k>>q;
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<10;j++)a[j]=0;
		int m;
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			for(int l=0;l<10;l++)
			{
				if(a[l]!=0&&i-a[l]+1<=k)
				{
					gg[l][x]=1;
				}
			}
			a[x]=j;
		}
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				g[i][j]+=gg[i][j];
				gg[i][j]=0;
			}
		}
	}
	for(int i=1;i<=100;i++)
	{
		for(int x=0;x<10;x++)
		{
			for(int y=0;y<10;y++)
			{
				ans[i][x][y]=dfs(i,x,y);
			}
		}
	}
	while(q--)
	{
		int r,c;
		cin>>r>>c;
		cout<<ans[r][1][c]-1<<endl;
	}
}
signed main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		work();
	}
	return 0;
}
