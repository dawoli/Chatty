#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a>b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n*m] = {0};
	for (int i=0; i<n*m; i++) {
		cin >> a[i];
	}
	int scorer = a[0];
	sort(a, a+n*m, cmp);
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (a[int(ceil(sqrt(n*m))*i)+j]==scorer) {
				cout << i+1 << " " << j+1 << endl;
				return 0;
			}
		}
	}
	return 0;
}
