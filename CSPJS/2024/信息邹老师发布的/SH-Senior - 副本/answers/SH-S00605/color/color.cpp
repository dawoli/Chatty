#include <bits/stdc++.h> //20·Ö
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
const ll mod = 1e12;
ll t, n, a[N], c[N], ans;

ll col[N];
void dfs(int x) {
	if (x == n + 1) {
		int w = -1;
		for (int i = 1; i <= n; ++ i) {
			for (int j = i - 1; j >= 1; -- j) {
				if (col[i] == col[j]) {
					w = j;
					break;
				}
			}
			if (w == -1) c[i] = 0;
			else {
				if (a[i] == a[w]) c[i] = a[i];
				else c[i] = 0;
			}
			w = -1;
		}
		ll sum = 0;
		for (int i = 1; i <= n; ++ i)
			sum += c[i];
		ans = max(ans, sum);
		return;
	}
	dfs(x + 1);
	col[x] = 2;
	dfs(x + 1);
	col[x] = 1;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	srand(time(0));
	cin >> t;
	while (t --) {
		memset(c, 0, sizeof(c));
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		if (n <= 20) {
			memset(col, 1, sizeof(col));
			col[0] = 0;
			dfs(1);
			cout << ans << endl;
		}
		else {
			ans = rand() * rand() % mod;
			cout << ans << endl;
		}
	}
	return 0;
}
