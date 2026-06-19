// sticks.cpp
#include <iostream>
#include <cstdio>
using namespace std;
int t;
// matches: the required number of matches to create a digit
// ans: the answer for every posible n
int matches[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }, ans[100005];
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	// initialization (processing)
	for (int i = 1; i < 50005; ++i) {
		int cnt = 0;
		for (int j = i; j > 0; j /= 10) cnt += matches[j % 10];
		if (ans[cnt] == 0) ans[cnt] = i;
	}
	cin >> t;
	while (t--) {
		// query
		int n;
		cin >> n;
		// output
		if (ans[n]) cout << ans[n] << endl;
		else cout << -1 << endl;
	}
	return 0;
}
