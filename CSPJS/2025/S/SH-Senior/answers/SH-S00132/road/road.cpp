#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#define ll long long
#define RP return
#define PLUSplus 0
using namespace std;

struct Edge{
	ll v, w;
};

struct COMpare{
	bool operator()(Edge x, Edge y){
		return x.w > y.w;
	}
};

ll n, m, k;
ll ans = 0x3f3f3f3f3f3f3f3f;
ll o[20][11000] = {0};
vector<vector<Edge>> a(11000, vector<Edge>(0, {0, 0}));

ll Prim(int l){
	ll dist[11000];
	bool vis[11000] = {0};
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	for(int i = 0; i < l; i++){
		int minind = 0;
		for(int j = 1; j <= l; j++){
			if(dist[j] < dist[minind] && !vis[j]){
				minind = j;
			}
		}
		vis[minind] = 1;
		for(int j = 0; j < a[minind].size(); j++){
			if(!vis[a[minind][j].v]) dist[a[minind][j].v] = min(dist[a[minind][j].v], a[minind][j].w);
		}
	}
	ll suma = 0;
	for(int i = 1; i <= l; i++){
		suma += dist[i];
	}
//	for(int i = 1; i <= l; i++){
//		cout << dist[i] << ' ';
//	}
//	cout << endl;
	return suma;
}

ll Kruscal(int l){
	priority_queue<Edge, vector<Edge>, COMpare> pq;
	bool vis[11000] = {0};
	ll suma = 0;
	pq.push((Edge){1, 0});
	for(int i = 0; i < l; i++){
//		if(pq.empty()){
//			cout << "error!";
//			return 0;
//		}
		Edge ne = pq.top();
		while(vis[ne.v]){
			//cout << '&' << ne.v << ' ' << ne.w << '&';
			pq.pop();
//			if(pq.empty()){
//				cout << "error!";
//				return 0;
//			}
			ne = pq.top();
		}
		//cout << '*' << ne.v << ' ' << ne.w << '*';
		pq.pop();
		suma += ne.w;
		vis[ne.v] = 1;
		for(int j = 0; j < a[ne.v].size(); j++){
			if(!vis[a[ne.v][j].v]) pq.push(a[ne.v][j]);
		}
	}
	return suma;
}

void dfs1(int depth, int cnt, int totalcost){
	if(depth > k){
		//cout << '*' << totalcost + Prim(n + cnt);
		ans = min(ans, totalcost + Prim(n + cnt));
		return;
	}
	dfs1(depth + 1, cnt, totalcost);
	cnt++;
	for(int i = 1; i <= n; i++){
		a[n + cnt].push_back((Edge){i, o[depth][i]});
		a[i].push_back((Edge){n + cnt, o[depth][i]});
	}
	dfs1(depth + 1, cnt, totalcost + o[depth][0]);
	a[n + cnt].clear();
	for(int i = 1; i <= n; i++){
		a[i].pop_back();
	}
	return;
}

void dfs2(int depth, int cnt, int totalcost){
	if(depth > k){
		//cout << '*' << totalcost + Kruscal(n + cnt);
		ans = min(ans, totalcost + Kruscal(n + cnt));
		return;
	}
	dfs2(depth + 1, cnt, totalcost);
	cnt++;
	for(int i = 1; i <= n; i++){
		a[n + cnt].push_back((Edge){i, o[depth][i]});
		a[i].push_back((Edge){n + cnt, o[depth][i]});
	}
	dfs2(depth + 1, cnt, totalcost + o[depth][0]);
	a[n + cnt].clear();
	for(int i = 1; i <= n; i++){
		a[i].pop_back();
	}
	return;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back((Edge){y, z});
		a[y].push_back((Edge){x, z});
	} 
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++){ // o[i][0] = cost[i]
			cin >> o[i][j];
		}
	}
	//cout << Kruscal(n);
	if(n * n <= 6 * m){
		dfs1(1, 0, 0);
	}else{
		dfs2(1, 0, 0);
	}
	cout << ans;
	
	RP PLUSplus;
}
