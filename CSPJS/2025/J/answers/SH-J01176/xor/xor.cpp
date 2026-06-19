#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, a [N], s [N], dp [N];
int xorr (int i, int j) {
	if (i == 1) return s [j];
	else return s [j] ^ s [i - 1];
}
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a [i];
	s [1] = a [1];
	for (int i = 2; i <= n; i ++)
		s [i] = a [i] ^ s [i - 1];
	dp [0] = 0;
	for (int i = 1; i <= n; i ++) {
		dp [i] = dp [i - 1];
		for (int j = i - 1; j >= 0; j --)
			if (xorr (j + 1, i) == k) {
				dp [i] = max (dp [i], dp [j] + 1);
				break;
			}
	}
	cout << dp [n];
}