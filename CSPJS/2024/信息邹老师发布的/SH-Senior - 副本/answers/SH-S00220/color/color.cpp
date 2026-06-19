#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], color[N], n, sum, ans;

void dfs(int i) {
	if (i == n) {
		ans = max(ans, sum);
		return;
	}
	color[i] = 0;
	int c = 0;
	for (int j = i - 1; j >= 0; --j) {
		if (color[j] == color[i] && a[j] == a[i]) {
			c = a[i];
			break;
		}
	}
	sum += c;
	dfs(i + 1);
	sum -= c;
	color[i] = 1;
	c = 0;
	for (int j = i - 1; j >= 0; --j) {
		if (color[j] == color[i] && a[j] == a[i]) {
			c = a[i];
			break;
		}
	}
	sum += c;
	dfs(i + 1);
	sum -= c;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		sum = ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}
