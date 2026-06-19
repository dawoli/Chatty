#include <bits/stdc++.h>
using namespace std;
const int N = 10005, M = 1000005, K = 15;
int n, m, k, u[M], v[M], w[M], c[K], a[K][N], fa[N + K];
bool flagA = 1;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edge;
void init(int n) {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
}
int find(int n) {
	return fa[n] == n ? n : fa[n] = find(fa[n]);
}
bool merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x == y) return 0;
	fa[x] = y;
	return 1;
}
void solveA() {
	int rest = n + k - 1, ans = 0;
	init(n + k);
	for (int i = 1; i <= m; i++)
		edge.push({w[i], {u[i], v[i]}});
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			edge.push({a[i][j], {n + i, j}});
	for (int i = 1; rest; i++) {
		pair<int, pair<int, int>> e = edge.top();
		edge.pop();
		if (merge(e.second.first, e.second.second)) {
			ans += e.first, rest--;
		}
	}
	cout << ans << endl;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	int rest = n;
	for (int i = 1; i <= m; i++)
		cin >> u[i] >> v[i] >> w[i];
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i]) flagA = 0;
		bool flag = 1;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (!a[i][j]) flag = 0;
		}
		if (flag) flagA = 0;
	}
	if (flagA) solveA();
	else solveA();
	return 0;
}
