#include<bits/stdc++.h>
using namespace std;
int n;	string s;
int T;
int dx[6]={0,1,0,-1};
int dy[6]={1,0,-1,0};
char a[1000][1000];
int vis[1000][1000];
int m=0,k,d;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int x,y,ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
		ans+=1;
		vis[x][y]=1;
		for(int i=0;i<k;i++)
		{
			if(a[x+dx[d]][y+dy[d]]!='.'||(x+dx[d])>n||(x+dx[d])<=0||(y+dy[d])>m||(y+dy[d])<=0)
			{
				
				d=(d+1)%4;
			}
			else
			{
			x+=dx[d];y+=dy[d];
			}
			if(vis[x][y]!=1)
			{
				ans+=1;vis[x][y]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
