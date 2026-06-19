#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e6+10;
const int N=1e4+20;
struct node{
	ll u,v,w;
}e[M];
ll n,m,k,cnt;
ll id[N],c[N],a[N][12];
bool cmp(node a,node b){
	return a.w<b.w;
}
ll find(ll u){
	return id[u]==u?u:id[u]=find(id[u]);
}
void kruskal(){
	sort(e+1,e+m+1,cmp);
	ll cntk=0,ans=0;
	for(int i=1;i<=m;i++){
		ll ida=find(e[i].u);
		ll idb=find(e[i].v);
		if(ida==idb) continue;
		id[ida]=idb;
		ans+=e[i].w;
		cntk++;
		if(cntk==n-1) break;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) id[i]=i; 
	for(int i=1;i<=m;i++){
		//++cnt;
		cin>>e[i].u>>e[i].v>>e[i].w;
		//++cnt;
		//e[cnt].u=e[cnt-1].v;
		//e[cnt].v=e[cnt-1].u;
		//e[cnt].w=e[cnt].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[j][i];
	}
	if(k==0){
		kruskal();
		return 0;
	}
	else{
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				++m;
				e[m].u=j;
				e[m].v=n+i;
				e[m].w=a[j][i];
			}
		}
		n=n+k;
		for(int i=1;i<=n;i++) id[i]=i;
		kruskal();
	}
	return 0;
}
