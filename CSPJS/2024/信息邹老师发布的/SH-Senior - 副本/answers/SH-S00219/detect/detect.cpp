#include <bits/stdc++.h>

const int N = 1e5 + 2;

int n = 0, m = 0, L, V, btp, ans1;
int pos[N];
struct node {
	int d, v, a;
} a[N];
struct seg {
	int l, r;
} b[N];

void solve() {
	for (int i = 1; i <= btp; i++) {
		b[i].l = b[i].r = 0;
	}
	btp = 0, ans1 = 0;
	std::cin >> n >> m >> L >> V;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].d >> a[i].v >> a[i].a;
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> pos[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i].a == 0) {
			if (a[i].v <= V) {
				
			} else {
				int k1 = std::lower_bound(pos + 1, pos + 1 + m, a[i].d) - pos;
				int k2 = std::upper_bound(pos + 1, pos + 1 + m, L) - pos - 1;
				if (k1 <= k2) {
					b[++btp] = {k1, k2};
					ans1++;
				}
			}
		} else if (a[i].a < 0) {
			a[i].a = -a[i].a;
			if (a[i].v <= V) {
				
			} else {
				int right_bound;
				if ((a[i].v * a[i].v - V * V) % (a[i].a * 2) == 0) {
					right_bound = a[i].d + (a[i].v * a[i].v - V * V) / (a[i].a * 2) - 1;
				} else {
					right_bound = a[i].d + (a[i].v * a[i].v - V * V) / (a[i].a * 2);
				}
				right_bound = std::min(right_bound, L);
				int k1 = std::lower_bound(pos + 1, pos + 1 + m, a[i].d) - pos;
				int k2 = std::upper_bound(pos + 1, pos + 1 + m, right_bound) - pos - 1;
				if (k1 <= k2) {
					b[++btp] = {k1, k2};
					ans1++;
				}
			}
		} else {
			if (a[i].v > V) {
				int k1 = std::lower_bound(pos + 1, pos + 1 + m, a[i].d) - pos;
				int k2 = std::upper_bound(pos + 1, pos + 1 + m, L) - pos - 1;
				if (k1 <= k2) {
					b[++btp] = {k1, k2};
					ans1++;
				}
			} else {
				int left_bound;
				if ((V * V - a[i].v * a[i].v) % (a[i].a * 2) == 0) {
					left_bound = a[i].d + (V * V - a[i].v * a[i].v) / (a[i].a * 2) + 1;
				} else {
					left_bound = a[i].d + (V * V - a[i].v * a[i].v + a[i].a * 2 - 1) / (a[i].a * 2);
				}
				if (left_bound <= L) {
					int k1 = std::lower_bound(pos + 1, pos + 1 + m, left_bound) - pos;
					int k2 = std::upper_bound(pos + 1, pos + 1 + m, L) - pos - 1;
					if (k1 <= k2) {
						b[++btp] = {k1, k2};
						ans1++;
					}
				}
			}
		}
	}
	std::cout << ans1 << ' ';
	std::sort(b + 1, b + 1 + btp, [](const seg ox, const seg oy) {
		return ox.r == oy.r ? ox.l < oy.l : ox.r < oy.r;
	});
//	if (b[1].r != b[btp].r) {
////		fclose(stdout);
//		std::cout << b[1].r << " " << b[btp].r << " " << L << " " << m << std::endl;
//		exit(6);
//	}
	int ans2 = 0, now = 0;
	b[0] = {-1, -1};
	for (int i = 1; i <= btp; i++) {
		if (b[i].l <= b[now].r) {
			continue;
		} else {
			ans2++;
			now = i;
		}
	}
	std::cout << m - ans2 << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
//	freopen("detect5.in", "r", stdin);
//	freopen("ans.txt", "w", stdout);
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
}
