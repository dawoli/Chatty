#include <bits/stdc++.h>
const int maxn = 1e4 + 500;
const int maxm = 2e6 + 10;
const long long inf = 2e18;
struct originalroad {
	int u, v;
	long long w;
} road[maxm];
int fa[maxn];
long long c[15];
long long a[15][maxn];
long long cmp(originalroad x, originalroad y) {
	return x.w < y.w; 
}
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, tot = 0, city = 0;
	bool zero = true;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n + k + 1; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		long long val;
		scanf("%d%d%lld", &u, &v, &val);
		road[i].u = u, road[i].v = v, road[i].w = val;
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		if (c[i] != 0)
			zero = false;
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	if (k == 0) {
		std::sort(road + 1, road + m + 1, cmp);
		long long sum = 0;
		for (int i = 1; i <= m; i++) {
			int fax = find(road[i].u), fay = find(road[i].v);
			if (fax != fay) {
				fa[fax] = fay;
				sum += road[i].w;
			}
		}
		printf("%lld", sum);
		return 0;
	}
	if (zero) {
		tot = m;
		city = n;
		for (int i = 1; i <= k; i++) {
			city++;
			for (int j = 1; j <= n; j++) {
				road[++tot].u = city, road[tot].v = j;
				road[tot].w = a[i][j];
			}
		}
		std::sort(road + 1, road + tot + 1, cmp);
		long long sum = 0;
		for (int i = 1; i <= tot; i++) {
			int fax = find(road[i].u), fay = find(road[i].v);
			if (fax != fay) {
				fa[fax] = fay;
				sum += road[i].w;
			}
		}
		printf("%lld", sum);
		return 0;
	}
//	if (k <= 5) {
		long long ans = inf, sum = 0;
		for (int state = 0; state < (1 << k); state++) {
			sum = 0;
			tot = m;
			city = n;
			for (int i = 1; i <= k; i++) {
				if (state & (1 << (i - 1))){
					sum += c[i];
					city++;
					for (int j = 1; j <= n; j++) {
						tot++;
						road[tot].u = city, road[tot].v = j;
						road[tot].w = a[i][j];
					}
				}
			}
			std::sort(road + 1, road + tot + 1, cmp);
			for (int i = 1; i <= n + k + 2; i++) {
				fa[i] = i;
			}
			for (int i = 1; i <= tot; i++) {
				int fax = find(road[i].u), fay = find(road[i].v);
				if (fax != fay) {
					fa[fax] = fay;
					sum += road[i].w;
				}
			}
			ans = std::min(ans, sum);
	//		printf("%d %lld\n", city, sum);
		}
		printf("%lld", ans);
		return 0;
//	}
}
