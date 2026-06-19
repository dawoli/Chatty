#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int x,y,d;
char mp[1010][1010];
bool vis[1010][1010];
int ret=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool check(int xx,int yy)
{
	return xx>=1&&xx<=n&&yy>=1&&yy<=m&&mp[xx][yy]!='x';
}
void work()
{
	ret=0;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			vis[i][j]=0;
		}
	}
	ret++;
	vis[x][y]=1;
	while(k--)
	{
		x+=dx[d];
		y+=dy[d];
		if(!check(x,y))
		{
			x-=dx[d];
			y-=dy[d];
			d=(d+1)%4;
		}
		if(vis[x][y])
		{
			continue;
		}
		vis[x][y]=1;
		ret++;
	}
	cout<<ret<<endl;
}
signed main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		work();
	}
	return 0;
}
