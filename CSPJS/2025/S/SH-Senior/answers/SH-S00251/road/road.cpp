#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
long long ans;
int fa[10005];
int a[100005];
struct node{
	int u,v,w;
}e[100005];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void kruskal(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			fa[u]=v;
			ans+=e[i].w; 
		}
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				e[++m]={i,j,c+a[i]+a[j]};
			}
		}
	} 
	kruskal();
	return 0;
}
