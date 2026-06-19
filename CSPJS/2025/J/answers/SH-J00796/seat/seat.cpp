#include <bits/stdc++.h>
using namespace std;

int n, m, k, idx, a[105];

int cmp (int x, int y) {
	return x > y;
}

int main () {

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i*n+j];
		}
	}
	k = a[1];

	sort (a+1, a+n*m+1, cmp);

	for (int i = 1; i <= n*m; i++) {
		if (a[i] == k) {
			idx = i;
			break;
		}
	}

	if (((idx/n) % 2 == 0 && (idx % n != 0)) || (idx % n == 0 && (idx/n)%2 == 1)) {
		if (idx % n == 0) {
			cout << idx/n << " " << n;
		} else {
			cout << idx/n+1 << " " << idx % n;
		}

		return 0;
	} else {
		if (idx % n == 0) {
			cout << idx/n << " " << (2*n+1-n) % n;
		} else {
			cout << idx/n+1 << " " << (idx/n+1)*n+1-idx;
		}

		return 0;
	}

	return 0;
}
