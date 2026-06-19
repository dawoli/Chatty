#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10,M=1e6+10,K=15;
struct Edge{
	int u,v,w;
	bool operator < (const Edge& edge) const {
		return w<edge.w;
	}
};
int n,m,k,ans,c[K],a[K][N],fa[N+K];
Edge g[M<<1];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>g[i].u>>g[i].v>>g[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			g[++m]={n+i,j,a[i][j]};
		}
	}
	sort(g+1,g+m+1);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(g[i].u),y=find(g[i].v);
		if(x==y) continue;
		fa[x]=y;
		ans+=g[i].w;
	}
	cout<<ans;
	return 0;
}
