#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 10;
ll n, m, k, c[N], a[15][N], ans = 0x3f7f7f7f;
struct Edge{
	int nx, w;
};
vector<Edge> e[N];

void adde(ll u, ll v, ll w) {
	Edge ee;
	ee.nx = v; ee.w = w;
	e[u].push_back(ee);
	ee.nx = u;
	e[v].push_back(ee);
}

int fe[N];
bool vis[N];
struct po{
	int x, fee;
};
void bfs(ll rot) {
	memset(fe, 0x3f7f7f7f, sizeof(fe));
	queue<po> q;
	po now;
	now.x = rot;
	now.fee = 0;
	q.push(now);
	while(!q.empty()) {
		now = q.front();
		q.pop();
//		cout << now.x << "\n";
		if (vis[now.x]) {
			fe[now.x] = min(fe[now.x], now.fee);
			continue;
		}
		vis[now.x] = 1;
		fe[now.x] = now.fee;
		for (int i = 0; i < e[now.x].size(); ++ i) {
			po nxt;
			nxt.x = e[now.x][i].nx;
			nxt.fee = e[now.x][i].w;
			q.push(nxt);
		}
	}
	
	ll cnt = 0;
	for (int i = 1; i <= n; ++ i)
		cnt += fe[i];
	ans = min(ans, cnt);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++ i) {
		ll u, v, w;
		cin >> u >> v >> w;
		adde(u, v, w);
	}
//	for (int i = 1; i <= n; ++ i) {
//		for (int j = 0; j < e[i].size(); ++ j)
//			cout << e[i][j].nx << " " << e[i][j].w << "\n";
//		cout << "\n";
//	}
	for (int i = 1; i <= k; ++ i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++ j)
			cin >> a[i][j];
	}
	
	for (ll i = 1; i <= n; ++ i) 
		bfs(i);
	cout << ans << "\n";
	return 0;
}
