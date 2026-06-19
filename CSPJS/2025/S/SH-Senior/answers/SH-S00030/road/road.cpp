#include <bits/stdc++.h>
using namespace std;

#define int long long

#define N 10005
#define K 11

#define INF 0x3f3f3f3f3f3f3f3f

struct E {
	int v, w;
};

int n, m, k;
vector<E> g[N];
int c[K];
int a[K][N];
bool exist[K];
bool vis[N + K];

inline void add_edge(int u, int v, int w) {
	g[u].push_back(E {v, w});
}

typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii>> q;
int d[N];

int prim() {
	int res = 0;
	for (int i = 1; i <= n + k; i++) {
		d[i] = INF;
		vis[i] = 0;
	}
	vis[1] = 1;
	for (E &e : g[1]) {
		q.push(pii {e.w, e.v});
	}
	for (int j = 1; j <= k; j++) {
		if (exist[j]) {
			q.push(pii {a[j][1], n + j});
		}
	}
	while (!q.empty()) {
		pii p = q.top();
		q.pop();
		int u = p.second;
		if (vis[u]) {
			continue;
		}
		vis[u] = 1;
		res += p.first;
		if (u <= n) {
			for (E &e : g[u]) {
				if (!vis[e.v] && e.w < d[e.v]) {
					d[e.v] = e.w;
					q.push(pii {e.w, e.v});
				}
			}
			for (int j = 1; j <= k; j++) {
				if (exist[j] && !vis[n + j] && a[j][u] < d[n + j]) {
					d[n + j] = a[j][u];
					q.push(pii {a[j][u], n + j});
				}
			}
		} else {
			for (int i = 1; i <= n; i++) {
				if (!vis[i] && a[u - n][i] < d[i]) {
					d[i] = a[u - n][i];
					q.push(pii {a[u - n][i], i});
				}
			}
		}
	}
	return res;
}

bool flagA;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	flagA = 1;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		if (c[j] != 0) {
			flagA = 0;
		}
		bool flg = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
			if (a[j][i] == 0) {
				flg = 1;
			}
		}
		if (!flg) {
			flagA = 0;
		}
	}
	if(k == 0) {
		cout << prim() << endl;
	} else if (flagA) {
		for (int j = 1; j <= k; j++) {
			exist[j] = 1;
		}
		cout << prim() << endl;
	} else {
		int mxsel = (1 << k);
		int ans = INF;
		for (int sel = 0; sel < mxsel; sel++) {
			int cost = 0;
			for (int j = 1; j <= k; j++) {
				if (sel & (1 << (j - 1))) {
					exist[j] = 1;
					cost += c[j];
				} else {
					exist[j] = 0;
				}
			}
			ans = min(ans, cost + prim());
		}
		cout << ans << endl;
	}
}
