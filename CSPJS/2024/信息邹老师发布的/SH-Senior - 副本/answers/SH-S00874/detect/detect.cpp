#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, inf = 0x3f3f3f3f, M = 3010;

double v_square_lim;
int l, n, m;
double p[N];

struct Car {
	double x, v, a;
	Car(double xxx, double vvv, double aaa) {
		x = xxx, v = vvv, a = aaa;
	}
	Car() {}
	double x_stop() {
		if (a > 0) return l;
		return x - v * v / (2 * a);
	}
	double v_square(double x_final) {
		return v * v+ 2 * a * (x_final - x);
	}
} cars[N];

set<int> valid_stations[M], s;
bool skip[N];

template<typename T> void chk_merge(set<T>& lhs, const set<T>& rhs) {
	set<T> res;
	for (auto x : lhs) {
		if (rhs.find(x) == rhs.end()) continue;
		res.insert(x);
	}
	lhs = res;
}

void init() {
	s.clear();
	for (int i = 1; i <= m; ++i) {
		valid_stations[i].clear();
	}
	memset(skip, 0, sizeof skip);
}

int find_idx(double x) {
	return lower_bound(p + 1, p + 1 + m, x) - p;
}

double x_lim(const Car& c) {
	return c.x + (v_square_lim - (c.v * c.v)) / (2 * c.a);
}

void modify(int i, int first, int last) {
	if (first > last) {
		skip[i] = true;
		return;
	}
	for (int idx = first; idx <= last; ++idx) {
		valid_stations[i].insert(idx);
		s.insert(idx);
	}
}

void solve() {
	cin >> n >> m >> l >> v_square_lim;
	init();
	v_square_lim = v_square_lim * v_square_lim;
	for (int i = 1; i <= n; ++i) {
		int x, v, a;
		cin >> x >> v >> a;
		cars[i] = Car(x, v, a);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> p[i];
	}
	int ans1 = 0;
	for (int i = 1; i <= n; ++i) {
		auto& c = cars[i];
		if (c.a > 0) {
			if (c.v_square(p[m]) > v_square_lim) {
				++ans1;
				// cerr << "*** " << x_lim(c) << endl;
				int first = find_idx(x_lim(c)), last = m;
				if (1.00 * p[first] == x_lim(c)) ++first;	// todo
				// cerr << "+ " << first << " " << last << endl;
				modify(i, first, last);
			}
		} else if (c.a < 0) {
			int first = find_idx(c.x), last = upper_bound(p + 1, p + 1 + n, x_lim(c)) - p;
			// cerr << "xlim = " << x_lim(c) << endl;
			// cerr << "- " << first << " " << last << " " << endl;
			while (p[last] >= x_lim(c)) --last;
			// cerr << "- " << first << " " << last << " " << endl;
			// cerr << c.v_square(p[first]) << ", lim = " << v_square_lim << endl;
			if (c.v_square(p[first]) > v_square_lim) {
				// cerr << i << " try" << endl;
				if (1.00 * p[first] > c.x_stop()) {skip[i] = true; continue;}
				// cerr << "<0 && exceeded vlim\n";
				++ans1;
				modify(i, first, last);
			}
		} else {
			// a == 0
			if (c.v * c.v > v_square_lim) ++ans1;
			skip[i] = true;
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (skip[i]) continue;
		// cerr << i << ": ";
		// for (auto x : valid_stations[i]) {
			// cerr << x << " ";
		// }
		// cerr << endl;
		chk_merge(s, valid_stations[i]);
	}
	// cerr << "s: ";
	// for (auto x : s) {
	// 	cerr << x << " ";
	// }
	// cerr << endl;
	cout << ans1 << " " << n - (int)s.size() << endl;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	// ------------------------
	// #ifdef LOCAL
	// cerr << "\n[Finished]" << endl;
	// getchar();
	// #endif
	return 0;
}