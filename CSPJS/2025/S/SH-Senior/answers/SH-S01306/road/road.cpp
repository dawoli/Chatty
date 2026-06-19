#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+5;
struct Edge{
	ll u,v,w;
};
ll parent[N];
ll n,m,k;
const ll INF=1e18;
void init(ll node_num){
	for(ll i=1;i<=node_num;i++){
		parent[i]=i;
	}
}
ll find(ll x){
	if(x!=parent[x]) return x=find(parent[x]);
	return parent[x];
}
bool merge(ll x,ll y){
	ll px=find(x),py=find(y);
	if(px==py){
		return false;
	}
	else{
		parent[py]=px;
		return true;
	}
}
ll kruskal(vector<Edge>& vec,ll node_num){
	ll total_distance=0;
	ll cnt=0;
	for(ll i=0;i<vec.size();i++){
		ll pu=vec[i].u;
		ll pv=vec[i].v;
		ll w=vec[i].w;
		if(merge(pu,pv)){
			total_distance+=w;
			cnt++;
		}
		if(cnt==node_num-1){
			return total_distance;
			break;
		}
	}
}
bool cmp(Edge a, Edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vector<Edge> edges;
	init(n);
	for(ll i=0;i<m;i++){
		Edge e;
		cin>>e.u>>e.v>>e.w;
		edges.push_back(e);
	}
	sort(edges.begin(),edges.end(),cmp);
	ll ans=kruskal(edges,n);
	//cout<<ans<<endl;
	ll node_num=n;
	for(ll i=0;i<k;i++){
		ll c;
		vector<ll> cost(n);
		cin>>c;
		for(ll j=0;j<n;j++){
			cin>>cost[i];
		}
		//add edges
		node_num++;
		for(ll j=0;j<n;j++){
			Edge e;
			e.u=node_num;
			e.v=j+1;
			e.w=c+cost[j];
			edges.push_back(e);
		}
		//sort
		sort(edges.begin(),edges.end(),cmp);
		init(node_num);
		//kruskal for ans
		ans=min(ans,kruskal(edges,node_num));
	}
	cout<<ans<<endl;
	return 0;
}
