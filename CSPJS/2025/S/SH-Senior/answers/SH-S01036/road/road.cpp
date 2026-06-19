#include<bits/stdc++.h>
using namespace std;
long long n, m, k, pa[100005], ans, ck[15], troad[15][10005];
priority_queue<pair<int, pair<int, int> > > pq;
vector<pair<int, int>> g[100005];
int find(int x){
	if(pa[x] == x) return x;
	return pa[x] = find(pa[x]);
}
bool query(int a, int b){
	return find(a) == find(b);
}
void merge(int a, int b){
	pa[find(a)] = find(b);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
		pq.push({-c, {a, b}});
	}
	for(int i = 1; i <= k; i++){
		cin >> ck[i];
		for(int j = 1; j <= n; j++) cin >> troad[i][j];
	}
	for(int i = 1; i <= n; i++) pa[i] = i;
	ans += pq.top().first;
	pa[pq.top().second.first] = pq.top().second.second;
	merge(pq.top().second.second, pq.top().second.first);
	pq.pop();
	while(!pq.empty()){
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		if(!query(a, b)){
			merge(a, b);
			ans += cost;
		}
	//	cout << a << " " << b << " " << cost << endl;
	//	for(int i = 1; i <= n; i++) cout << pa[i] << " ";
	//	cout << endl;
	}
	cout << -ans;
}
