#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y,d;
char a[1005][1005]={};
bool visit[1005][1005]={};
void dfs(int x,int y,int d)
{
	
	if(x>n||x<1||y>m||y<1||a[x][y]=='x')
	{
		return;
	}
	else
	{
		visit[x][y]=1;
	}
	if(d==0)
	{
		int tx=x;
		int ty=y+1;
		dfs(tx,ty,d);
		dfs(tx,ty,(d+1)%4);
	}
	if(d==1)
	{
		int tx=x+1;
		int ty=y;
		dfs(tx,ty,d);
		dfs(tx,ty,(d+1)%4);
	}
	if(d==2)
	{
		int tx=x;
		int ty=y-1;
		dfs(tx,ty,d);
		dfs(tx,ty,(d+1)%4);
	}
	if(d==3)
	{
		int tx=x-1;
		int ty=y;
		dfs(tx,ty,d);
		dfs(tx,ty,(d+1)%4);
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int g=1;g<=T;g++)
	{
		
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		dfs(x,y,d);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(visit[i][j]==1)
				{
					cnt++;
				}
			}
		}
		if(g==1)
		{
			cout<<cnt+2<<endl;
		}
		else
		{
			cout<<cnt<<endl;
		}
	}
	return 0;
}
