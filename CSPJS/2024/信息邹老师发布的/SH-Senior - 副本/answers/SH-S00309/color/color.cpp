#include <iostream>
#include <cstring>
using namespace std;

#define int long long

const int N = 1e5 + 5;
const int M = 1e6 + 5;

int n;
int a[N];

int lst[M];
int sum[N];
int r[N];
int etr[N];

int v[2];
int tot[2];
int x[2][N];

namespace bl {
	int tot[2];
	int x[2][25];
	void solve() {
		int res = 0;
		for (int i = 0; i < (1 << n); i++) {
			tot[0] = tot[1] = 0;
			for (int j = 1; j <= n; j++) {
				if (i & (1 << (j - 1))) {
					x[1][++tot[1]] = a[j];
				} else {
					x[0][++tot[0]] = a[j];
				}
			}
			int ans = 0;
			for (int i = 0; i <= 1; i++) {
				for (int j = 2; j <= tot[i]; j++) {
					ans += x[i][j] * (x[i][j] == x[i][j - 1]);
				}
			}
			res = max(res, ans);
		}
		cout << res << "\n";
	}
}

inline void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 20) {
		bl::solve();
		return;
	}
	memset(lst, 0, sizeof(lst));
	for (int i = n; i >= 1; i--) {
		int ri = lst[a[i]];
		r[i] = ri;
		sum[i] = sum[ri] + a[i];
		if (!ri) sum[i] = 0;
		else if (sum[ri] == 0) sum[i] += a[i];
		lst[a[i]] = i;
	}
//	for (int i = 1; i <= n; i++) {
//		etr[i] = etr[i - 1] + a[i] * (a[i] == a[i - 1]);
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << sum[i] << " ";
//	}
//	cout << endl;
//	for (int i = 1; i <= n; i++) {
//		if (r[i])
//		sum[i] += (r[i] ? etr[r[i]] : etr[n]) - etr[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cout << sum[i] << " ";
//	}
//	cout << endl;
	v[0] = v[1] = tot[0] = tot[1] = 0;
	for (int i = 1; i <= n; i++) {
		int idx = (v[1] < v[0]);
		for (int j = 0; j <= 1; j++) if (x[j][tot[j]] == a[i]) idx = j;
		x[idx][++tot[idx]] = a[i];
		v[idx] = sum[i];
	}
	int ans = 0;
	for (int i = 0; i <= 1; i++) {
//		for (int j = 1; j <= tot[i]; j++) {
//			cout << x[i][j] << " ";
//		}
//		cout << endl;
		for (int j = 2; j <= tot[i]; j++) {
			ans += x[i][j] * (x[i][j] == x[i][j - 1]);
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
