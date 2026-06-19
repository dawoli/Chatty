#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e3+5;
int T;
int n,m,k,x,y,d;
char mp[N][N];
bool vis[N][N];
const int f[][2]={{0,1},{1,0},{0,-1},{-1,0}};
void solve()
{
	memset(vis,false,sizeof(vis));
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d%d",&x,&y,&d);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		if(!vis[x][y])
		{
			ans++;
			vis[x][y]=true;
		}
		int nx=x+f[d][0],ny=y+f[d][1];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.')
		{
			x=nx;
			y=ny;
		}
		else
			d=(d+1)%4;
	}
	if(!vis[x][y])
	{
		ans++;
		vis[x][y]=true;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}

