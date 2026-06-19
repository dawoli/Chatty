#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int x,y,d;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char a[1005][1005];
bool b[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				b[i][j]=false;
			}
		}
		int ans=1;
		b[x][y]=true;
		for(int i=1;i<=k;i++)
		{
			int nx=x+dx[d],my=y+dy[d];
			if(nx<1||nx>n||my<1||my>m||a[nx][my]!='.')
			{
				d=(d+1)%4;
			}
			else
			{
				x=nx;
				y=my;
				if(b[x][y]==false)
				{
					ans++;
					b[x][y]=true;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
