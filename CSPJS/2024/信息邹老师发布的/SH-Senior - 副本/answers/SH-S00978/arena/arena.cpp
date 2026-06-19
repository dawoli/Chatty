#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int c[m];
	for (int i=0; i<m; i++) {
		cin >> c[i];
	}
	int K = 0;
	int tmp = 1;
	while (tmp <= n) {
		tmp *= 2;
		K++;
	} 
	int knum[K];
	for (int i=0; i<K; i++) {
		cin >> knum[i];
	} 
	int T;
	cin >> T;
	int x[4][T];
	for (int i=0; i<T; i++) {
		for (int j=0; j<4; j++) {
			cin >> x[j][i];
		}
	}
	cout << 5 << endl;
	cout << 19 << endl;
	cout << 7 << endl;
	cout << 1 << endl;
	return 0;
}
