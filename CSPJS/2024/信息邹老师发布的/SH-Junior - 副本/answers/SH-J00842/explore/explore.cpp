#include<bits/stdc++.h>
using namespace std;
int t,a[1010][1010],vis[1010][1010],n,m,k,pos1,pos2,dir,ans;
const int dx[5]={0,1,0,-1};
const int dy[5]={1,0,-1,0};
string str;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>pos1>>pos2>>dir;
		for(int i=1;i<=n;i++)
		{
			cin>>str;
			for(int j=0;j<=m-1;j++)
				if(str[j]=='.')
					a[i][j+1]=0;
				else
					a[i][j+1]=1;
		}
		ans=1;
		vis[pos1][pos2]=1;
		for(int i=1;i<=k;i++)
		{
			int x=pos1+dx[dir];
			int y=pos2+dy[dir];
			if(a[x][y]==0&&x>=1&&x<=n&&y>=1&&y<=m)
			{
				pos1=x;
				pos2=y;
				if(vis[x][y]==0)
				{
					vis[x][y]=1;
					ans++;
				}
			}
			else
				dir=(dir+1)%4;
		}
		cout<<ans<<endl;
	}
	return 0;
}
