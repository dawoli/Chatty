#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e4;
const int M = 0x3f3f3f3f;

int n, m, k, W;
struct Road{
	int u, v, w, c;
};
vector<Road> road;

bool visit[maxn][maxn];

void dfs(int i, bool flag, int w){
	
}



signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	   
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		road.push_back({u, v, w, 0});
		W += w;
	}
	for(int i = 1; i <= k; i++){
		int c;
		cin >> c;
		for(int j = 1; j <= n; i++){
			int a;
			cin >> a;
			road.push_back({i, j, a, c});
		}
	}
	
	if(n >= m){
		cout << W;
		return 0;
	}
	if(k == 0){
		//solve();
	}

	cout.tie(0);
	return 0;
}
