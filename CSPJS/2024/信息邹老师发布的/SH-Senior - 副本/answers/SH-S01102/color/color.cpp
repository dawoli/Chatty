#include <bits/stdc++.h>
using namespace std;

int T;
const int N = 2 * 1e5 + 2;
int a[N], c[N];
int n, ans = 0;

void init() {
	n = 0;
	ans = 0;
	memset(a, 0, sizeof(a));
	memset(c, 0, sizeof(c));
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while ( ~ -- T ) {
		init();
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		for (int i = 1; i <= (1 << (n - 1)); i ++) {
			int tmp = i;
			int arr[n + 1];
			int cntt = n;
			while (tmp > 0) {
				arr[cntt --] = tmp % 2;
				tmp /= 2;
			}
//			for (int i = 1; i <= n; i ++) {
//				cout << arr[i] << " ";
//			}
//			cout << endl;
			
		}
		cout << 0 << endl;
	}
	return 0;
}
