#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 20;
bool vis[MAXN], cc[15], found = true;
int n, m, k;
long long ans = LLONG_MAX, c[15], a[15][MAXN];
vector <pair<int, long long> > graph[MAXN];
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;

vector <int> more;

long long prim(){
	long long tot = 0;
	for (int i = 1; i <= n + k; ++i)
		vis[i] = false;
	more.clear();
	for (int i = 1; i <= k; ++i){
		if (cc[i]){
			more.push_back(i);
			tot += c[i];
		}
	}
	pq.push(make_pair(0, 1));
	while(!pq.empty()){
		int u = pq.top().second;
		long long dist = pq.top().first;
		pq.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		tot += dist;
		for (size_t i = 0; i < graph[u].size(); ++i){
			int v = graph[u][i].first;
			long long w = graph[u][i].second;
			if (vis[v])
				continue;
			pq.push(make_pair(w, v));
		}
		if (u > n){
			for (int i = 1; i <= n; ++i){
				int v = i;
				long long w = a[u - n][i];
				if (vis[v])
					continue;
				pq.push(make_pair(w, v));
			}
		}
		else{
			for (size_t i = 0; i < more.size(); ++i){
				int v = more[i];
				long long w = a[v][u];
				pq.push(make_pair(w, v + n));
			}
		}
	}
	return tot;
}

void dfs(int now){
	if (now == k + 1){
		ans = min(ans, prim());
		return;
	}
	cc[now] = true;
	dfs(now + 1);
	cc[now] = false;
	dfs(now + 1);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	for (int i = 1; i <= k; ++i){
		cin >> c[i];
		if (c[i])
			found = false;
		bool zero = false;
		for (int j = 1; j <= n; ++j){
			cin >> a[i][j];
			if (a[i][j] == 0)
				zero = true;
		}
		if (!zero)
			found = false;
	}
	if (!found)
		dfs(1);
	else{
		for (int i = 1; i <= k; ++i)
			cc[i] = true;
		ans = prim();
	}
	cout << ans;
	return 0;
}
