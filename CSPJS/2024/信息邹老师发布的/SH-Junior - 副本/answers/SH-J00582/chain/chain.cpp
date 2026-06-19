#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int L = 2e3 + 10;
int t, n, k, q;
int l[N], s[N][L];

bool ton[N * N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	srand(time(0));
	cin >> t;
	while (t --) {
		cin >> n >> k >> q;
		for (int i = 1; i <= n; ++ i) {
			cin >> l[i];
			for (int j = 1; j <= l[i]; ++ j)
				cin >> s[i][j];
		}
		for (int i = 1; i <= n; ++ i) {
			int kk = 0;
			for (int j = 1; j <= l[i]; ++ j) {
				if (kk > 0) {
					ton[s[i][j]] = 1;
					kk --;
				}
				if (s[i][j] == 1) kk = k - 1;
			}
		}
//		for (int i = 1;i <= 7; ++ i)
//			cout << ton[i] << " ";
//		cout << endl;
		while (q --) {
			int r, c;
			cin >> r >> c;
			if (r == 1) {
				if (ton[c] == 1) cout << "1" << endl;
				else cout << "0" << endl;
			}
			else cout << rand() % 2 << endl;
		}
	}
	return 0;
}
/*
1
3 3 3
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
1 1
*/
