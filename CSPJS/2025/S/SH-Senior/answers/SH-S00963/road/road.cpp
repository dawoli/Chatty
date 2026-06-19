#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,k,u,v,w,c[20],a[20][10005],fa[1000005],ans;
vector<pii> e[1000005];
struct path
{
	int u,v,w;
}g[1000005];
vector<path> g2;
bool cmp(path a,path b){return a.w<b.w;}
int father(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=father(fa[x]);
}
int Kruskal()
{
	int ans=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(g+1,g+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		u=g[i].u;
		v=g[i].v;
		w=g[i].w;
		int fu=father(u);
		int fv=father(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		g2.push_back({u,v,w});
		ans+=w;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
		e[g[i].u].push_back({g[i].v,g[i].w});
		e[g[i].v].push_back({g[i].u,g[i].w});
	}
	bool flag1=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)flag1=0;
		}
		if(c[i]!=0)flag1=0;
	}
	if(flag1&&k)
	{
		printf("0\n");
		return 0;
	}
	printf("%d\n",Kruskal());
	return 0;
}
