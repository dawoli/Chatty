#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge{
	int u,v;
	ll w;
};

bool operator>(const edge& a,const edge& b){
	return (a.w>b.w);
}

int n,m,k;

inline int getn(int i){
	return n+i;
}

priority_queue<edge,vector<edge>,greater<edge>> pq;

int fa[10025],h[10025];

int seek(int u){
	return (fa[u]==u?u:fa[u]=seek(fa[u]));
}

bool merge(int u,int v){
	u=seek(u),v=seek(v);
	if(u==v) return 0;
	if(h[u]<h[v]) swap(u,v);
	fa[v]=u;
	h[u]+=h[v],h[v]=0;
	return 1;
}

ll ans;

void kru(){
	while(h[seek(1)]<n+k){
		edge e=pq.top();pq.pop();
		int u=e.u,v=e.v;
		ll w=e.w;
		
		if(merge(u,v)){
			ans+=w;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		pq.push({u,v,w});
	}
	
	for(int i=1;i<=k;++i){
		int u=getn(i),c;
		cin>>c;
		for(int j=1;j<=n;++j){
			int w;
			cin>>w;
			pq.push({j,u,w}); 
		}
	}
	
	for(int u=1;u<=n+k;++u) fa[u]=u,h[u]=1;
	
	kru();
	
	cout<<ans<<endl;
	
	return 0;
}
