#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200];
int xr;
int mp[20][20];

bool cmp(int x,int y)
{
	return x>y;
}

void dfs(int x,int y,int cnt)
{
	if(y>m) return ;
	if(y%2)
	{
		if(x==n+1)
		{
			dfs(n,y+1,cnt);
		}
		else{
			mp[x][y]=a[cnt];
			dfs(x+1,y,cnt+1);
		}
	}
	else{
		if(x==0)
		{
			dfs(1,y+1,cnt);
		}
		else{
			mp[x][y]=a[cnt];
			dfs(x-1,y,cnt+1);
		}
	}
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==xr)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
