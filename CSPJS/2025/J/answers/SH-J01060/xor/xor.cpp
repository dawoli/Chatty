#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;

int n, k, a[N], s[N];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(nullptr), cout.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	s[1] = a[1];
	for(int i = 2; i <= n; ++i) s[i] = s[i - 1] ^ a[i];
	int last = 0, res = 0;
	for(int i = 1; i <= n; ++i) { // O(n) 正确性？
		for(int j = i; j > last; --j)
			if((s[i] ^ s[j - 1]) == k) {
				last = i;
				res++;
				break;
			}
	}

	cout << res << "\n";
	return 0;
}
