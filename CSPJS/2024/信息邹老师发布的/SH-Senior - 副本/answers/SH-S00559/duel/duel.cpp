# include <iostream>
# include <algorithm>
using namespace std;
int main() {
	int n, a[100001], ans = 0;
	cin >> n;
	bool vis[100001];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort (a, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] > a[j] && !vis[j]) {
				vis[j] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}

