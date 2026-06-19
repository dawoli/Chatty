#include <iostream>
#include <cstdio>

using namespace std;
const int mod = 998244353;

int n, m, a[510], dp[510], cnt[510];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 500; i >= 1; i--) {
		cnt[i] += cnt[i - 1];
	}
	int ans = 1;
	for (int i = n; i >= 1; i--)
		ans *= n, ans %= mod;
	cout <<ans <<"\n";
	return 0;
}
