#include<iostream>
#include<cstdio>
using namespace std;
char mp[1005][1005];
bool vis[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin>>mp[i][j];
				vis[i][j]=0;
			}
		}
		int cnt=1;
		vis[x][y]=1;
		for(int i = 1;i<=k;i++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<1||nx>n||ny<1||ny>m)
			{
				d=(d+1)%4;
				continue;
			}
			if(mp[nx][ny]=='x')
			{
				d=(d+1)%4;
				continue;
			}
			if(!vis[nx][ny])cnt++;
			vis[nx][ny]=1;
			x=nx;
			y=ny;
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
