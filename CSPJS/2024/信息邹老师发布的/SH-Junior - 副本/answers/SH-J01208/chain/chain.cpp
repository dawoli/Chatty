#include <bits/stdc++.h>
using namespace std;
int t;
bool ff;
int n, k, q;
int r, c; 
int l[100010];
vector<int> a[100010];
void dfs(int x, int y, int pre) {
	if (x > r) {
		if (y == c) ff = 1;
		return;
	}
	if (ff == 1) return;
	for (int i = 1; i <= n; i++) {
		if (i == pre) continue;
		for (int s = 0; s < l[i]; s++) {
			if (a[i][s] == y) {
				for (int e = s + 1; e < min(l[i], s + k); e++) {
					dfs(x + 1, a[i][e], i);
				}
			}
		}
	}
}
int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++) {
			cin >> l[i];
			for (int j = 1; j <= l[i]; j++) {
				int x; cin >> x;
				a[i].push_back(x);
			}
		}
		for (int i = 1; i <= q; i++) {
			ff = 0;
			cin >> r >> c;
			dfs(1, 1, 0);
			cout << ff << endl;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= l[i]; j++) {
				a[i].pop_back();
			}
		}
	}
	return 0;
}
//I AK IOI!
//RP+++++++++++++ 
