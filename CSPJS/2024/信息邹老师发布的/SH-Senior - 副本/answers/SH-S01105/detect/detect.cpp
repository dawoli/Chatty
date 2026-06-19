#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e5 + 7;
constexpr double eps = 1e-6;

ll n, m, L, V;

struct car {
	ll d, v, a;
} c[N];

ll p[N];

namespace A {
	ll v[N];
	
	void solve() {
		memset(v, 0, sizeof v);
		
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			ll di = c[i].d, vi = c[i].v, ai = c[i].a;
			if (p[m] >= di && vi > V) ++ans;
		}
		printf("%lld %lld\n", ans, ans == 0 ? m : m - 1);
	}
}


namespace B {
	ll v[N];
	void solve() {
		memset(v, 0, sizeof v);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int di = c[i].d, vi = c[i].v, ai = c[i].a;
			if (p[m] >= di && (vi * vi + 2 * ai * (p[m] - di) > V * V))
				++ans;
		}
		printf("%lld %lld\n", ans, ans == 0 ? m : m - 1);
	}
}

namespace C {
	ll v[N], pos[N];
	
	struct carr {
		int p, id;
		bool operator<(carr x) {
			return p == x.p ? c[id].d > c[x.id].d : p < x.p;
		}
	} cc[N];
	
	void solve1() {
		memset(v, 0, sizeof v);
		memset(cc, 0, sizeof cc); 
		for (int i = 1; i <= n; ++i) {
			int di = c[i].d, vi = c[i].v, ai = c[i].a;
			for (int j = 1; j <= m; ++j) {
				if (p[j] < di) continue;
				if (vi * vi + 2 * ai * (p[j] - di) > V * V)
					pos[i] = j;
			}
		}
		
		for (int i = 1; i <= n; ++i) cc[i] = {pos[i], i};
		sort(cc + 1, cc + n + 1);
		
		int ans = 0;
		for (int i = 1; i <= m; ++i) if (pos[i]) ++ans;
		
		int p = 2, res = 0;
		for (int i = 1; i <= n; ++i) {
			int id = cc[i].id;
			while (p <= n) {
				int pd = cc[p].id;
				if (c[pd].d <= pos[id]) {
					++res;
					++p;
				} else if (c[pd].d > pos[id]) {
					i = p;
					++p;
					break;
				}
			}
		}
		printf("%lld %lld\n", ans, res);
	}
}

void solve() {
	scanf("%lld %lld %lld %lld", &n, &m, &L, &V);
	for (int i = 1; i <= n; ++i) {
		ll d, v, a;
		scanf("%lld %lld %lld", &d, &v, &a);
		c[i] = {d, v, a};
	}
	for (int i = 1; i <= m; ++i) scanf("%lld", p + i);
	
	ll aa = 1, bb = 1, cc = 1;
	for (int i = 1; i <= n; ++i) aa &= c[i].a == 0;
	for (int i = 1; i <= n; ++i) bb &= c[i].a > 0;
	for (int i = 1; i <= n; ++i) cc &= c[i].a < 0;
	
	if (aa) A::solve();
	else if (bb) B::solve();
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	ll T;
	scanf("%lld", &T);
	while (T--) solve();
	
	return 0;
}

