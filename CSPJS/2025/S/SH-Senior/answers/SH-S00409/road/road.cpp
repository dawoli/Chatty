#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e7+5;
int n,m,k,cnt=0,tmp,fa[N],c[N],ans=0,inQ[N];
struct node{
	int u,v,w;
}e[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
void Kruskal(){
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
			//cout<<ans<<endl;
			//cout<<e[i].w<<endl;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		e[i].u=u; e[i].v=v; e[i].w=w;
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w; cin>>w;
			cnt++;
			e[cnt].u=n+i; e[cnt].v=j; e[cnt].w=w;
		}
	}
	Kruskal();
	if(k==0){
		cout<<ans<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}
