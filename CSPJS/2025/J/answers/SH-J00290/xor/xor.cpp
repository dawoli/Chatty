#include <bits/stdc++.h>
using namespace std;
long long n, ans, maxAns, l, r, tem;
int k;
vector<int> a;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	// vector<bool> used(n, false); 
	// ^“ÏªÚ
	for (long long i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		a.push_back(num);
	}
		while (l < n && r < n) {
			bool found = false;
			// for (int i = l; i <= r && !used[i]; ++i) {
			for (int i = l; i <= r && l < n && r < n; ++i) {
				tem ^= a[i];
				// cout << l << " " << r << " " << tem << " " << ans << "\n";
				if (tem == k) {
					++ans;
					++r;
					// for (int i = l; i <= r; ++i) {
					//     used[i] = true;
					// }
					found = true;
					break;
				}
				else {
				++r;
				}
			}
			l = r;
			tem = 0;
		}
		maxAns = max(maxAns, ans);
		ans = 0;

	cout << maxAns;
	return 0;
}
