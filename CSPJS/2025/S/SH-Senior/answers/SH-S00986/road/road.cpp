#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+9,M=1e6+9;
int n,m,k,ne,finans,ans;
struct edge_g{
	int u,v,w;
	bool operator < (const edge_g &a){
		return w<a.w;
	}
} e[M],e0[M];
int cst_new[20][N],c[20],fa[N];
int findroot(int u){
	if(fa[u]==u) return u;
	return fa[u]=findroot(fa[u]);
}
void uniteroot(int u,int v){
	u=findroot(u),v=findroot(v);
	fa[u]=v;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>cst_new[i][j];
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m&&ne!=n-1;i++){
		if(findroot(e[i].u)==findroot(e[i].v)) continue;
		int u=findroot(e[i].u),v=findroot(e[i].v);
		uniteroot(u,v);
		ans+=e[i].w;
		swap(e[i],e[++ne]);
	}
	finans=ans;
	m=ne;
	for(int i=1;i<=m;i++) e0[i]=e[i];
	for(int i=1;i<(1<<k);i++){
		ne=m;
		ans=0;
		for(int j=1;j<=m;j++) e[j]=e0[j];
		for(int j=1;j<=k;j++) if((1<<(j-1))&i){
			ans+=c[j];
			for(int u=1;u<=n;u++){
				e[++ne]=(edge_g){n+j,u,cst_new[j][u]};
			}
		}
		sort(e+1,e+1+ne);
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=ne;j++){
			if(findroot(e[j].u)==findroot(e[j].v)) continue;
			int u=findroot(e[j].u),v=findroot(e[j].v);
			uniteroot(u,v);
			ans+=e[j].w;
		}
		finans=min(finans,ans);
	}
	cout<<finans;
	return 0;
}

