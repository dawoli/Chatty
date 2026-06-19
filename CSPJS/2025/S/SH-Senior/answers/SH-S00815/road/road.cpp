#include<bits/stdc++.h>
using namespace std;
const int M=2000005;
const int N=1005;
int head[N],to[M];
long long weight[M];
int nxt[M],c[N],ct[N][15],tot,in[N];
int tmp[N];
int visited[N];
long long n,m,k,ans=LONG_LONG_MAX;
inline void add_edge(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[tot]=v;
	weight[tot]=w;
	head[u]=tot;
}
long long calc()
{
	int maxn=INT_MIN;
	long long ret=0;
	for(int i=1;i<=n;i++)
	{
		ret+=tmp[i];
		maxn=max(maxn,tmp[i]);
	} 
	return ret-maxn;
}
void dfs1(int u,int cnt)
{
	if(cnt>=n)
	{
		ans=min(ans,calc());
		return ;
	}
	visited[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(visited[v])
			continue;
		tmp[cnt]=weight[i];
		dfs1(v,cnt+1);
	}
}
void dfs(int u,long long sum,int cnt)
{
	if(cnt>=n)
	{
		ans=min(ans,sum);
		return ;
	}
	visited[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(visited[v])
			continue;
		dfs(v,sum+weight[i],cnt+1);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int flag=1;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
		in[u]++,in[v]++;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]!=0)
			flag=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&ct[j][i]);
			if(ct[j][i]!=0)
				flag=0;
		}
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			memset(visited,0,sizeof(visited));
			dfs(i,0,1);
		}
		printf("%lld\n",ans);
	}
	else if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			memset(visited,0,sizeof(visited));
			dfs1(i,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
