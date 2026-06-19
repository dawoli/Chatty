#include<bits/stdc++.h>
using namespace std;

const long long maxn=1e15;
int n,m,k;
bool fA=1;
long long a[10005][10005];
long long c,cost[10005];
int isass[10005][10005];
int asstot[10005];
int totass[10005],detail_ass[10005][20005];
int father[10005],numass[10005];
long long co[10005],ans;
bool ifass[10005];
bool mapass[10005][10005];
int u,v;

void dijkstra0(int id)
{
	if(id>n)return;
	for(int i=1;i<=asstot[id];i++)
	{
		if(!ifass[isass[id][i]])
		{
			ifass[isass[id][i]]=1;
			co[isass[id][i]]=co[id]+a[id][isass[id][i]];
			totass[id]++;
			detail_ass[id][totass[id]]=isass[id][i];
			father[isass[id][i]]=id;
			numass[isass[id][i]]=totass[id];
		}
		else
		{
			if(co[id]+a[id][isass[id][i]]>co[isass[id][i]])
			{
				totass[id]++;
				co[isass[id][i]]=co[id]+a[id][isass[id][i]];
				detail_ass[father[isass[id][i]]][numass[isass[id][i]]]=0;
				father[isass[id][i]]=id;
				detail_ass[id][totass[id]]=isass[id][i];
			}
		}
	}
			
	dijkstra0(id+1);
}

void dijkstra(int id)
{
	if(id>n)return;
	for(int i=1;i<=n;i++)
	{
		if(i==id)continue;
		if(!ifass[i])
		{
			ifass[i]=1;
			co[i]=co[id]+a[id][i];
			totass[id]++;
			detail_ass[id][totass[id]]=i;
			father[i]=id;
			numass[i]=totass[id];
		}
		else
		{
			if(co[id]+a[id][i]>co[i])
			{
				totass[id]++;
				co[i]=co[id]+a[id][i];
				detail_ass[father[i]][numass[i]]=0;
				father[i]=id;
				detail_ass[id][totass[id]]=i;
			}
		}
	}
	dijkstra(id+1);
}

void dfs(int id)
{
	for(int i=1;i<=totass[id];i++)
	{
		if(detail_ass[id][i]!=0)
		{
			ans=ans+co[detail_ass[id][i]]-co[id];
			dfs(detail_ass[id][i]);
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		asstot[u]++;
		asstot[v]++;
		isass[u][asstot[u]]=v;
		isass[v][asstot[v]]=u;
		scanf("%lld",&a[u][v]);
		a[v][u]=a[u][v];
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&cost[i]);
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[j][k]==0)
				{
					a[j][k]=c+cost[j]+cost[k];
					a[k][j]=a[j][k];
				}
				else
				{
					a[j][k]=min(a[j][k],c+cost[j]+cost[k]);
					a[k][j]=a[j][k];
				}
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		co[i]=maxn;
	}
	ifass[1]=1;
	if(k==0)
	{
		dijkstra0(1);
	}
	else
	{
		dijkstra(1);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
