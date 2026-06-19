#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+14;
const int M = 14;
int n, m, k, ans;
vector<pair<int, int>> g[N];
struct cmp{
	bool operator ()(const pair<int, int>& x, const pair<int, int>& y){
		return x.second > y.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
bool f[N];
int c[M], far[M][N];
void prim(){
	for(int i = 0; i < g[1].size(); i ++){
		//cout << g[1][i].first << ' ' << g[1][i].second << '\n';
		q.push({g[1][i].first, g[1][i].second});
		//f[g[1][i].first] = 1;
	}
	q.push({1, 0});
	f[1] = 1;
	for(int i = 1; i < n; i ++){
		while(!q.empty() && f[q.top().first]) q.pop();
		if(q.empty()) return;
		int now = q.top().first;
		int dis = q.top().second;
		//cout << now << '\n';
		q.pop();
		ans += dis, f[now] = 1;
		for(int j = 0; j < g[now].size(); j ++){
			if(!f[g[now][j].first]){
				//cout << g[now][i].first << g[now][i].second << '\n';
				q.push({g[now][j].first, g[now][j].second});
			}
		}
	}
	return;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		for(int j = 1; j <= n; j ++){
			cin >> far[i][j];
		}
	}
	prim();
	if(k == 0){
		cout << ans << '\n';
		return 0;
	}
	return 0;
}
