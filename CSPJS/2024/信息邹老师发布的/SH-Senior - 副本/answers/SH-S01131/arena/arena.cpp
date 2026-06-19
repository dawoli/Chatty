#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e3 + 5;
int T, K, n, m, a[maxn], t[maxn], c[maxn], x[5], ans, res[maxn];
char G[19][maxn];
struct node {
	int num, id;
};
deque <node> q;
int g(int x) {
	for (int i=1; i; i*=2) {
		if (i >= x) return i;
	}
}
int solve(int x) {
	while (!q.empty()) q.pop_front();
	for (int i=1; i<=x; i++) q.push_back(node{a[i], i});
	for (int i=1; i<=log2(x); i++) {
		for (int j=1; j<=(x / pow(2, i-1)); j++) {
			node a1 = q.front(); q.pop_front();
			node a2 = q.front(); q.pop_front();
			int opt = G[i][j] - '0';
			if (opt == 0) {
				if (a1.num >= i) q.push_back(a1);
				else q.push_back(a2);
			} 
			else {
				if (a2.num >= i) q.push_back(a2);
				else q.push_back(a1);
			} 
		}
	}
	return q.front().id;
}
signed main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> t[i];
	for (int i=1; i<=m; i++) cin >> c[i];
	K = g(n);
	for (int i=1; i<=log2(K); i++) {
		for (int j=1; j<=pow(2, log2(K)-i); j++) {
			cin >> G[i][j];
		}
	}
	cin >> T;
	while (T --) {
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for (int i=1; i<=n; i++) a[i] = t[i] ^ x[i % 4];
		ans = solve(c[1]);
		for (int i=2; i<=m; i++) {
			ans = ans ^ (i * solve(c[i]));
		}
		cout << ans << endl;
	}
	return 0;
}
