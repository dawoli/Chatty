#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int t, n, a[MAXN][3];
struct x {
	int v;
	int i;
	int j;
}xs[MAXN * 3];

bool operator < (const x& x1, const x& x2) {
	return x1.v > x2.v;
}

priority_queue<int> q[3];
int ans, cnt[3];
bool used[MAXN];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(used, 0, sizeof(used));
		while (!q[0].empty()) q[0].pop();
		while (!q[1].empty()) q[1].pop();
		while (!q[2].empty()) q[2].pop();
		ans = cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			xs[i] = {a[i][0], i, 0};
			xs[i + n] = {a[i][1], i, 1};
			xs[i + 2 * n] = {a[i][2], i, 2};
		}
		sort(xs + 1, xs + 3 * n + 1);
		for (int i = 1, xv, xi, xj; i <= 3 * n; i++) {
			xv = xs[i].v;
			xi = xs[i].i;
			xj = xs[i].j;
			if (used[xi]) continue;
			used[xi] = true;
			ans += xv;
			cnt[xj]++;
			if (xj == 0) q[0].push(max(a[xi][1], a[xi][2]) - xv);
			if (xj == 1) q[1].push(max(a[xi][0], a[xi][2]) - xv);
			if (xj == 2) q[2].push(max(a[xi][0], a[xi][1]) - xv);
		}
		for (int i = 0; i < 3; i++) {
			while (cnt[i] * 2 > n) {
				ans += q[i].top();
				q[i].pop();
				cnt[i]--;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
