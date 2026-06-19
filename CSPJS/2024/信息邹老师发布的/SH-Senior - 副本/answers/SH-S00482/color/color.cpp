#include<bits/stdc++.h>
using namespace std;

#define l first
#define r second

typedef long long ll;
const int MAX_N = 2e5 + 10, MAX_S = 1e6 + 10;

ll ans;
int T, n, A[MAX_N], C[MAX_N];

void dfs(int u) {
	if (u == n + 1) {
		int pos[2] = {0, 0}; ll res = 0;
		for (int i = 1; i <= n; i++) {
			if (A[pos[C[i]]] == A[i]) res += A[i];
			pos[C[i]] = i;
		}
		ans = max(res, ans);
		return;
	}
	dfs(u + 1);
	C[u] = 1;
	dfs(u + 1);
	C[u] = 0;
}

void solve() {
	ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	dfs(1);
	printf("%lld\n", ans);
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
