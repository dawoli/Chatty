#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int T;
ll n, m, L, V;
struct Car {
	ll d, v, a;
} a[100005];
struct Node {
	ll l, r;
} b[100005];
bool operator < (Node x, Node y) {
	return x.r < y.r;
}
int sz = 0;
int p[100005];
int ans1 = 0;

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for (int i = 1; i <= n; ++i)
			scanf("%d%d%d", &a[i].d, &a[i].v, &a[i].a);
		for (int i = 1; i <= m; ++i)
			scanf("%d", &p[i]);
		
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; ++i) {
			if (a[i].a > 0) {
				if (a[i].v > V) {
					b[i].l = a[i].d;
					b[i].r = L + 1;
				}
				else {
					b[i].l = (V * V - a[i].v * a[i].v) / (2 * a[i].a) + a[i].d + 1;
					b[i].r = L + 1;
					if (b[i].l > L) {
						b[i].l = 0;
						b[i].r = 0;
					}
				}
			}
			else if (a[i].a == 0) {
				if (a[i].v > V) {
					b[i].l = a[i].d;
					b[i].r = L + 1;
				}
				else {
					b[i].l = 0;
					b[i].r = 0;
				}
			}
			else {
				if (a[i].v > V) {
					b[i].l = a[i].d;
					b[i].r = (V * V - a[i].v * a[i].v + 2 * a[i].a + 1) / (2 * a[i].a) + a[i].d;
				}
				else {
					b[i].l = 0;
					b[i].r = 0;
				}
			}
		}
		
		sz = 0;
		for (int i = 1; i <= n; ++i) {
			if (b[i].l == 0 && b[i].r == 0) continue;
			int pos = lower_bound(p + 1, p + m + 1, b[i].l) - p;
			if (1 <= pos && pos <= m && b[i].l <= p[pos] && p[pos] <= b[i].r){
				b[++sz].l = pos;
				pos = lower_bound(p + 1, p + m + 1, b[i].r) - p;
				b[sz].r = pos - 1;
				cout << i << endl;
			}
		}
		sort(b + 1, b + sz + 1);
		int last = 0, cnt = 0;
		for (int i = 1; i <= sz; ++i) {
			if (b[i].l <= last && b[i].r >= last) continue;
			last = b[i].r;
			cnt++;
		}
		printf("%d %d\n", sz, m - cnt);
	}
	return 0;
}
