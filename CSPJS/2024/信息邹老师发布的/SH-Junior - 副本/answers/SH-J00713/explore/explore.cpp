#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int cnt,n,m,k;
bool b;
void dfs(int x,int y,int d)
{
	if(k<0||b)
	{
		b=1;
		return;
	}
	if(vis[x][y]==0) cnt++;
	vis[x][y]=1;
	int tx=x+dx[d],ty=y+dy[d];
	if(tx<1||tx>n||ty<1||ty>m||a[tx][ty]=='x')
	{
		d=(d+1)%4;
		k--;
		dfs(x,y,d);
	}
	else
	{
		k--;
		dfs(tx,ty,d);
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,sx,sy,d;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k>>sx>>sy>>d;
		d=d%4;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) cin>>a[i][j];
		}
		memset(vis,0,sizeof(vis));
		cnt=0;
		b=0;
		dfs(sx,sy,d);
		cout<<cnt<<'\n';
	}
	return 0;
}
