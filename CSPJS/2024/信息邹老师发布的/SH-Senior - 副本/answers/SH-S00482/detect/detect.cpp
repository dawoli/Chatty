#include<bits/stdc++.h>
using namespace std;

struct Car { int d, v, a; };
const int MAX_N = 1e5 + 10;

int T, n, m, L, V, p[MAX_N];
vector<pair<int, int> > req;
Car c[MAX_N];

void solve() {
	scanf("%d%d%d%d", &n, &m, &L, &V);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
	for (int i = 1; i <= m; i++)
		scanf("%d", &p[i]);
	req.clear();
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int d = c[i].d, v = c[i].v, a = c[i].a;
		if (a > 0) {
			double x = 1.0 * (V * V - v * v) / (2 * a);
			x = d + max(x, 0.0);
			if (x >= p[m]) continue;
			int pos = lower_bound(p + 1, p + m + 1, x) - p;
			ans++; req.push_back({pos, m});
		}
		else if (a != 0) {
			if (v <= V) continue;
			double x = 1.0 * (v * v - V * V) / (-a * 2) + d;
			int le = lower_bound(p + 1, p + m + 1, d) - p, ri = m;
			if (x <= p[m]) ri = lower_bound(p + 1, p + m + 1, x) - p - 1;
			if (le > ri) continue;
			ans++, req.push_back({le, ri});
		}
		else if (v > V && d <= p[m]) {
			ans++; int pos = lower_bound(p + 1, p + m + 1, d) - p;
			req.push_back({pos, m});
		}
	}
	printf("%d ", ans);
	
	sort(req.begin(), req.end());
	int l = 0, r = m + 1, cnt = 1;
	for (auto& i : req) {
		l = max(l, i.first), r = min(r, i.second);
		if (l > r) cnt++, l = i.first, r = i.second;
	}
	printf("%d\n", m - cnt);
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
