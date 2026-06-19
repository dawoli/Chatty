#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while (t--)
	{
		int n,m,k,x,y,d;
		char mp[1005][1005];
		bool vis[1005][1005]={0};
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		vis[x][y]=1;
		while (k--)
		{
			int nx=x,ny=y;
			if (d==0)
			{
				ny++;
			}
			if (d==1)
			{
				nx++;
			}
			if (d==2)
			{
				ny--;
			}
			if (d==3)
			{
				nx--;
			}
			if (nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x')
			{
				nx=x;
				ny=y;
				d++;
				d%=4;
			}
			vis[nx][ny]=1;
			x=nx;
			y=ny;
		}
		int exp=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				exp+=vis[i][j];
			}
		}
		cout<<exp<<endl;
	}
	return 0;
}
