#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7, M = 1 << 20;
int n, k, cnt, a[N];
vector<int> g[M];

struct node {
	int l, r;
} c[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
	}
	for (int i = n; i >= 1; --i) g[a[i]].push_back(i);
	for (int i = 1; i <= n; ++i) {
		if (g[a[i - 1] ^ k].size()) {
			++cnt;
			c[cnt].l = i, c[cnt].r = *g[a[i - 1] ^ k].rbegin();
		}
		g[a[i]].pop_back();
	}
	int l = n + 1, ans = 0;
	for (int i = cnt; i >= 1; --i) {
		while (i && c[i].r >= l) --i;
		if (i) ++ans, l = c[i].l;
	}
	printf("%d\n", ans);
	return 0;
}
