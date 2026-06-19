#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

int n, m, k, a[N], c[N], t; 
string d[N];
 
int cal(int x) {
	int k = 0;
	while (pow(2, k) < x) {
		k++;
	}
	return k;
}
 
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> c[i];
	k = cal(n);
	for (int i = 1; i <= k; i++) cin >> d[i];
	cin >> t;
	while (t--) {
		int x[4], ans[N] = {0};
		for (int i = 0; i < 4; i++) cin >> x[i];
		for (int i = 1; i <= n; i++) a[i] ^= x[i % 4];
		for (int i = 1; i <= m; i++) {
			for (int i = 1; i <= k; i++) {
				
			}
		}
	}
	return 0;
} 
