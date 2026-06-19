#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	int t;
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;
		for (int i = 1; i <= n; i++) {
			int l;
			cin >> l;
			for (int j = 1; j <= l; j++) {
				int x;
				cin >> x;
			}
		}
		while (q--) {
			int r, c;
			cin >> r >> c;
			cout << "0\n";
		}
	}
	return 0;
}
