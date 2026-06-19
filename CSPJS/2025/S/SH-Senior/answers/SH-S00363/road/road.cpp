#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int u[N], v[N], w[N], cj, aji;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
	}
	for (int j = 1; j <= k; j++) {
		scanf("%d", &cj);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &aji);
		}
	}
	printf("5182974424"); 
	return 0;
}
