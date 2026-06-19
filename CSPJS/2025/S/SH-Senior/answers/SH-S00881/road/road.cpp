#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,k;
struct node
{
	int u,v,w;
}a[1100005];
int f[10020],sz[10020];
long long sum=0;
int c[15],d[15][10005];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void Union(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	if(sz[fx]>sz[fy])
	{
		f[fy]=fx;
		sz[fx]+=sz[fy];
	}
	else
	{
		f[fx]=fy;
		sz[fy]+=sz[fx];
	}
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	bool flag=1;
	for(int i = 1;i <= k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)flag=0;
		bool ff=1;
		for(int j = 1;j <= n;j++)
		{
			cin>>d[i][j];
			if(d[i][j]==0)ff=0;
		}
		if(ff==1)flag=0;
	}
	if(!flag)
	{
		long long ans=1e14;
		for(int i = 0;i <= (1<<k)-1;i++)
		{
			for(int j = 1;j <= n+k;j++)
			{
				f[j]=j;
				sz[j]=1;
			}
			long long sum=0;
			int cur=m;
			int t=i;
			int num=0;
			for(int j = 1;j <= k;j++)
			{
				if(t%2==1)
				{
					sum+=c[j];
					num++;
					for(int l = 1;l <= n;l++)
					{
						a[++cur]={n+j,l,d[j][l]};
					}
				} 
				t/=2;
			}
			sort(a+1,a+cur+1,cmp);
			int cnt=0;
			for(int i = 1;i <= cur;i++)
			{
				if(cnt==n+num-1)break;
				if(find(a[i].u)!=find(a[i].v))
				{
					Union(a[i].u,a[i].v);
					sum+=a[i].w;
					cnt++;
				}
			}
			ans=min(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	for(int i = 1;i <= n+k;i++)
	{
		f[i]=i;
		sz[i]=1;
	}
	int cur=m;
	for(int i = 1;i <= k;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			a[++cur]={n+i,j,d[i][j]};
		}
	}
	sort(a+1,a+cur+1,cmp);
	int cnt=0;
	long long ans=0;
	for(int i = 1;i <= cur;i++)
	{
		if(cnt==n+k-1)break;
		if(find(a[i].u)!=find(a[i].v))
		{
			Union(a[i].u,a[i].v);
			ans+=a[i].w;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
} 
