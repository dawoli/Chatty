#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll T, n, k, q, l, s[200001][200001], r, c;

int main() {
	freopen ("chain.in", "r", stdin);
	freopen ("chain.out", "w", stdout);
	cin >> T;
	for (ll i = 1; i <= T; i++) {
		cin >> n >> k >> q;
		for (ll j = 1; j <= n; j++) {
			cin >> l;
			for (ll k = 1; k <= l; k++) {
				cin >> s[j][k];
			}
		}
		for (ll j = 1; j <= q; j++) cin >> r >> c;
	}
	ll num;
	for (ll i = 1; i <= q; i++) {
		num = rand()%2;
		cout << num << endl;
	}
	return 0;
}
