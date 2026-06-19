#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10; 
int n;
int t;
int a[MAXN];
int score(int x) {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (a[i] == a[j] && ((x >> i) & 1) == ((x >> j) & 1)) {
				res += a[j];
				break;
			}
		}
	}
	return res;
}

int main() {
	freopen("color1.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		int ans = 0;
		for (int i = 0; i < (1 << n) - 1; ++i) {
			ans = max(ans, score(i));
		}
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
