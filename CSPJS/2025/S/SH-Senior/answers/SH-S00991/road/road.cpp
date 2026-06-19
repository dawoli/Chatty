#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define pi pair<int, int>
#define int long long
const int maxn = 1e4 + 45;
const int inf = 1e18;
int n, m, k;
int c[maxn];

int vst[maxn];
int d[maxn];
vector<pi> g[maxn];
queue<int> p;
void solve(){
	
	for(int i = 1; i <= n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	
	fill(d + 1, d + n + 1, inf);
	d[1] = 0, vst[1] = 1;
	p.push(1);
	
	int ans = 0;
	
	while(!p.empty()){
		int u = p.front();
		p.pop();
		
		for(pi v : g[u]){
			if(d[v.first] > d[u] + v.second){
				if(!vst[v.first]) p.push(v.first), vst[v.first] = 1, ans += v.second;
				else ans -= (d[v.first] - d[u]);
				
				d[v.first] = d[u] + v.second;
			}
		}
	}
	
//	for(int i = 1; i <= n; i++) cout << d[i] << ' ';
	 
	cout << ans << '\n';
	exit(0);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	if(k == 0) solve();
	
	for(int i = 1; i <= n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	
	bool flaga = true;
	for(int i = n + 1; i <= n + k; i++){
		cin >> c[i];
		if(c[i] != 0) flaga = false;
		for(int j = 1; j <= n; j++){
			int w;
			cin >> w;
			g[i].push_back({j, w});
			g[j].push_back({i, w});
		}
	}
	
//	if(flaga && n <= 1000) solvea();
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
