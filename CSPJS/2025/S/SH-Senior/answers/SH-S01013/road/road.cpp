/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10009,M=1e6+9;
ll n,m,k,c[19],rrw[19][N];
//vector<ll> to[N];
struct Edge{
	ll u,v,w;
	bool operator<(const Edge &a)const{
		return a.w<w;
	}
};
//ll hd[N],to[2*M+20008],next[2*M+20008],w[2*M+20080];//?
ll rt[N];
ll root(ll u){
	if(rt[u]==u) return u;
	return rt[u]=root(rt[u]);
}
void solve0(){
	priority_queue<Edge> q;	
	for(ll i=1;i<=m;i++){
		ll u,v,wi;
		cin>>u>>v>>wi;
//		w[i*2-1]=w[i*2]=wi;
//		to[i*2-1]=hd[u];
//		hd[u]=i*2-1;
//		to[i*2]=hd[v];
//		hd[v]=i*2;
		Edge e={u,v,wi};
		q.push(e);
	}
//	bool vis[N];
//	memset(vis,0,sizeof(vis));
	ll ans=0;
	for(ll i=1;i<=n;i++) rt[i]=i;
	while(!q.empty()){
		Edge e=q.top();
		q.pop();
		if(root(e.u)!=root(e.v)){
			ans+=e.w;
//			vis[e.u]=vis[e.v]=1;
			rt[root(e.u)]=rt[root(e.v)];
//			cout<<"edge "<<e.u<<' '<<e.v<<' '<<e.w<<endl;
//			cout<<"nowrt "<<rt[e.u]<<' '<<rt[e.v]<<endl; 
		}
	}
	cout<<ans<<endl;
}
map<ll,ll> road_to_rr;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		solve0();
		return 0;	
	}
	
	priority_queue<Edge> q;
//	queue<Edge> Q;	
	for(ll i=1;i<=m;i++){
		ll u,v,wi;
		cin>>u>>v>>wi;
//		w[i*2-1]=w[i*2]=wi;
//		to[i*2-1]=hd[u];
//		hd[u]=i*2-1;
//		next[hd[u]]=v;
//		to[i*2]=hd[v];
//		hd[v]=i*2;
//		next[hd[v]]=u;
		Edge e={u,v,wi};
////		Q.push(e);
		q.push(e);
	}
	//加边
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++) 
			cin>>rrw[i][j];
	}
	for(ll u=1;u<=n;u++){
		for(ll v=1;v<=n;v++){
			if(u==v) continue;
			for(ll i=1;i<=k;i++){
				q.push((Edge){u,v,rrw[i][u]+rrw[i][v]});
			}
		}
	}
	//最小生成树 
	ll ans=0;
	for(ll i=1;i<=n;i++) rt[i]=i;
	while(!q.empty()){
		Edge e=q.top();
		q.pop();
		if(root(e.u)!=root(e.v)){
			ans+=e.w;
			rt[root(e.u)]=rt[root(e.v)];
		}
	}
	cout<<ans<<endl;
	return 0;
}
