#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+20;
int n,m,k,fa[N];
ll ans=9e18;
struct node{ int u,v,w; }e[N];
int ecnt;
struct ncity{
	int c,w[N];
}b[15];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
ll kruskal(){
	ll ret=0;
	sort(e+1,e+1+ecnt,[](node x,node y){ return x.w<y.w; });
	for(int i=1;i<=ecnt;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		merge(u,v);
		ret+=w;
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].c;
		for(int j=1;j<=n;j++) cin>>b[i].w[j];
	}
	for(int p=0;p<(1<<k);p++){
		ecnt=m;
		ll mst=0;
		for(int i=1;i<=k;i++){
			if((p&(1<<(i-1)))){
				mst+=b[i].c;
				for(int j=1;j<=n;j++) e[++ecnt]={i+n,j,b[i].w[j]};
			}
		}
		for(int i=1;i<=n+k;i++) fa[i]=i;
		mst+=kruskal();
		ans=min(ans,mst);
	}
	cout<<ans;
	return 0;
}
