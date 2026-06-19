#include <iostream>
#include <vector>
#include <set>
const int N = 1e5 + 9;
struct Car {
	int v, a;
	double d, l, r;
	bool speedy;
	bool il, ir;
	Car() { l = 0, r = 0, speedy = false; }
} car[N];
int n, m, len, vlimit;
double monitor[N];
std::multiset<int> check[N];
void solve_small_case() {
	int ans1 = 0;
	for (int i = 1; i <= n; i++) {
		double d = car[i].d;
		int v = car[i].v, a = car[i].a;
		if (a > 0) {
			if (v > vlimit) {
				car[i].speedy = true;
				car[i].il = true;
				car[i].ir = true;
				car[i].l = d;
				car[i].r = len;
			} else if (v == vlimit) {
				if (d == len) {
					car[i].speedy = false;
				} else {
					car[i].speedy = true;
					car[i].il = false;
					car[i].ir = true;
					car[i].l = d;
					car[i].r = len;
				}
			} else {
				double s = 1. * (vlimit * vlimit - v * v) / a / 2;
				if (d + s >= len) {
					car[i].speedy = false;
				} else {
					car[i].speedy = true;
					car[i].il = false;
					car[i].ir = true;
					car[i].l = d + s;
					car[i].r = len;
				}
			}
		} else if (a == 0) {
			if (v <= vlimit) {
				car[i].speedy = false;
			} else {
				car[i].speedy = true;
				car[i].il = true;
				car[i].ir = true;
				car[i].l = d;
				car[i].r = len;
			}
		} else {
			if (v > vlimit) {
				double s = 1. * (v * v - vlimit * vlimit) / (-a) / 2;
				car[i].speedy = true;
				car[i].il = true;
				car[i].ir = false;
				car[i].l = d;
				car[i].r = std::min(d + s, (double)len);
			} else {
				car[i].speedy = false;
			}
		}
		if (car[i].speedy == false) continue;
		bool check_speedy = false;
		for (int j = 1; j <= m; j++) {
			if (car[i].l < monitor[j] and monitor[j] < car[i].r) {
				check[j].insert(i);
				check_speedy = true;
			} else if (car[i].l == monitor[j] and car[i].il == true) {
				check[j].insert(i);
				check_speedy = true;
			} else if (car[i].r == monitor[j] and car[i].ir == true) {
				check[j].insert(i);
				check_speedy = true;
			}
		}
		ans1 += check_speedy;
		car[i].speedy = check_speedy;
	}
	printf("%d ", ans1);
//	for (int i = 1; i <= m; i++) {
//		printf("cars #%d monitor check out: ", i);
//		for (auto j : check[i]) {
//			printf("%d ", j);
//		}
//		puts("");
//	}
	int cars_check = 0, ans2 = 0;
	while (cars_check < ans1) {
		int mx = 0, mxid;
		for (int i = 1; i <= m; i++) {
			if (check[i].size() > mx) {
				mx = check[i].size();
				mxid = i;
			}
		}
		cars_check += check[mxid].size();
//		printf("mxid = %d\n", mxid);
		for (auto i : check[mxid]) {
//			printf("i = %d\n", i);
			for (int j = 1; j <= m; j++) {
				if (j == mxid) continue;
				if (check[j].find(i) == check[j].end()) continue;
//				printf("erase %d from the check list of %d\n", i, j);
				check[j].erase(check[j].find(i));
//				printf("check[%d].size() = %d\n", j, check[j].size());
			}
		}
		check[mxid].clear();
		ans2++;
//		printf("cars have checked = %d\n", cars_check);
	}
	printf("%d\n", m - ans2);
	for (int i = 1; i <= m; i++) check[i].clear();
}
void solve_property_ab() {
	int mx = 0;
	for (int i = 1; i <= m; i++) {
		mx = std::max((int)monitor[i], mx);
	}
	int ans1 = 0;
	for (int i = 1; i <= n; i++) {
		double d = car[i].d;
		int v = car[i].v, a = car[i].a;
		if (a > 0) {
			if (v > vlimit) {
				car[i].speedy = true;
				car[i].il = true;
				car[i].ir = true;
				car[i].l = d;
				car[i].r = len;
			} else if (v == vlimit) {
				if (d == len) {
					car[i].speedy = false;
				} else {
					car[i].speedy = true;
					car[i].il = false;
					car[i].ir = true;
					car[i].l = d;
					car[i].r = len;
				}
			} else {
				double s = 1. * (vlimit * vlimit - v * v) / a / 2;
				if (d + s >= len) {
					car[i].speedy = false;
				} else {
					car[i].speedy = true;
					car[i].il = false;
					car[i].ir = true;
					car[i].l = d + s;
					car[i].r = len;
				}
			}
		} else if (a == 0) {
			if (v <= vlimit) {
				car[i].speedy = false;
			} else {
				car[i].speedy = true;
				car[i].il = true;
				car[i].ir = true;
				car[i].l = d;
				car[i].r = len;
			}
		} else {
			if (v > vlimit) {
				double s = 1. * (v * v - vlimit * vlimit) / (-a) / 2;
				car[i].speedy = true;
				car[i].il = true;
				car[i].ir = false;
				car[i].l = d;
				car[i].r = std::min(d + s, (double)len);
			} else {
				car[i].speedy = false;
			}
		}
		if (car[i].speedy == false) continue;
		if (car[i].l > mx or (car[i].l == mx and car[i].il == false)) {

		} else {
			ans1++;
		}
	}
	if (ans1 == 0) printf("%d %d\n", ans1, m);
	else printf("%d %d\n", ans1, m - 1);
}
void solve() {
	bool judge_small_case = true;
	bool judge_property_a = true;
	bool judge_property_b = true;
	bool judge_property_c = true;
	scanf("%d%d%d%d", &n, &m, &len, &vlimit);
	for (int i = 1; i <= n; i++) {
		double d;
		int v, a;
		scanf("%lf%d%d", &d, &v, &a);
		car[i].d = d;
		car[i].v = v;
		car[i].a = a;
		if (a != 0) judge_property_a = false;
		if (a <= 0) judge_property_b = false;
		if (a >= 0) judge_property_c = false;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lf", monitor + i);
	}

	if (n <= 20 and m <= 20) solve_small_case();
	else if (judge_property_a or judge_property_b) solve_property_ab();
	// else if (judge_property_c) solve_property_c();
	// else solve();
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
