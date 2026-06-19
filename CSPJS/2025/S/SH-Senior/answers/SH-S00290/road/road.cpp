#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
}G[10005];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long n,m,k,c[15],cnt,fa[10005],ans,a[15][10005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
long long kruskal(int n_){
	long long ret=0;
	sort(G+1,G+1+cnt,cmp);
	for(int i=1;i<n_;i++){
		int p=G[i].u,q=G[i].v;
		if(find(p)!=find(q)){
			merge(p,q);
			ret+=G[i].w;
			cout<<G[i].w<<endl;
		}
		else n_++;
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		G[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<j;l++){
				G[++cnt]={j,l,a[i][j]+c[i]+a[i][l]};
			}
		}
	}
	ans=kruskal(n);
	
	for(int i=1;i<=k;i++){
		
	}
	cout<<ans;
	return 0;
}
