#include<bits/stdc++.h>
using namespace std;
int c[1000005],ancestor[1000005],vis[1000005];
int n,m,ans;
typedef struct node
{
	int u,v,w;
	bool operator < (const struct node &t) const
	{
		w<t.w;
	}
}NODE,PNODE;
NODE rd[1000005];
int get_ancestor(int u)
{
	return ancestor[u]==get_ancestor(ancestor[u])?u:ancestor[u];
}
void union_ancestor(int u,int v)
{
	ancestor[u]=get_ancestor(ancestor[v]);
}
void kruskal() 
{
	int i;
	sort(rd+1,rd+m+1);
	for(i=1;i<=n-1;++i)
	{
		if(ancestor[rd[i].u]==ancestor[rd[i].v]||vis[rd[i].u]&&vis[rd[i].v])
			continue;
		else
		{ 
			union_ancestor(rd[i].u,rd[i].v);
			ans+=rd[i].w;
			vis[rd[i].u]=vis[rd[i].v]=1;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int k,u,v,w,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		rd[i]=(NODE){u,v,w};
	}
	for(i=1;i<=k;++i)
	{
		scanf("%d",&c[i]);
		for(j=1;j<=n;++j)
			scanf("%d",&w);
	}
	kruskal();
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
