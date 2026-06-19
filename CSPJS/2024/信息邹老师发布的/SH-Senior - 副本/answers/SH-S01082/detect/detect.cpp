#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
struct car {
	int v0, a, d;
};
struct seg {
	int l, r;
};
bool cmp(seg x, seg y) {
	return x.r < y.r;
}
int t, n, m, L, V, tot, ans;
car a[maxn];
int b[maxn];
seg c[maxn];
int bt[maxn];
inline int lowbit(int x) {
	return x & -x;
}
inline void add(int x) {
	for (; x <= m; x += lowbit(x)) {
		bt[x] ++;
	}
}
inline int query(int x) {
	int res = 0;
	for (; x; x -= lowbit(x)) {
		res += bt[x];
	}
	return res;
}
void clear() {
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	memset(bt, 0, sizeof(bt));
	tot = ans = 0;
}
void read() {
	scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld%lld%lld", &a[i].d, &a[i].v0, &a[i].a);
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%lld", b + i);
	}
}
bool check(int x, int pos) {
	return a[x].v0 * a[x].v0 + 2 * a[x].a * (b[pos] - a[x].d) <= V * V;
}
void solve(int x, int pos) {
	int l = pos, r = m, ans = -1;
	if (a[x].a > 0) {
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(x, mid)) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
				ans = mid;
			}
		}
		if (~ans) {
			tot ++;
			c[tot] = {ans, m};
		}
	}
	else {
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(x, mid)) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
				ans = mid;
			}
		}
		if (~ans) {
			tot ++;
			c[tot] = {pos, ans};
		}
	}
}
void run() {
	for (int i = 1, pos; i <= n; i ++) {
		pos = lower_bound(b + 1, b + m + 1, a[i].d) - b;
		solve(i, pos);
	}
	sort(c + 1, c + tot + 1, cmp);
	for (int i = 1; i <= tot; i ++) {
		int numr = query(c[i].r);
		int numl = query(c[i].l - 1);
		if (!(numr - numl)) {
			ans ++;
			add(c[i].r);
		}
	}
	ans = m - ans;
	printf("%lld %lld\n", tot, ans);
}
signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &t);
	while (t --) {
		clear();
		read();
		run();
	}
}
