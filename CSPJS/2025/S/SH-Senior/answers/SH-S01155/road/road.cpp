#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e4+18;
const ll INF = 1e6;

ll n,m,k,c[N],dis[N];
bool vis[N],rb[N];
vector <pair<ll,ll> > edgs[N];

void dijkstra(ll s) {
	memset(dis,INF,sizeof(dis));
	memset(vis,false,sizeof(vis));
	
	priority_queue <pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
	pq.push({0,s});
	dis[s] = 0;
	while(!pq.empty()) {
		ll u = pq.top().second;
		pq.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(ll i = 0;i < edgs[u].size();i++) {
			ll v = edgs[u][i].first, w = edgs[u][i].second;
			if(dis[v] >= dis[u]+w+(v > n ? c[v-n] : 0)) {
				dis[v] = dis[u]+w+(v > n ? c[v-n] : 0);
				pq.push({dis[v],v});
			}
		}
	}
	return;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i = 1,u,v,w;i <= n;i++) {
		scanf("%lld %lld %lld",&u,&v,&w);
		edgs[u].push_back({v,w});
		edgs[v].push_back({u,w});
	}
	for(ll u = 1;u <= k;u++) {
		scanf("%lld",&c[u]);
		for(ll v = 1,w;v <= n;v++) {
			scanf("%lld",&w);
			edgs[u+n].push_back({v,w});
			edgs[v].push_back({u+n,w});
		}
	}
	
	dijkstra(1);
	
	ll ans = -1;
	for(ll i = 1;i <= n;i++) {
		ans = max(ans,dis[i]);
	}
	printf("%lld\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
