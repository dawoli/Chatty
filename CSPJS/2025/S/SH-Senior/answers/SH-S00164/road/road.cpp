#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
struct node{
	int u,v,w;
}e[1100005];
int c[15],edge=0,fa[1000010];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	else {
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void add(int x,int y){
	fa[find(y)]=find(x);
}
bool check(){
	int f=find(1);
	for(int i=2;i<=n;i++)if(find(i)!=f) return false;
	return true; 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
 	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	}
	if(k==0) {
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int x=e[i].u,y=e[i].v;
			if(find(x)==find(y)) continue;
			else{
				add(x,y);edge++;
				ans+=e[i].w;
			} 
			if(edge==n-1){
				cout<<ans;
				return 0;
			} 
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,x;j<=n;j++){
			cin>>x;++m;
			e[m].u=n+i;
			e[m].v=j;
			e[m].w=x;
		}
	} 
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v;
		if(find(x)==find(y)) continue;
		else{
			add(x,y);edge++;
			ans+=e[i].w;
			if(x>n) ans+=c[x-n];
		} 
		if(edge>=n-1){
			if(check()) {cout<<ans;break;}
		} 
	}
	return 0;
}
