#include <iostream>
#include <algorithm>
using namespace std;
int n, m, x, ans, y;
int a[128];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	x = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n *m; i++) {
		if (a[i] == x) {
			ans = i;
			break;
		}
	}
	x = 1;
	while (ans > n) {
		ans -= n;
		x++;
	}
	cout << x << " ";
	if (x % 2)
		cout << ans;
	else
		cout << n - ans + 1;
	return 0;
} 
