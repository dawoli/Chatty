#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int u, v, w;
} edge[1000005];
int n, m, k, ans, fa[10005];
bool cmp(const Edge &n1, const Edge &n2){
	return n1.w < n2.w;
}
int find(int x){
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	fa[find(x)] = find(y);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i){
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	
	if(k == 0){
		sort(edge + 1, edge + m + 1, cmp);
		for(int i = 1; i <= n; ++ i)
			fa[i] = i;
		
		for(int i = 1; i <= m; ++ i){
			if(find(edge[i].u) != find(edge[i].v)){
				merge(edge[i].u, edge[i].v);
				ans += edge[i].w;
			}
		}
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
