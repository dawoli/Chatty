#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10,maxm=1e6+10;
struct edge{
	int u,v,w;
}e[maxm];
int g[maxn][maxn];
int n,m,k;
int c[11],a[11][maxn];
bool nc[11],vis[maxn];
bool cmp(edge x,edge y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n;i++)
	  for(int j=0;j<=n;j++)
	    g[i][j]=0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g[x][y]=g[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
		if(c[i]==0)nc[i]=true;
	}
	for(int i=1;i<=k;i++){
		for(int u=1;u<=n;u++)
		  for(int v=1;v<=n;v++){
		  	if(c[i]+a[i][u]+a[i][v]<=g[u][v]){
		  		g[u][v]=g[v][u]=a[i][u]+a[i][v];nc[i]=true;
			  }
			else if(a[i][u]+a[i][v]<=g[u][v] && nc[i]){
				g[u][v]=g[v][u]=a[i][u]+a[i][v];
			} 
		  }
	}
	for(int u=1;u<=n;u++)
	  for(int v=1;v<=n;v++)
	    for(int r=1;r<=n;r++)
	      g[u][v]=min(g[u][v],g[u][r]+g[r][v]);
	int elen=0;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++){
	 	if(g[i][j]<0x3f3f3f3f)e[elen++]=edge{i,j,g[i][j]};
	 }
	sort(e,e+elen,cmp);
	long long ans=0;
	for(int i=1;i<=k;i++)if(nc[i])ans+=c[i]*1ll;
	for(int i=0;i<elen;i++){
		for(int j=1;j<=n;j++){
			if(!vis[j])break;
			if(j==n){
				printf("%lld",ans);
				return 0;
			}
		}
		if(vis[e[i].u]==vis[e[i].v] && vis[e[i].u]==true)continue;
		vis[e[i].u]=vis[e[i].v]=true;
		ans+=e[i].w*1ll;
	}
	return 0;
}
