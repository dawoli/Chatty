#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int a[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long cnt = 0;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 2; j <= n; j++) {
			int mx = 0;
			long long sum = 0;
			for (int k = i; k <= j; k++) {
				mx = max(mx, a[k]);
				sum += a[k];
			}
			if (sum > mx * 2) {
				cnt++;
			}
		}
	}
	cout << cnt % 998244353;
	return 0;
}
