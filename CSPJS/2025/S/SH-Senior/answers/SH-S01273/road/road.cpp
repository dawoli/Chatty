#include<bits/stdc++.h>
using namespace std;
long long a,b,c,n,m,l,fa[100010],cnn[10010],sum,cnt,ok,ans;
long long g[1010][1010];
struct stu{
	long long u,v,w;
}p[4000010];
bool cmp(stu a,stu b)
{
	return a.w<b.w;
}
int root(int x)
{
	if(fa[x]==x) return x;
	fa[x]=root(fa[x]);
	return fa[x];
}
void unt(int x,int y)
{
	fa[root(x)]=root(y);
	return ;
}
void kru()
{
	for(int i=1;i<=cnt;i++)
	{
		if(fa[p[i].u]==fa[p[i].v]) continue;
		unt(fa[p[i].u],fa[p[i].v]);
		ans+=p[i].w;
		ok++;
		if(ok==n-1) break;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%lld%lld%lld",&n,&m,&l);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if(g[a][b])
		{
			g[a][b]=min(g[a][b],c);
			g[b][a]=min(g[b][a],c);
		}
		else
		{
			g[a][b]=c;
			g[b][a]=c;
		}
	}
	for(int i=1;i<=l;i++)
	{
		long long v;
		scanf("%lld",&v);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&cnn[j]);
			for(int k=1;k<j;k++)
			{
				sum=v+cnn[j]+cnn[k];
				if(!g[k][j])
				{
					g[k][j]=sum;
					g[j][k]=sum;
				}
				else if(g[k][j])
				{
					g[k][j]=min(g[k][j],sum);
					g[j][k]=min(g[j][k],sum);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(g[i][j])
			{
				cnt++;
				p[cnt].u=i;
				p[cnt].v=j;
				p[cnt].w=g[i][j];
			}
		}
	}
	sort(p+1,p+cnt+1,cmp);
	kru();
	printf("%lld",ans);
	return 0;
}
