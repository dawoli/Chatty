#include <bits/stdc++.h>
using namespace std;
int a[201];
int num;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = 1, m = 1;
	cin >> n >> m;
	int N = n * m;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	int r = a[1];
	sort(a + 1, a + N + 1);
	for (int i = 1; i <= N; i++)
		if (r == a[i]) {
			num = N - i + 1;
			break;
		}
	if (n == 1) {
		cout << "1 " << num;
		return 0;
	}
	if (m == 1) {
		cout << num << " 1";
		return 0;
	}
	int p;
	if (num % m == 0) p = num / m;
	else p = num / m + 1;
	cout << p << ' ';
	int q;
	if (num % n == 0) q = n;
	else q = num % n;
	if (p % 2 == 1) cout << q;
	else cout << n - q + 1;
	return 0;
}
