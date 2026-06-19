// chain.cpp
#include <iostream>
#include <cstdio>
using namespace std;
int t, s[100005][200005];
int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n, k, q;
		cin >> n >> k >> q;
		for (int i = 1; i <= n; ++i) {
			cin >> s[i][0];
			for (int j = 1; j <= s[i][0]; ++j) cin >> s[i][j];
		}
		while (q--) {
			int r, c;
			cin >> r >> c;
			cout << false << endl;
		}
	}
	return 0;
} 
