#include<bits/stdc++.h>
using namespace std;
int T;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int n,m,k;
	bool a[1002][1002];
	bool vis[1002][1002];
	int x,y,d;
	string s;
	int i,j,ii;
	int count;
	
	cin>>T;
	for(ii=0;ii<T;ii++)
	{
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(i=1;i<=n;i++)
		{
			cin>>s;
			for(j=1;j<=m;j++)
				if(s[j-1]=='.')
					a[i][j]=1;
		}
		count=1;
		vis[x][y]=1;
		for(i=0;i<k;i++)
		{
			if(a[x+dx[d]][y+dy[d]])
			{
				x+=dx[d];
				y+=dy[d];
				if(!vis[x][y])
				{
					count++;
					vis[x][y]=1;
				}
			}
			else
			{
				d=(d+1)%4;
			}
		}
		cout<<count<<endl;	
	}
	
	return 0;
}
