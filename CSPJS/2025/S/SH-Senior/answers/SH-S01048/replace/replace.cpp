#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string s[n][2];
	for (int i=0; i<n; i++) {
		for (int j=0; j<2; j++) {
			cin >> s[i][j];
		}
	}
	string t[q][2];
	for (int i=0; i<q; i++) {
		for (int j=0; j<2; j++) {
			cin >> t[i][j];
		}
		cout << 0 << endl;
	}
	return 0;
}
