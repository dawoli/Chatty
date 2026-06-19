#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define PII pair<int, int>
#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define ROF(i, r, l) for (int i = (r); i >= (l); --i)
#define allc(x) (x).begin(), (x).end()
#define SZ size()
#define FI first
#define SE second
using namespace std;
const int N = 2e5 + 5;
const int inf = 1e18;
int T, n, m, a[N], ans[N], c[N], dep[N], w[N], _a[N], x[4], lg[N], b[N], cnt[N];
bool cx[10][10], d[20][N];
int solve(int x) {
	if (!x) {
		return ++cnt[x];
	}
	int l = solve(x - 1);
	int r = solve(x - 1);
	++cnt[x];
	if (!d[x][cnt[x]]) {
		return a[l] >= x ? l : r;
	} else {
		return a[r] >= x ? r : l;
	}
}
string str;
void dfs(int x) {
	if (x > (1 << dep[n])) {
		FOR (j, 1, n) {
			FOR (k, 0, 4) {
				cnt[k] = 0;
			}
			if (a[j] != b[j]) {
				break;
			}
			cx[j][solve(dep[j])] = 1;
		}
		return;
	}
	FOR (i, 0, 5) {
		a[x] = i;
		dfs(x + 1);
	}
}
void solBF() {
	cin >> T;
	while (T--) {
		FOR (i, 0, 3) {
			cin >> x[i];
		}
		FOR (i, 1, n) {
			a[i] = _a[i] ^ x[i % 4];
			b[i] = a[i];
		}
		memset(cx, 0, sizeof(cx));
		dfs(1);
		FOR (i, 1, n) {
			ans[i] = 0;
			FOR (j, 1, n) {
				if (cx[i][j]) {
					ans[i] += j;
				}
			}
		}
		int res = 0;
		FOR (i, 1, m) {
			res ^= i * ans[c[i]];
		}
		cout << res << '\n';
	}
}
signed main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	FOR (i, 1, N - 5) {
		dep[i] = ceil(log2(i));
	}
	cin >> n >> m;
	FOR (i, 1, n) {
		cin >> _a[i];
	}
	FOR (i, 1, m) {
		cin >> c[i];
	}
	FOR (i, 1, dep[n]) {
		cin >> str;
		FOR (j, 1, (1 << dep[n] - i)) {
			d[i][j] = str[j - 1] - '0';
		}
	}
	if (n <= 8) {
		solBF();
		return 0;
	}
	cin >> T;
	while (T--) {
		FOR (i, 0, 3) {
			cin >> x[i];
		}
		FOR (i, 1, n) {
			a[i] = _a[i] ^ x[i % 4];
		}
		FOR (i, 0, dep[n]) {
			FOR (j, 0, i) {
				cnt[j] = 0;
			}
			ans[i] = solve(i);
		}
		int res = 0;
		FOR (i, 1, m) {
			res ^= i * ans[dep[c[i]]];
		}
		cout << res << '\n';
	}
	return 0;
}
