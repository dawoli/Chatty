#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5, MOD = 998244353;
int n;
int a[N];


int fa[N];

/* DFS part START */

int cnt;

void dfs(int x, int sum, int maxn) {
	if (x == n + 1) {
		if (sum > 2 * maxn) cnt++;
		return;
	}
	// choose
	dfs(x + 1, sum + a[x], max(maxn, a[x]));
	// not choose
	dfs(x + 1, sum, maxn);
}

/* DFS part END */



int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool all1 = true;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != 1) {
			all1 = false;
		}
	}
 	if (all1) {
		int first = 1;
		for (int i = 1; i <= n; ++i) {
			first = first * 2 % MOD;
		}
		first  = first - n;
		first = first - n * (n - 1) / 2;
		first = first - 1;
		cout << (first % MOD + MOD) % MOD << endl;
	}
	else if (n <= 40) {
		dfs(1, 0, 0);
		cout << cnt << endl;
	}
	return 0;
}
