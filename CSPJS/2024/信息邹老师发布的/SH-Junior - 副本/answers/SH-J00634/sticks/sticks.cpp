#include <iostream>
using namespace std;

typedef long long LL;

void print_8(int n) {
	for (int i = 0; i < n; i++) {
		cout << '8';
	}
	cout << endl;
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n <= 20) {
			int ans[21] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 67, 88, 108, 188, 200, 208, 288, 688};
			cout << ans[n] << endl;
			continue;
		}
		int pre[7] = {88, 108, 188, 200, 208, 288, 688};
		cout << pre[n % 7];
		print_8(n / 7 - 2);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
