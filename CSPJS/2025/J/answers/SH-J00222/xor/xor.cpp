#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5, N2 = 1e3 + 5;
int n, k;
int a[N];
int f[N2][N2];
int sa[N];

void init() {
	for (int i = 1; i <= n; ++i) {
		sa[i] = sa[i - 1] ^ a[i];
	}
}

void solve_Testcase_1() {

}

void dp() {
	for (int i = 1; i <= n; ++i) {
		if (a[i] == k) f[i][i] = 1;
	}
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			if ((sa[j] ^ sa[i - 1]) == k) f[i][j] = max(f[i][j], 1ll);
			for (int k = i; k < j; ++k) {
				//printf("f[%lld][%lld] = max(%lld, f[%lld][%lld] (%lld) + f[%lld][%lld] (%lld)\n", i, j, f[i][j], i, k, f[i][k], k + 1, j, f[k + 1][j]);
				 f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
			}
		}
	}
	cout << f[1][n] << endl;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	init();
	//for (int i = 1; i <= n; ++i) cout << sa[i] << " ";
	//cout << endl;
	dp();	
	return 0;
}
