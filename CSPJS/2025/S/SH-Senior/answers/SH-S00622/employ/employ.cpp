#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int c[505];

ll perm(int k) {
	ll ans = 1;
	for (ll i = 1; i <= k; i++) {
		ans *= i;
		ans %= MOD;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	
	int mx = n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		if (c[i] == 0) mx--;
	}
	
	if (mx < m) {
		cout << 0;
		return 0;
	}
	
	sort(c, c + n);
	
	ll res = 0;
	do {
		int cnt = 0;
		int gvu = 0;
		for (int i = 0; i < n; i++) {
			if (c[i] <= gvu) gvu++;
			else cnt++;
		}
		if (cnt >= m) res++;
	} while (next_permutation(c, c + n));
	
	cout << (res % MOD) - 1;
	return 0;
}
