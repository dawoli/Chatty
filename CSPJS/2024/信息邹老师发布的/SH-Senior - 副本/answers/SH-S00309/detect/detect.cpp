#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define int long long

inline int ceil(int x, int y) {
	return (x % y) ? ((x / y) + 1) : (x / y);
}
inline int sq(int x) {
	return x * x;
}

const int N = 1e5 + 5;
const int M = 1e6 + 5;

struct node {
	int l, r;
	node () {}
	node (int _l, int _r) {
		l = _l; r = _r;
	}
};

inline bool cmp(const node & l, const node & r) {
	return (l.r == r.r) ? (l.l < r.l) : (l.r < r.r);
}

int n, m, L, V;
int p[N];

int tot;
int cnt;
node ars[N];

struct BIT {
	int bit[M];
	int len = 1e6 + 1;
	// 记得要加一！！！
	inline void init() {
		memset(bit, 0, sizeof(bit));
	}
	inline int lb(int x) {
		return x & (-x);
	}
	inline void add(int x, int v) {
		if (x < 0) x = 0;
		x++;
		while (x <= len) {
			bit[x] += v;
			x += lb(x);
		}
	}
	inline int get(int x) {
		if (x < 0) x = 0;
		x++;
		int res = 0;
		while (x) {
			res += bit[x];
			x -= lb(x);
		}
		return res;
	}
};

BIT bit;

inline void solve() {
	tot = 0; cnt = 0;
	cin >> n >> m >> L >> V;
	for (int i = 1; i <= n; i++) {
		int d, v, a;
		cin >> d >> v >> a;
		if (a == 0) {
			// 匀速，若超速则全程超速
			if (v > V) ars[++tot] = node(d, L);
		} else if (a > 0) {
			// 匀加速，初速超速则全程超速，否则从某一点开始超速
			if (v > V) {
				ars[++tot] = node(d, L);
			} else {
				int x = (sq(V) - sq(v)) / (2 * a) + 1;
				if (d + x <= L) ars[++tot] = node(d + x, L);
			}
		} else {
			// 匀减速，初速不超速则全程不超速，否则从起点一直到某一点超速
			if (v > V) {
				int x = ceil(sq(V) - sq(v), 2 * a) - 1;
				ars[++tot] = node(d, min(d + x, L));
			}
		}
	}
	bit.init();
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
		bit.add(p[i], 1);
	}
	for (int i = 1; i <= tot; i++) {
//		cout << ars[i].l << " " << ars[i].r << "\n";
		if (bit.get(ars[i].r) - bit.get(ars[i].l - 1)) {
			ars[++cnt] = ars[i];
		}
	}
	cout << cnt << " ";
//	cout << "\n------------------\n";
	sort(ars + 1, ars + 1 + cnt, cmp);
	int res = 0;
	int idx = 0;
	int mar = -1;
	for (int i = 1; i <= cnt; i++) {
//		cout << ars[i].l << " " << ars[i].r << "\n";
		if (ars[i].l <= mar) continue;
		while (idx < m && p[idx + 1] <= ars[i].r) idx++;
		res++;
		mar = p[idx];
	}
	cout << m - res << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
