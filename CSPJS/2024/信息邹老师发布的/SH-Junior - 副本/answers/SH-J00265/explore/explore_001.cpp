#include<bits/stdc++.h>
using namespace std;

int T,n,m,k;
long long ans=1;
int x0,y0,d;
char a[1005][1005];


void dfs(int x0,int y0,int d)
{
	if(k==0) return;
	if(d==0)
	{
		if(x0>=1 && x0<=n && y0+1>=1 && y0+1<=m && a[x0][y0+1]=='.')
		{
			ans++;
			k--;
			dfs(x0,y0+1,d);
		}
		else
		{
			d=(d+1)%4;
			k--;
			dfs(x0,y0,d);
		}
	}
	else if(d==1)
	{
		if(x0+1>=1 && x0+1<=n && y0>=1 && y0<=m && a[x0+1][y0]=='.')
		{
			ans++;
			k--;
			dfs(x0+1,y0,d);
		}
		else
		{
			d=(d+1)%4;
			k--;
			dfs(x0,y0,d);
		}
	}
	else if(d==2)
	{
		if(x0>=1 && x0<=n && y0-1>=1 && y0-1<=m && a[x0][y0-1]=='.')
		{
			ans++;
			k--;
			dfs(x0,y0-1,d);
		}
		else
		{
			d=(d+1)%4;
			k--;
			dfs(x0,y0,d);
		}
	}
	else if(d==3)
	{
		if(x0-1>=1 && x0-1<=n && y0>=1 && y0<=m && a[x0-1][y0]=='.')
		{
			ans++;
			k--;
			dfs(x0-1,y0,d);
		}
		else
		{
			d=(d+1)%4;
			k--;
			dfs(x0,y0,d);
		}
	}
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++)
	{
		ans=1;
		a[1005][1005]={0};
		cin>>n>>m>>k;
		cin>>x0>>y0>>d;
		for(int j=1;j<=n;j++)
		{
			for(int c=1;c<=m;c++)
			{
				cin>>a[j][c];
			}
		}
		dfs(x0,y0,d);
		cout<<ans<<endl;
	}
	return 0;
}
