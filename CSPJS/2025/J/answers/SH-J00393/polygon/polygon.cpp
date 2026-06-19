#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 5e3 +10;
const int mod = 998244353;

int n, a[N], c[N][N];

void pre() {
	c[0][0] = 1;
	c[1][0] = c[1][1] = 1;
	for (int i = 2; i <= 5000; i++)
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	pre();
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n == 3) {
		if (a[1] +a[2] > a[3]) cout <<1 <<"\n";
		else cout <<"0\n";
	} else if (a[n] == 1) {
		int ans = 0;
		for (int j = 3; j <= n; j++)
			ans = (ans + c[n][j]) % mod;
		cout << ans <<"\n";
	}
	return 0;
}
