#include <bits/stdc++.h>
#define int long long
#define maxn 1000010
using namespace std;

int f[maxn];
string s, ans;
bool check() {
	for (int i = 1; i <= 9; i++) {
		if (f[i]) {
			return true;
		}
	}
	return false;
}
void solve() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			f[s[i] - '0']++;
		}
	}
	if (!check()) {
		cout << 0 << endl;
		exit(0);
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < f[i]; j++) {
			ans += i + '0';
		}
	}
	cout << ans << endl;
}
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	solve();
	return 0;
}

