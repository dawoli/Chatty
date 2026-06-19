#include <iostream>
using namespace std;
int t, n, num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, ans = 1e9;
void dfs(int pr, int n, int sum) {
	if (n == 0) {
		ans = min(ans, sum);
		return ;
	}
	if (n < 2) return ;
		for (int i = pr; i <= 9; i++) {
	        sum *= 10;
	        sum += i;
			n -= num[i];
	        dfs(i, n, sum);
			n += num[i];
	        sum /= 10;
		}
}
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 1e9;
		cin >> n;
		if (n % 7 == 0) {
			int s = n / 7;
			for (int i = 1; i <= s; i++) cout << 8;
			cout << endl;
			return 0;
		} 
		if (n < 2) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 1; i <= 9; i++) {
			dfs(0, n - num[i], i);
		}
		if (ans == 1e9) cout << - 1 << endl;
		else cout << ans << endl;
	}
	return 0;
} 
