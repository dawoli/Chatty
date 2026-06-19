#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define REP(i, r, l) for (int i = (r); i >= (l); --i)
#define mp make_pair
#define fir first
#define sec second
using namespace std;

typedef pair<int, int> pii;

int n, m, k, u, v, w;
int c[11], a[11][10001];
int dis[10001][10001];

vector<vector<pii> > edge;
priority_queue<int> pq;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dis, -1, sizeof(dis));
	cin >> n >> m >> k;
	edge.resize(n + k + 1);
	rep (i, 1, m) {
		cin >> u >> v >> w;
		edge[u].push_back(mp(v, w));
		edge[v].push_back(mp(u, w));
	}
	rep (i, 1, k) {
		cin >> c[i];
		rep (j, 1, n) {
			cin >> a[i][j];
			edge[n + i].push_back(mp(j, a[i][j]));
		}
	}
	pq.push(1);
	return 0;
}
