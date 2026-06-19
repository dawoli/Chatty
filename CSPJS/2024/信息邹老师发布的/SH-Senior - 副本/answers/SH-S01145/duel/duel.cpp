#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	int n;
	int r[100005];
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> r[i];
	}
	
	sort(r, r + n);
	
	int cur = 1;
	int ked = 0;
	
	for (int i = 0; i < n; ++i) {
		while (r[cur] <= r[i] && cur < n - 1) ++cur;
		if (r[cur] > r[i]) {
			++ked;
			++cur;
		} else {
			break;
		}
	}
	
	cout << n - ked;
	
	return 0;
}

