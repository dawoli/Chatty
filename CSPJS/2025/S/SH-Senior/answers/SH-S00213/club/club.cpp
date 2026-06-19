// 廖晓刚万岁!!!
// 223199 223199 223199 223199 223199
// 533!!!



// dzx&zzr99
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, N2 = 5e4 + 5;
int t;
int n;
int a[N][4];

int f[205][105][105];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(f, 0, sizeof f);
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= n / 2; ++j) {
				for (int k = 0; k <= n / 2; ++k) {
					//int l = n - j - k;
					//if (l > n / 2) continue;
					int l = i - j - k;
					if (j != 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i][1]);
					if (k != 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][2]);
					if (l != 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][3]);
					//if (j == 0 && k == 0) f[i][j][k] = f[i - 1][j][k] + a[i][3];
					//else if (j == 0) f[i][j][k] = max(f[i - 1][j][k - 1] + a[i][2], f[i - 1][j][k] + a[i][3]);
					//else if (k == 0) f[i][j][k] = max(f[i - 1][j - 1][k] + a[i][1], f[i - 1][j][k] + a[i][3]);
					//else f[i][j][k] = max(f[i - 1][j - 1][k] + a[i][1], max(f[i - 1][j][k - 1] + a[i][2], f[i - 1][j][k] + a[i][3]));
				}
			}
		}
		int ans = 0, ansi = 0, ansj = 0;
		for (int i = 0; i <= n / 2; ++i) {
			for (int j = 0; j <= n / 2; ++j) {
				int k = n - i - j;
				if (k > n / 2) continue;
				//cout << k << endl;
				//if (f[n][i][j] >= ans) ansi = i, ansj = j, cout << ansi << " " << ansj << endl;
				ans = max(ans, f[n][i][j]);
			}
		}
		cout << ans << endl;
		//int curi = n, curj = ansi, curk = ansj;
		//while (curi) {
		//	if (f[curi][curj][curk] == f[curi - 1][curj - 1][curk] + a[curi][1]) {
		//		cout << "no. " << curi << ": " << 1 << endl;
		//		curi--;
		//		curj--;
		//	} else if (f[curi][curj][curk] == f[curi - 1][curj][curk - 1] + a[curi][2]) {
		//		cout << "no. " << curi << ": " << 2 << endl;
		//		curi--;
		//		curk--;
		//	} else if (f[curi][curj][curk] == f[curi - 1][curj][curk] + a[curi][3]) {
		//		cout << "no. " << curi << ": " << 3 << endl;
		//		curi--;
		//	} else {
		//		cout << "no. " << curi << ": ???" << endl;
		//		curi--;
		//	}
		//}	
	}
	return 0;
}
