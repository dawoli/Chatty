#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct spot
{
	int a,dis;
};
bool operator< (const spot& x,const spot& y){
	return x.dis>y.dis;
}
int vis[10010];
int disa[10010];
int g[1010][1010];
int c[20][10010];
int main()
{
	priority_queue<spot> q;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=n;v++)
			{
				g[u][v]=g[v][u]=min(c[i][u]+c[i][v],g[u][v]);
			}
		}
	}//½¨Â· 
	memset(disa,0x3f,sizeof(disa));
	disa[1]=0;
	int cnt=0;
	int ans=0;
	q.push({1,0});
	while(!q.empty())
	{
		int x=q.top().a;
		q.pop();
		if(vis[x])	continue;
		ans+=disa[x];//¼ÓÇ® 
		vis[x]=1;
		disa[x]=0;
		cnt++;
		if(cnt==n)	break;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])	continue;
			if(disa[i]>g[x][i])
			{
				disa[i]=g[x][i];
				q.push({i,disa[i]});
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
