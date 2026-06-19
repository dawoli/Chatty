#include<bits/stdc++.h>
using namespace std;
int t;
char f[1005][1005];
bool b[1005][1005];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
void pk()
{
	int ans=0;
	memset(b,false,sizeof(b));
	int n,m,k;
	int x,y,d;
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
		}
	}
	b[x][y]=true;
//	cout<<"b["<<x<<"]["<<y<<"]=true;"<<endl;
	for(int i=1;i<=k;i++)
	{
		int nx=x+dx[d];
		int ny=y+dy[d];
		if(nx<1||nx>n||ny<1||ny>m||f[nx][ny]=='x')
		{
			d=(d+1)%4;
//			cout<<"i="<<i<<" f["<<dx<<"]["<<dy<<"]²»ÐÐ d="<<d<<endl; 
			continue;
		}
		x=nx;
		y=ny;
//		cout<<"i="<<i<<" b["<<x<<"]["<<y<<"]=true;"<<endl;
		b[x][y]=true;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==true) ans++;
		}
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		pk();
	}
	return 0;
}
