#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e4+15,MAXM=1e6+1e5+5;
int n,m,k,cnt,ans,cnt0,fa[MAXN];
struct node{
	int u,v,w;
	bool operator<(const node&x){
		return w<x.w;
	}
}e[MAXM];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
void kruskal(){
	sort(e+1,e+cnt+1);
	for(int i=1;i<=cnt&&cnt0<n+k;i++){
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
			cnt0++;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int u;
			cin>>u;
			e[++cnt]={i+n,j,u};
		}
	}
	kruskal();
	cout<<ans<<endl;
	return 0;
}
