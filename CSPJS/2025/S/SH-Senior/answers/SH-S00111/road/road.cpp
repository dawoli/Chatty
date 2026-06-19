#include <bits/stdc++.h>
using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
}

int n, m, k;
const int SZ = 1e4 + 5;
int p[SZ][SZ];
int a[11][SZ];
int group[SZ];

int find(int x) {
	if (group[x] == x) return x;
	int ans = find(group[x]);
	group[x] = ans;
	return ans;
}

int merge(int x, int y) {
	group[find(x)] = find(y);
}

bool connected(int x, int y) {
	return find(x) == find(y);
}

struct Path {
	int u, v;
	bool operator < (const Path& another) const {
		return p[u][v] < p[another.u][another.v];
	}
};
int path_amt = 0;
vector<Path> paths;

void update_path(int u, int v, int w) {
	if (p[u][v] != -1 && p[u][v] < w) return;
	path_amt += p[u][v] == -1;
	p[u][v] = w;
	p[v][u] = w;
}

int main() {
    init();
	
	memset(p, -1, sizeof(p));
	
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	update_path(u, v, w);
	}
	
	for (int j = 1; j <= k; j++) {
		int c;
		cin >> c; // c is always 0
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
		}
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v < u; v++) {
				update_path(u, v, a[j][u] + a[j][v]);
			}
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << p[i][j] << ' ';
//		}
//		cout << endl;
//	}

	for (int i = 0; i <= n; i++) {
		group[i] = i;
	}
	
	paths.reserve(path_amt);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (p[i][j] != -1) {
				paths.push_back(Path{i, j});
			}
		}
	}
	sort(paths.begin(), paths.end());
	
	long long cost = 0;
	for (Path& cur : paths) {
		// cout << cur.u << " -> " << cur.v << ": " << p[cur.u][cur.v] << endl;
		if (!connected(cur.u, cur.v)) {
			merge(cur.u, cur.v);
			cost += p[cur.u][cur.v];
		}
	}
	cout << cost << endl;
}
