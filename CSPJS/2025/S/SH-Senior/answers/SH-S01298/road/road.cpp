#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<climits>
#define maxm 1000005
#define maxn 100005
using namespace std;
int n,m,k;
int fir[maxn],nex[2*maxm],to[2*maxm][2];
int c[15],a[15][maxn];
int dis[maxn],tr[maxn][2];
bool vst[maxn],cvst[15];
int tot=0;
void file()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
void add(int x,int y,int w)
{
	nex[tot++]=fir[x];fir[x]=tot;to[tot][1]=y,to[tot][2]=w;
	nex[tot++]=fir[y];fir[y]=tot;to[tot][1]=x,to[tot][2]=w;
}
void read()
{
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
}
queue<int> q;
int prim()
{
	int ans=0;
	memset(dis,0x3f,sizeof dis);
	vst[1]=true;
	dis[1]=0;
	q.push(1);	
	while(!q.empty())
	{
		for(int j=fir[q.front()];j;j=nex[j])
		{
			dis[to[j][1]]=min(dis[to[j][1]],to[j][2]);
			for(int i=1;i<=k;i++)
			{
				if(cvst[i]) dis[to[j][1]]=min(dis[to[j][1]],a[i][q.front()]+a[i][to[j][1]]);
				else
				{
					dis[to[j][1]]=min(dis[to[j][1]],a[i][q.front()]+a[i][to[j][1]]+c[i]);
					cvst[i]=true;
				}
			}
		}
		q.pop();
		int minn=0;
		for(int j=1;j<=n;j++)
			if(dis[minn]>dis[j] && !vst[j]) minn=j;
		if(minn!=0) vst[minn]=true;
		if(minn!=0) q.push(minn);
		if(minn!=0) ans+=dis[minn];
	}
	return ans;
}
int main()
{
	file();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	read();
	int ans = prim();
	cout<<ans<<endl;
	return 0;
}
