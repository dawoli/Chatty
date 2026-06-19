#include <bits/stdc++.h>
using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
}

int n;
const int MXN = 200, MXN2 = 1e5;
int a[MXN+1][4];
//int f[MXN+1][MXN/2+1][MXN/2+1];
int f[2][MXN/2+1][MXN/2+1];
int g[2][MXN2/2+1];
bool cur_row = true;

void dp(int i, int p1, int p2, int p3) {
	int ans = 0;
	if (p3 <= n/2) {
		if (p1 != 0) ans = max(ans, f[!cur_row][p1-1][p2] + a[i][1]);
		if (p2 != 0) ans = max(ans, f[!cur_row][p1][p2-1] + a[i][2]);
		if (p3 != 0) ans = max(ans, f[!cur_row][p1][p2] + a[i][3]);
	}
	f[cur_row][p1][p2] = ans;
}

void dp2(int i, int p1, int p2) {
	int ans = 0;
	if (p2 <= n/2) {
		if (p1 != 0) ans = max(ans, g[!cur_row][p1-1] + a[i][1]);
		if (p2 != 0) ans = max(ans, g[!cur_row][p1] + a[i][2]);
	}
	g[cur_row][p1] = ans;
}

void solve() {
	memset(f, 0, sizeof(f));
	cur_row = true;
	for (int i = 1; i <= n; i++) {
		for (int p1 = 0; p1 <= n/2; p1++) {
			for (int p2 = 0; p2 <= n/2; p2++) {
				dp(i, p1, p2, i-p1-p2);
			}
		}
		cur_row = !cur_row;
	}
	
	int ans = 0;
	for (int p1 = 0; p1 <= n/2; p1++) {
		for (int p2 = 0; p2 <= n/2; p2++) {
			ans = max(ans, f[!cur_row][p1][p2]);
		}
	}
	cout << ans << '\n';
}

void solve2() {
	memset(g, 0, sizeof(g));
	cur_row = true;
	for (int i = 1; i <= n; i++) {
		for (int p1 = 0; p1 <= n/2; p1++) {
			dp2(i, p1, i-p1);
		}
		cur_row = !cur_row;
	}
	
	int ans = 0;
	for (int p1 = 0; p1 <= n/2; p1++) {
		ans = max(ans, g[!cur_row][p1]);
	}
	cout << ans << '\n';
}

int main() {
    init();

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	cin >> n;
    	for (int i = 1; i <= n; i++) {
    		cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		if (n > MXN) {
			solve2();
		} else {
			solve();
		}
	}
}
