#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
struct node {
	int d, v, a;
} c[N];
int p[N];

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, L, V;
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d", &p[i]);
		}
		
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int idx = lower_bound(p + 1, p + 1 + m, c[i].d) - p;
			if (idx == m + 1) continue;
			if (c[i].v > V) {
				cnt++;
			}
		}
		
		if (cnt != 0) {
			printf("%d %d\n", cnt, m - 1);
		} else {
			printf("%d %d\n", cnt, m);
		}
	}
	
	return 0;
}

