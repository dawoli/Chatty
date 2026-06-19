#include <iostream>
#include <cstdio>
using namespace std;

int T;
int n;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long ans = 4e18;

int getnum(long long x) {
	int ret = 0;
	while (x) {
		ret += num[x % 10];
		x /= 10;
	}
	return ret;
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);

	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 1) {
			cout << -1 << endl;
			continue;
		}
		if (n <= 50) {
			long long max_int = 0;
			bool flag = false;
			for (int i = 1; i <= n / 6; i++) max_int = max_int * 10 + 9;
			max_int = max(max_int, 9ll);
			for (long long i = 1; i <= max_int; i++) {
				if (getnum(i) == n) {
					cout << i << endl;
					flag = true;
					break;
				}
			}
			if (!flag) cout << "-1" << endl;
		}
	}

	return 0;
}