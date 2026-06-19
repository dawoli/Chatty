#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,ans,chao,x,y,ch[2][5],vis[1001][1001];
char c[1001][1001];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ch[1][0]=0;
	ch[1][1]=1;
	ch[1][2]=0;
	ch[1][3]=-1;
	ch[2][0]=1;
	ch[2][1]=0;
	ch[2][2]=-1;
	ch[2][3]=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		memset(vis,0,sizeof(vis));
		ans=1;
		cin>>n>>m>>k>>x>>y>>chao;
		vis[x][y]=1;
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=m;l++) cin>>c[j][l];
		}
		for(int j=1;j<=k;j++)
		{
			int nx=x+ch[1][chao],ny=y+ch[2][chao];
			if(c[nx][ny]=='x'||nx<1||nx>n||ny<1||ny>m)
			{
				chao=(chao+1)%4;
			}
			else
			{
				if(!vis[nx][ny])
				{
					vis[nx][ny]=1;
					ans++;
				}
				x=nx;
				y=ny;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
