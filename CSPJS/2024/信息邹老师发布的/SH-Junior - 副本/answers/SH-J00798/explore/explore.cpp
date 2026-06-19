#include<iostream>
using namespace std;
int dx[4]={0,1,0,-1},
    dy[4]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(t-=1;t>=0;t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		char a[n+1][m+1]={};bool b[n+1][m+1]={};
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
		b[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			if(x+dx[d]>0&&x+dx[d]<=n&&y+dy[d]>0&&y+dy[d]<=m&&a[x+dx[d]][y+dy[d]]=='.')
			{
				b[x+dx[d]][y+dy[d]]=1;
				x+=dx[d],y+=dy[d];
			}
			else d=(d+1)%4;
		}
		int t=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(b[i][j]) t++;
		cout<<t<<endl;
	}
	return 0;
}
