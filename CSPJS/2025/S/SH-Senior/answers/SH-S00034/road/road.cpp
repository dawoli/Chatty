#include<bits/stdc++.h>
using namespace std;
#define _1 first
#define _2 second
using ll = long long;
using T = pair<ll,ll>;
const int N=1e4+5;
struct edge{
	int v,w;
	bool operator<(edge x){
		return w<x.w;
	}
};
vector<edge> g[N];
int n,m,k,node[15][N];
void prim(){
	ll ans=0;
	bitset<N> vis;
	priority_queue<T,vector<T>,greater<T>> q;
	vis[1]=1;
	for(edge p:g[1]) q.push({p.w,p.v});
	while(!q.empty()){
		T t=q.top();
		q.pop();
		int v=t._2,w=t._1;
		if(vis[v]) continue;
		ans+=w;
		vis[v]=1;
		for(edge p:g[v]){
			q.push({p.w,p.v});
		}
	}
	cout<<ans;
	return;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>node[i][j];
		}
	}
	if(k==0){
		prim();
		return 0;
	}
	ll ans=1e18;
	for(int _=0;_<(1<<k);_++){
		bitset<10> lit(_);
		ll c=0;
		for(int i=0;i<k;i++){
			if(lit[i]) c+=node[i+1][0];
		}
		bitset<N> vis;
		priority_queue<T,vector<T>,greater<T>> q;
		vis[1]=1;
		for(edge p:g[1]) q.push({p.w,p.v});
		for(int i=0;i<k;i++){
			if(lit[i]){
				for(int j=2;j<=n;j++){
					q.push({node[i+1][j]+node[i+1][1],j});
				}
			}
		}
		while(!q.empty()){
			T t=q.top();
			q.pop();
			ll v=t._2,w=t._1;
			if(vis[v]) continue;
			c+=w;
			vis[v]=1;
			for(edge p:g[v]){
				if(vis[p.v]) continue;
				q.push({p.w,p.v});
			}
			for(int i=0;i<k;i++){
				if(lit[i]){
					for(int j=1;j<=n;j++){
						if(j==v or vis[j]) continue;
						q.push({node[i+1][j]+node[i+1][v],j});
					}
				}
			}
		}
		ans=min(ans,c);
	}
	cout<<ans;
}
