#include <bits/stdc++.h>
using namespace std;
int n,m,k,xd,yd,d;
int ans;
char a[1001][1001];
bool b[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y)
{
	if(k<=0) return;
	int nx=x+dx[d];
	int ny=y+dy[d];
	while(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x')
	{
		if(k<=0) break;
		d=(d+1)%4;
		nx=x+dx[d];
		ny=y+dy[d];
		if(!(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x')) break;
		k--;
	}
	if(b[nx][ny]==0)
	{
		ans++;
		b[nx][ny]=1;
	}
	k--;
	dfs(nx,ny);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ans=0;
		cin>>n>>m>>k;
		cin>>xd>>yd>>d;
		bool cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		int sx=xd+dx[d];
		int sy=yd+dy[d];
		if(!(sx<1||sx>n||sy<1||sy>m||a[sx][sy]=='x')) ans=1;
		b[xd][yd]=1;
		dfs(xd,yd);
		cout<<ans<<endl;
	}
	return 0;
}
