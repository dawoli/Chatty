#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 15, M = 1100005;
int n, m, k, fa[N], U[M], V[M], W[M], p[M], c[12][N];

bool cmp(int i, int j) {
	return W[i] < W[j];
}

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

bool add(int x, int y) {
	x = find(x), y = find(y);
	if (x == y)
		return 0;
	fa[y] = x;
	return 1;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int n0 = n;
	for (int i = 1; i <= m; i++)
		scanf("%lld%lld%lld", U + i, V + i, W + i);
	for (int i = 1; i <= k; i++) {
		int c0;
		cin >> c0;
		if (!c0)
			n++;
		for (int j = 1; j <= n0; j++) {
			scanf("%lld", &c[i][j]);
			if (!c0)
				m++, U[m] = n, V[m] = j, W[m] = c[i][j];
		}
	}
	for (int i = 1; i <= m; i++)
		p[i] = i;
	sort(p + 1, p + m + 1, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	int ans = 0;
	for (int x = 1; x <= m; x++) {
		int i = p[x];
		if (add(U[i], V[i]))
			ans += W[i];
	}
	cout << ans;
	return 0;
}

