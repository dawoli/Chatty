#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool b[1005][1005];
int n,m,k;
int dfs(int x,int y,int d,int step)
{
	if(step>k)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][j])sum++;
			}
		}
		return sum;
	}
	b[x][y]=true;
	int dx=x,dy=y;
	if(d==0)dy++;
	if(d==1)dx++;
	if(d==2)dy--;
	if(d==3)dx--;
	if(dx>n||dx<1||dy>m||dy<1)
	{
		d=(d+1)%4;
		return dfs(x,y,d,step+1);
	}
	else if(a[dx][dy]=='x')
	{
		d=(d+1)%4;
		return dfs(x,y,d,step+1);
	}
	else
	{
		return dfs(dx,dy,d,step+1);
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				b[j][k]=false;
			}
		}
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				cin>>a[j][k];
			}
		}
		cout<<dfs(x0,y0,d0,0)<<endl;
	}
	return 0;
}
