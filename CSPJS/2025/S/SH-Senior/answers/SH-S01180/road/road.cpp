#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=8009,M=1000009,K=19,INF=1e10;
ll n,m,k;
ll e[N][N];
ll cnt=0;
ll vis[N];
struct Edge{
	ll u,v;
	bool operator<(const Edge&a)const{
		return e[u][v]>e[a.u][a.v];
	}
};
void mintree(){
	priority_queue<Edge>q;
	vis[1]=1;
	for(ll i=2;i<=n;i++){
		if(e[1][i]>=0){
			q.push((Edge){1,i});
		}
	}
	ll sum=0;
	while(!q.empty()){
		Edge ed=q.top();
		q.pop(); 
		ll u=ed.u;
		ll v=ed.v;
		ll w=e[ed.u][ed.v];
		if(vis[v]){
			continue;
		}
		vis[v]=1;
		sum+=w;
		for(ll i=1;i<=n;i++){
			if(e[v][i]>=0&&i!=v){
				q.push((Edge){v,i});
			}
		}
	}
	cout<<sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			e[i][j]=INF;
		}
	}
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e[u][v]=w;
		e[v][u]=w;
	}
	for(ll i=1;i<=k;i++){
		ll c;
		cin>>c;
		for(ll i=1;i<=n;i++){
			ll a[N];
			cin>>a[i];
			for(ll j=i-1;j;j--){
				if(c+a[i]+a[j]<e[i][j]){
					e[i][j]=c+a[i]+a[j];
					e[j][i]=c+a[i]+a[j];
				}
			}
		}
	}
	mintree(); 
	return 0;
}
