#include<bits/stdc++.h>
using namespace std;
int n, m, k, vis[10010], maxv;
vector<vector<pair<int, int>>> g(10010); 
struct sta{
	int v,w;
	bool operator<(sta y)const{
		return w>y.w;
	}
};
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
//	for(int i = 0, u, w; i < k; i++) {
//		cin >> u >> w;
//		for(int j = 0; j < n; j++)
//		g[u].push_back({v, w});
//	}
	priority_queue<sta> q;
	for(auto v:g[0]) q.push({v.first, v.second});
	while(!q.empty()) {
		auto v = q.top(); q.pop();
		if(vis[v.v]) continue;
		vis[v.v] = v.w;
		for(auto nxt:g[v.v]) 
			q.push({nxt.first, v.w + nxt.second});
	}
	for(int i = 0; i < n; i++) maxv = max(maxv, vis[i]);
	cout<<maxv;
	return 0;
} 
