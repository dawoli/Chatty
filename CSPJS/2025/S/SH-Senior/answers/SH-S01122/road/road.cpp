#include <cstdio>
#include <algorithm>
using namespace std;
const int N=10100;
const int M=1001000;
const int K=13;
const long long INF=1e16;
struct edge
{
	int u,v,w;
};
edge e[M],e_add[N*K];
int c[K],a[K][N];
int cmp(edge a,edge b)
{
	return (a.w<b.w);
}
long long min(long long a,long long b)
{
	return (a < b) ? a : b;
}
int fa[N];
int findx(int x)
{
	if(fa[x]!=x) fa[x]=findx(fa[x]);
	return fa[x];
}
void unionn(int a,int b)
{
	int x=findx(a),y=findx(b);
	fa[x]=y;
}
int read()
{
	int num=0,k=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		num=num*10+c-'0';
		c=getchar();
	}
	return num*k;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	long long minx=INF;
	for(int i=0;i<(1<<k);i++)
	{
		long long ans=0;
		int tot=0,add=0;
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				ans+=c[j];
				add++;
				for(int l=1;l<=n;l++)
				{
					e_add[++tot].u=n+add;
					e_add[tot].v=l;
					e_add[tot].w=a[j][l];
				}
			}
		}
		sort(e_add+1,e_add+1+tot,cmp);
		for(int j=1;j<=n+add;j++)
		{
			fa[j]=j;
		}
		int cnt=0;
		for(int pos1=1,pos2=1;pos1<=m || pos2<=tot;)
		{
			int u,v;
			if(pos1>m || (pos2<=tot && e_add[pos2].w<e[pos1].w))
			{
				u=e_add[pos2].u,v=e_add[pos2].v;
				u=findx(u);v=findx(v);
				if(u!=v)
				{
					fa[u]=v;
					ans+=e_add[pos2].w;
					cnt++;
				}
				pos2++;
			}
			else if(pos2>tot || (pos1<=m && e_add[pos2].w>=e[pos1].w))
			{
				u=e[pos1].u,v=e[pos1].v;
				u=findx(u);v=findx(v);
				if(u!=v)
				{
					fa[u]=v;
					ans+=e[pos1].w;
					cnt++;
				}
				pos1++;
			}
			if(cnt==n+add-1) break;
			if(ans>=minx) break;
		}
		minx=min(minx,ans);
	}
	printf("%lld\n",minx);
	fclose(stdin);fclose(stdout);
	return 0;
}
