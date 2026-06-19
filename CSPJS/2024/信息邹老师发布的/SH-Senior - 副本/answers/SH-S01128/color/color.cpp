#include<bits/stdc++.h>
using namespace std;
const int N=2e3+2;
int n,ans,a[N],sum[N],f[N][N];
bool vis[N][N];
int dfs(int u,int v)
{
	if(u<v)
		swap(u,v);
	if(vis[u][v])
		return f[u][v];
	vis[u][v]=true;
	if(u==v+1)
		for(int i=0;i<=v-1;i++)
			f[u][v]=max(f[u][v],dfs(i,v)+(a[i]==a[u])*a[u]);
	else if(u>v+1)
		f[u][v]=max(f[u][v],dfs(u-1,v)+(a[u]==a[u-1])*a[u]);
	ans=max(ans,f[u][v]);
	return f[u][v];
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+(a[i]==a[i-1])*a[i];
		memset(f,0,sizeof(f));
		memset(vis,false,sizeof(vis));
		ans=0;
		for(int i=0;i<=n;i++)
			dfs(n,i);
		printf("%d\n",ans);
	}
}
