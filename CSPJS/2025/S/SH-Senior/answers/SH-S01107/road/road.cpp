#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4+5, M = 1e6+5, K = 15, INF = 1e10;
struct node{
	ll head, to, wei;
}edge[M+K*N];
ll n, m, k, deg[N], ans = INF, cnt = 1;
bool cmp(node a, node b){
	return a.wei>b.wei;
}
ll SPFA(int x){
	sort(edge+1, edge+1+m+n, cmp);
	ll count = 0, tot = 0;
	for(ll i=1; i<=m+n; i++){
		count += edge[i].wei;
	}
	for(ll i=1; i<=n+m && tot<m; i++){
		if(deg[edge[i].head]>=2 && deg[edge[i].to]>=2){
			tot++;
			deg[edge[i].head]--, deg[edge[i].to]--;
			count -= edge[i].wei;
		}
	}
	return count;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	cin >> n >> m >> k;
	memset(edge, 0ll, sizeof(edge));
	for(ll i=1, u, v, w; i<=m; i++){
		cin >> u >> v >> w;
		edge[i].head = u;
		edge[i].to = v;
		edge[i].wei = w;
		deg[u]++, deg[v]++; 
	}
	sort(edge+1, edge+1+m, cmp);
	if(k == 0){
		ll tott = 0;
		for(ll i=1; i>=1 && tott<m-n+1; i--){
			if(deg[edge[i].head]>1 && deg[edge[i].to]>1){
				tott++;
				deg[edge[i].head]--, deg[edge[i].to]--;
				edge[i].wei = 0;
			}
		}
		for(ll i=1; i<=m; i++){
			ans += edge[i].wei;
		}
		cout << ans;
		return 0;
	}
	for(ll i=1, cost; i<=k; i++){
		cin >> cost;
		for(ll j=1, build; j<=n; j++){
			cin >> build;
			deg[n+1]++, deg[j]++;
			edge[m+cnt].wei = build;
			edge[m+cnt].head = j;
			edge[m+cnt].to = n+i;
			cnt++;
		}
		ans = min(ans, SPFA(i) + cost);
		for(ll j=1; j<=n; j++){
			deg[j]--;
		}
		deg[n+1] = 0;
		cnt = 1;
	}
	cout << ans;
	return 0;
}
