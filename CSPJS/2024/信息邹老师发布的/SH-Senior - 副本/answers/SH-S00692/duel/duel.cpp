#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int n, a[N], ans;
bool vis[N], out[N];
void dfs(int x, int dead) {
	if (x > n) {
		ans = max(ans, dead);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] || out[i]) // can attack and is alive
			continue;
		vis[i] = true;
		for (int j = 1; j <= n; j++) {
			if (i == j || out[j]) // still alive
				continue;
			out[j] = (a[i] > a[j]);
			dfs(x + 1 + (!vis[j] && out[j]), dead + out[j]);
			out[j] = false;
		}
		vis[i] = false;
	}
}
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dfs(1, 0);
	printf("%d\n", n - ans);
	return 0;
}
