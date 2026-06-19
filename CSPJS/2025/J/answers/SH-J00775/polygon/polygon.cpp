#include<iostream>
#include<algorithm>
using namespace std;

int n, a[5010], sum;
unsigned long long b[50010], ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	b[0] = 1;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		if (sum > 2 * a[i]) {
			ans++;
			for (int j = sum - 2 * a[i] - 1; j >= 1; j--) {
				ans += b[j];
				ans %= 998244353;
			}
		}
		for (int j = 50000 - a[i]; j >= 0; j--) {
			b[j + a[i]] += b[j];
		}
	}
	cout << ans;
	
	return 0;
}  
