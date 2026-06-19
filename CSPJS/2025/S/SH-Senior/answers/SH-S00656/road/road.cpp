#include<bits/stdc++.h>
using namespace std;

int n, m, k, dis[10005], ans;
bool vis[10005];
vector<int> e[10005], w[10005];

//建图+dijkstra最短路+最短路和 

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++){
		int u, v, a;
		cin >> u >> v >> a;
		e[u].push_back(v);
		e[v].push_back(u);
		w[u].push_back(a);
		w[v].push_back(a);
	}
	for (int i = 1; i <= k; i ++){
		int c;
		cin >> c;
		for (int j = 1; j <= n; j ++){
			int a;
			cin >> a;
			e[n+i].push_back(j);
			e[j].push_back(n+i);
			w[n+i].push_back(c+a);
			w[j].push_back(c+a);
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<int, vector<int>, greater<int> > q;
	q.push(1);
	while (!q.empty()){
		int u = q.top();
		q.pop();
		vis[u] = true;
		for (int i = 0; i < e[u].size(); i ++){
			int v = e[u][i];
			if (!vis[v]){
				q.push(v);
				if (dis[v] > dis[u] + w[u][i]) dis[v] = dis[u] + w[u][i];
			}
		}
	}
	for (int i = 2; i <= n; i ++){
		ans += dis[i];
	}
	cout << ans;
	return 0;
} 
