#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 13, M = 1e6 + 13;
int n, m, k, a[11], b[11][N], t[M], f[N], e[N];

void read(int& x) {
	x = 0;
	char c = getchar();
	while (48 > c || c > 57) c = getchar();
	while (48 <= c && c <= 57) x = x * 10 + c - 48, c = getchar();
}

struct node {
	int u, v, w;
	bool operator<(const node& o) const {
		return w < o.w;
	}
} c[M], d[M];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]); 
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 1; i <= m; ++i)
		read(c[i].u), read(c[i].v), read(c[i].w), t[i] = f[i] = i;
	for (int i = 1; i <= k; ++i) {
		read(a[i]);
		for (int j = 1; j <= n; ++j)
			read(b[i][j]);
	}
	sort(c + 1, c + m + 1);
	int cnt = 0;
	long long ans = 1e18, sum = 0;
	for (int i = 1; cnt < n - 1; ++i) {
		if (find(c[i].u) != find(c[i].v))
			++cnt, sum += c[i].w, c[cnt] = {c[i].u, c[i].v, c[i].w}, f[f[c[i].u]] = f[c[i].v];
	}
	ans = sum;
	for (int i = 0; i < (1 << k); ++i) {
		for (int j = 1; j <= n - 1; ++j) d[j] = c[j], f[j] = j;
		f[n] = n;
		int ttt = n - 1;
		sum = 0, cnt = 0;
		int tt = n - 1;
		for (int j = 1; j <= k; ++j)
			if (i >> (j - 1) & 1) {
				sum += a[j];
				++tt;
				f[tt + 1] = tt + 1;
				for (int k = 1; k <= n; ++k)
					d[++ttt] = {tt + 1, k, b[j][k]};
			}
		sort(d + 1, d + ttt + 1);
		for (int j = 1; cnt < tt; ++j) { 
			if (find(d[j].u) != find(d[j].v))
				++cnt, sum += d[j].w, f[f[d[j].u]] = f[d[j].v];
		}
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}
