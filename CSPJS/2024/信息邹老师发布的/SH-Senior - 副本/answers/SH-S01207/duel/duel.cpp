#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[100010];
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout); 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	int pos = 1;
	for (int i = 2; i <= n; i++) {
		if (a[pos] > a[i]) {
			ans++;
			pos++;
		}
	}
	cout << n - ans;
	return 0;
} 
