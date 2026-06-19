#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int n,m,k,sx,sy,sd,ans;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char c[N][N];
bool vis[N][N];
void dfs(int x,int y,int d)
{
	if(!vis[x][y])
	{
		vis[x][y]=true;
		ans++;
	}
	k--;
	if(k<0)
		return;
	int tx=x+dx[d],ty=y+dy[d];
	if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&c[tx][ty]!='x')
		dfs(tx,ty,d);
	else
		dfs(x,y,(d+1)%4);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(vis,false,sizeof(vis));
		scanf("%d%d%d%d%d%d",&n,&m,&k,&sx,&sy,&sd);
		for(int i=1;i<=n;i++)
			scanf("%s",c[i]+1);
		dfs(sx,sy,sd);
		printf("%d\n",ans);
	}
} 
