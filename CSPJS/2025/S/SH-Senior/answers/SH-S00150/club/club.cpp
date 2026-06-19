#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 11;
int n, a[N][3], l1, l2, l3, p[N], q[N], r[N];

bool cmp(const int &x, const int &y) {
	return a[x][0] - max(a[x][1], a[x][2]) > a[y][0] - max(a[y][1], a[y][2]);
}

inline void solve() {
	l1 = l2 = l3 = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
			p[++l1] = i;
		else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2])
			q[++l2] = i;
		else
			r[++l3] = i;
	}
	if (l2 > (n >> 1)) {
		for (int i = 1; i <= l2; i++)
			swap(p[i], q[i]);
		swap(l1, l2);
		for (int i = 1; i <= n; i++)
			swap(a[i][0], a[i][1]);
	} else if (l3 > (n >> 1)) {
		for (int i = 1; i <= l3; i++)
			swap(p[i], r[i]);
		swap(l1, l3);
		for (int i = 1; i <= n; i++)
			swap(a[i][0], a[i][2]);
	}
	if (l1 * 2 > n) {
		sort(p + 1, p + l1 + 1, cmp);
		for (int i = (n >> 1) + 1; i <= l1; i++)
			if (a[p[i]][1] > a[p[i]][2])
				q[++l2] = p[i];
			else
				r[++l3] = p[i];
		l1 = (n >> 1);
	}
	int ans = 0;
	for (int i = 1; i <= l1; i++)
		ans += a[p[i]][0];
	for (int i = 1; i <= l2; i++)
		ans += a[q[i]][1];
	for (int i = 1; i <= l3; i++)
		ans += a[r[i]][2];
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
