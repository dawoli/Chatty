#include <bits/stdc++.h>

using namespace std;
const int N=1e3+10;
int n;
int m;
int k;
int xyd[3];
char c[N][N];
bool box[N][N];
bool check(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m&&c[x][y]=='.';
}
void dfs(int step,int x,int y,int d)
{
	if(step>k)
	{
		int ans;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(box[i][j])
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		return;
	}
	int x0;
	int y0;
	int d0;
	d0=d;
	if(d==0)
	{
		x0=x;
		y0=y+1;
	}
	if(d==1)
	{
		x0=x+1;
		y0=y;
	}
	if(d==2)
	{
		x0=x;
		y0=y-1;
	}
	if(d==3)
	{
		x0=x-1;
		y0=y; 
	}
	if(!check(x0,y0))
	{
		x0=x;
		y0=y;
		d0=(d+1)%4;
	}
	
	step++;
	box[x0][y0]=1;
	dfs(step,x0,y0,d0);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		int x0;
		int y0;
		int d0;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>c[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				box[i][j]=0;
			}
		}
		box[x0][y0]=1;
		dfs(1,x0,y0,d0);
	}
	return 0;
}
