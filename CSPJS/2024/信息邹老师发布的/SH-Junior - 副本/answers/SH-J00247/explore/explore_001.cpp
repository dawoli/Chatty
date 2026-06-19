#include<bits/stdc++.h>
using namespace std;
int t;
int xshuzu[4]={0,1,0,-1};
int yshuzu[4]={1,0,-1,0};
bool a[1001][1001];
bool rea[1001][1001];
int dfs(int x,int y,int d,int step,int n,int m)
{
	if(step<=0)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(rea[i][j]==1)
				cnt++;
			}
		}
		return cnt;
	}
	int next_x=x+xshuzu[d];
	int next_y=y+yshuzu[d];
	if(next_x>=1&&next_x<=n&&next_y>=1&&next_y<=m&&a[next_x][next_y]==0)
	{
		rea[next_x][next_y]=1;
		dfs(next_x,next_y,d,step-1,n,m);
	}
	else
	dfs(x,y,(d+1)%4,step-1,n,m);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int l=0;l<t;l++)
	{
		int n,m,k,x,y,w;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				rea[i][j]=0;
		cin>>n>>m>>k;
		cin>>x>>y>>w;
		rea[x][y]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char h;
				cin>>h;
				a[i][j]=(h=='x'?1:0);
			}
		}
		cout<<dfs(x,y,w,k,n,m)<<endl;
	}
	return 0;
}
