//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N= 1e6+85;



int n, m, k, first[N], ans;

struct egde{
	int v, nxt, w;
}e[2*N];

int idx;

void dijkstra(int n){
	
}

void add_edge(int u , int v, int w){
	idx++;
	e[u].w = w;
	e[u].v = v;
	first[u] = idx;
	e[idx].nxt = first[u];
}

signed main(){
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	for(int i = 1; i <= k; ++i){
		
	}
	dijkstra(1);
	cout << ans;
	return 0;
} 
