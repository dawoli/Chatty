#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,u,v,w,g[10004][10004];
struct s{int u,v,w;}a[1000006];
bool cmp(s x,s y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	bool f=0;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++)
	{
		int c,x;cin>>c;
		for(int j=1;j<=n;j++) cin>>x;
	}
	if(k==0)
	{
		long long ans=0;
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			g[a[i].u][a[i].v]=g[a[i].v][a[i].u]=a[i].w;
			for(int k=1;k<=n;k++)
				for(int x=1;x<=n;x++)
					for(int y=1;y<=n;y++)
					{
						if(x==y||x==k||y==k) continue;
						if(g[x][y]>0) continue;
						if(g[x][k]>0&&g[k][y]>0) g[x][y]=g[y][x]=1;
					}
			f=1;ans+=a[i].w;
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<j;k++)
				{
					if(j==k) continue;
					if(g[j][k]==0)
					{
						f=0;
						break;
					}
				}
				if(!f) break;
			}
			if(f) break;
		}
		printf("%lld",ans);
		return 0;
	}
	cout<<0;
	return 0;
}
