#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int T, n, m, q, l[N], s[N][N];
int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n >> m >> q;
		for(int i = 1; i <= n; i++) {
			cin >> l[i];
			for(int j = 1; j <= l[i]; j++) cin >> s[i][j];
		}
		while(q--) {
			int r, c;
			cin >> r >> c;
			if(r == 1) {
				int flag = 0;
				for(int i = 1; i <= n; i++)
					for(int j = 1; j <= l[i]; j++) {
						if(s[i][j] != 1) continue;
						for(int k = 2; k <= min(l[i] - j + 1, m); k++)
							if(s[i][j + k - 1] == c) {
								flag = 1;
								break;
							}
					}
				cout << flag << "\n";
			}
		}
	}
	return 0;
}
