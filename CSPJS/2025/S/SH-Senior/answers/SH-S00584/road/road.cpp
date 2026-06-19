#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int u,v;
	long long w;
	bool operator < (const struct node &t) const
	{
		return w==t.w?(u==t.u?v<t.v:u<t.u):w<t.w;
	}
} NODE,*PNODE;
NODE edge[2000004];
int ancestor[1005],country[15][1005],n,m;
long long ans=0;
int get_ancestor(int x)
{
	return x==ancestor[x]?x:ancestor[x]=get_ancestor(ancestor[x]);
}
void union_set(int x,int y)
{
	ancestor[get_ancestor(x)]=get_ancestor(y);
}
void Kruscal()
{
	int i,j;
	for(i=1;i<=n;++i)
		ancestor[i]=i;
	for(i=1,j=1;i<n&&j<=m;++i)
	{
		while(j<=m&&get_ancestor(edge[j].u)==get_ancestor(edge[j].v))
			++j;
		if(j<=m)
		{
			ans+=edge[j].w;
			union_set(edge[j].u,edge[j].v);
			++j;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int k,u,v,w,i,j,l;
	long long minv=LONG_LONG_MAX;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		edge[i].u=u;
		edge[i].v=v;
		edge[i].w=w;
	}
	for(i=1;i<=k;++i)
	{
		scanf("%d",&country[i][0]);
		for(j=1;j<=n;++j)
			scanf("%d",&country[i][j]);
	}
	for(i=1;i<n;++i)
	{
		for(j=i+1;j<=n;++j)
		{
			minv=INT_MAX;
			for(l=1;l<=k;++l)
				minv=min(minv,(long long)country[l][0]+country[l][i]+country[l][j]);
			edge[++m].u=i;
			edge[m].v=j;
			edge[m].w=minv;
		}
	}
	sort(edge+1,edge+m+1);
	Kruscal();
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
