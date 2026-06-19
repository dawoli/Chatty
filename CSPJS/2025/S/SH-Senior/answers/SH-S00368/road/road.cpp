#include<bits/stdc++.h>
using namespace std;

const int N=10004,M=1000006,INF=2147483647;
struct Node
{
	long long u,v,w;
};
Node edge[M],tree[M];
long long a[12][N],c[12];
int f[N],mm;
int root(int fa)
{
	if(fa==f[fa])
		return fa;
	return f[fa]=root(f[fa]);
}
int fun(int i,int j)
{
	if(i<j)
		swap(i,j);
	if(i==2)
		return 1;
	return (i-2)*(i-1)/2+j;
}
bool cmp1(Node a,Node b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=0;
	long long ans=0,sum=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	sort(edge+1,edge+1+m,cmp1);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;cnt<n-1&&i<=m;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(root(u)==root(v)) continue;
		ans+=w;
		f[root(u)]=root(v);
	}
	if(k==0)
		cout<<ans;
	else
	{
		for(int kkk=1;kkk<(1<<k);kkk++)
		{
			mm=0;sum=0;cnt=0;
			for(int t=1;t<=k;t++)
				if(kkk&(1<<(t-1)))
					sum+=c[t]; 
			for(int i=1;i<=n;i++)
				for(int j=1;j<i;j++)
				{
					int locat=fun(i,j);
					tree[locat].u=i;tree[locat].v=j;tree[locat].w=INF;mm++;
					for(int t=1;t<=k;t++)
						if(kkk&(1<<(t-1)))
							tree[locat].w=min(tree[locat].w,a[t][i]+a[t][j]);
				}
			for(int i=1;i<=m;i++)
			{
				int locat=fun(edge[i].u,edge[i].v);
				tree[locat].w=min(tree[locat].w,edge[i].w);
			}
			sort(tree+1,tree+1+mm,cmp1);
			for(int i=1;i<=n;i++) f[i]=i;
			for(int i=1;cnt<n-1&&i<=mm;i++)
			{
				int u=tree[i].u,v=tree[i].v,w=tree[i].w;
				if(root(u)==root(v)) continue;
				sum+=w;
				f[root(u)]=root(v);
			}
			ans=min(ans,sum);
		}
		cout<<ans;
	}
	return 0;
}
