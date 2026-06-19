# include <bits/stdc++.h>
using namespace std;
int ans[5]={0};
int xb[4]={0,1,0,-1};
int yb[4]={1,0,-1,0};
int n,m,k,i;
int sx,sy,sd;
char dt[1001][1001]={};
bool flag[1001][1001]={0};
void dfs(int x,int y,int sum,int xp,int d)
{
	if(xp>k)
	{
		ans[i-1]=sum;
		return;
	}
	flag[x][y]=1;
	if(x+xb[d]>=1&&x+xb[d]<=n&&y+yb[d]>=1&&yb[d]+y<=m&&dt[x+xb[d]][y+yb[d]]!='x'&&xp+1<=k)
	{
		if(flag[x+xb[d]][y+yb[d]]==1)
		{
			dfs(x+xb[d],y+yb[d],sum,xp+1,d);
			return;
		}
		dfs(x+xb[d],y+yb[d],sum+1,xp+1,d);
		return;
	}
	else
	{
		dfs(x,y,sum,xp+1,(d+1)%4);
		return;
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n>>m>>k;
		cin>>sx>>sy>>sd;
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=m;b++)
			{
				cin>>dt[a][b];
			}
		}
		dfs(sx,sy,1,0,sd);
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=m;v++)
			{
				flag[u][v]=0;
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
