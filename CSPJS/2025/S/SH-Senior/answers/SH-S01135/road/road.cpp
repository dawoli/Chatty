#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k,c[15],p[10015],cnt;
long long ans;
struct edge
{
	int u,v;
	long long w;
}a[1100005];
bool cmp(edge x1,edge x2)
{
	return x1.w<x2.w;
}
int root(int x)
{
	if (p[x]==x) return x;
	return p[x]=root(p[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if (k==0)
	{
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
			if (a[i].u>a[i].v) swap(a[i].u,a[i].v);
		}
		sort(a+1,a+m+1,cmp);
		cnt=n;
		for (int i=1;i<=n;i++) p[i]=i;
		for (int i=1;i<=m;i++)
		{
			if (root(a[i].u)==root(a[i].v)) continue;
			ans+=a[i].w;
			p[root(a[i].v)]=root(a[i].u);
			cnt--;
			if (cnt==1) break;
		}
	}
	else
	{
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
			if (a[i].u>a[i].v) swap(a[i].u,a[i].v);
		}
		for (int j=0;j<k;j++)
		{
			scanf("%lld",&c[j]);
			for (int i=1;i<=n;i++)
			{
				a[m+j*n+i].u=i;
				a[m+j*n+i].v=n+1+j;
				scanf("%lld",&a[m+j*n+i].w);
			}
		}
		sort(a+1,a+m+k*n+1,cmp);
		for (int C=0;C<(1<<k);C++)
		{
			long long answer=0;
			for (int i=1;i<=n;i++) p[i]=i;
			for (int j=0;j<k;j++) p[n+j+1]=n+j+1;
			cnt=n;
			for (int j=0;j<k;j++) if (C&(1<<j)) cnt++,answer+=c[j];
			for (int i=1;i<=m+k*n&&cnt>1;i++)
			{
				if (a[i].v>n)
				{
					if ((C&(1<<(a[i].v-n-1)))==0) continue;
				}
				if (root(a[i].u)==root(a[i].v)) continue;
				answer+=a[i].w;
				p[root(a[i].v)]=root(a[i].u);
				cnt--;
				if (cnt==1) break;
			}
			if (C) ans=min(ans,answer);
			else ans=answer;
		}
	}
	printf("%lld",ans);
	return 0;
}
