#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	cin >> t;
	int ans = 0;
	while(t--) {
		int x,y,z;
		cin >> x >> y >> z;
		ans+=z;
		for(int i = 1; i <= x; i++) {
			int p;
			cin >> p;
			for(int j = 1; j <= p; j++) {
				int hdgf;
				cin >> hdgf;
			}
		}
		for(int i = 1; i <= z; i++) {
			int io, ko;
			cin >> io >> ko;
		}
	}
	for(int i = 1; i <= ans; i++) {
		if(i%3 == 1) cout << 0;
		else cout << 1;
	}
	return 0;
}
