#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=10024,M=1000006;
ll n,m,k,rt[N+19],c[19],a[19][N];
ll root(ll u){
	if(rt[u]==u)return u;
	return rt[u]=root(rt[u]);
}
bool ifcon(ll u,ll v){
	return root(u)==root(v);
}
void conn(ll u,ll v){
	rt[root(u)]=root(v);
}
struct edge{
	ll u,v,w;
	bool operator<(const edge&a)const{
		return w<a.w;
	}
}e[M],g[N*19],d[19][N];
struct node{
	ll j,i,w;
	bool operator<(const node&a)const{
		return w>a.w;
	}
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(ll j=1;j<=k;++j){
		cin>>c[j];
		for(ll i=1;i<=n;++i){
			cin>>a[j][i];
		}
	}
	sort(e+1,e+1+m);
	for(ll i=1;i<=n;++i){
		rt[i]=i;
	}
	ll ans=0;
	for(ll i=1,j=1;i<=m;++i){
		if(!ifcon(e[i].u,e[i].v)){
			ans+=e[i].w;
			conn(e[i].u,e[i].v);
			if(i!=j){
				swap(e[i],e[j]);
			}
			j++;
		}
	}
	for(ll j=1;j<=k;++j){
		for(ll i=1;i<=n;++i){
			d[j][i]=(edge){i,n+j,a[j][i]};
		}
		sort(d[j]+1,d[j]+1+n);
	}
	priority_queue<node> pq;
	for(ll x=(1<<k)-1;x>0;--x){
		for(ll i=1;i<=n+k;++i){
			rt[i]=i;
		}
		ll nwans=0,tope=0;
		pq.push((node){0,1,e[1].w});
		for(ll j=1;j<=k;++j)if(x&(1<<(j-1))){
			nwans+=c[j];
			pq.push((node){j,1,d[j][1].w});
		}
		node nd;
		for(ll j=1;!pq.empty();++j){
			tope++;
			nd=pq.top();
			pq.pop();
			if(nd.j==0){
				g[tope]=e[nd.i];
				if(nd.i<n-1){
					pq.push((node){0,nd.i+1,e[nd.i+1].w});
				}
			}
			else{
				g[tope]=d[nd.j][nd.i];
				if(nd.i<n){
					pq.push((node){nd.j,nd.i+1,d[nd.j][nd.i+1].w});
				}
			}
			if(!ifcon(g[j].u,g[j].v)){
				nwans+=g[j].w;
				conn(g[j].u,g[j].v);
				if(nwans>=ans)break;
			}
		}
		while(!pq.empty())pq.pop();
		ans=min(ans,nwans);
	}
	cout<<ans<<"\n";
	return 0;
}
