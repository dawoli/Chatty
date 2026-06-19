#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

const int M = 1e6 + 5;
const int N = 1e5 + 5;

int n, m, K;
int a[N];
int c[N];
int d[25][M];
int x[5];

struct node {
	int vl, id;
	node () {}
	node (int v, int i) {
		vl = v; id = i;
	}
};

inline bool cmp(const node & l, const node & r) {
	return l.vl < r.vl;
}

node bf[N];
node qy[N];

int ans[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while ((1 << K) < n) K++;
	for (int i = 1; i <= m; i++) {
		cin >> c[i];
		qy[i] = node(c[i], i);
	}
	sort(qy + 1, qy + 1 + m, cmp);
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= 1 << (K - i); j++) {
			char c;
			cin >> c;
			d[i][j] = (c == '1');
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < 4; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++) {
		a[i] = a[i] ^ (x[i % 4]);
	}
	for (int i = 1; i <= n; i++) {
		bf[i] = node(a[i], i);
	}
	int tot = n;
	int idx = 0;
	for (int i = 1; i <= K; i++) {
		while (idx < m && qy[idx + 1].vl == (1 << (i - 1))) {
			idx++;
//			cout << "# " << (1 << (i - 1)) << "\n";
			ans[qy[idx].id] = bf[1].id;
		}
		int cnt = 0;
		for (int j = 1; j <= tot; j += 2) {
			cnt++;
			int ps = j + d[i][cnt];
			int np = j + (!d[i][cnt]);
			if (bf[ps].vl < i) {
				bf[cnt] = bf[np];
			} else {
				bf[cnt] = bf[ps];
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= m; i++) {
		res ^= (i * ans[i]);
	}
	cout << res;
}
