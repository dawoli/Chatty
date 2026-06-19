#include <iostream>
#include <cstdio>

using namespace std;
const int N = 5e5 + 10;

int n, m, a[N], sum[N]; 

bool check(int x) {
	int last = 1, s = 0;
	for (int i = 1; i <= n; i++) {
		if (sum[i] ^ sum[last - 1] == m) {
			last = i + 1, s++;
		}
	}
	cout << s;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	
	int last = 1, s = 0;
	for (int i = 1; i <= n; i++) {
		if ((sum[i] ^ sum[last - 1]) == m) {
			last = i + 1, s++;
		}
	}
	cout << s;
//	int l = 0, r = n;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		if (check(mid)) ans = mid, l = mid + 1;
//		else r = mid - 1;
//	}
 
	return 0;
}
