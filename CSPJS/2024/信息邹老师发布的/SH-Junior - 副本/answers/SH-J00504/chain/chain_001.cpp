#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, q, k, r, c, l[2010], s[2010][2010];

signed main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	cin >> n >> k >> q;
	for(int i = 1;i <= n;i++) {
		cin >> l[i];
		for(int j = 1;j <= l[i];j++) cin >> s[i][j];
	}
	while(q--) {
		int f = 0;
		cin >> r >> c;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= l[i];j++) {
				if(s[i][j] == c) {
					for(int k = j - k + 1;j <= j - 1;k++) 
						//cout << s[i][k] << endl;
					    if(s[i][k] == r) f = 1;
				}
			}
		}
		if(f == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
} 
