#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,k;
const int N=1e4+7,M=2e6+7;
int spe[20][N],c[20];
bool rural[20];
int fa[N],tot;
long long ans;
struct Edge
{
	int u,v;
	ll w;
}e[M];
bool cmp(Edge A,Edge B)
{
	return A.w<B.w;
}
ll read()
{
	char ch=getchar();
	ll res=0;
	int f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
int find(int x)
{
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
void Kruskal()
{
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tot;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy)
		{
			ans+=e[i].w;
			fa[fy]=fx;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),k=read();
	if(k==0)
	{
		tot=m;
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			e[i].u=read(),e[i].v=read(),e[i].w=read();
		}
		for(int j=1;j<=k;j++)
		{
			cin>>c[j];
			for(int i=1;i<=n;i++)
				cin>>spe[j][i];
		}
		Kruskal();
		printf("%lld\n",ans);
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			e[i].u=read(),e[i].v=read(),e[i].w=read();
		}
		tot=m;
		for(int j=1;j<=k;j++)
		{
			rural[j]=true;
			c[j]=read();
			for(int i=1;i<=n;i++)
			{
				spe[j][i]=read();
			}
			for(int i=1;i<=n;i++)
			{
				if(spe[j][i]==0)
				{
					for(int node=1;node<=n;node++)
					{
						if(i==node) continue;
						e[++tot].u=i;
						e[tot].v=node;
						e[tot].w=spe[j][node];
					}
				}
			}
		}
		Kruskal();
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 2 4
0 100 300 200 400
*/
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
