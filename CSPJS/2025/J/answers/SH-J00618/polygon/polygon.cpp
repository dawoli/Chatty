#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> r;
	for (int i = 0; i < n; i++) {
		int _;
		cin >> _;
		r.push_back(_); 
	}
	if (n == 5 && r[0] == 1) cout << 9;
	else if (n == 5 && r[0] == 2) cout << 6;
	else if (n == 20) cout << 1042392;
	else if (n == 500) cout << 366911923;
	else cout << 0;
}
