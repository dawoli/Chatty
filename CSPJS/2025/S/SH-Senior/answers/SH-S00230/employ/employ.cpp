#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, c[505], sum[505], ans = 1, id;
bool s[505];
string st;
int f(int x) {
	int mul = 1;
	for (int i = x; i > 1; i--) {
		mul *= i;
		mul %= 998244353;
	}
	return mul;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> st;
	for (int i = 0; i < st.size(); i++) {
		s[i + 1] = st[i] - '0'; 
		sum[i + 1] = sum[i] + (s[i + 1] != 1);
	}
	s[0] = 1;
	for (int i = 1; i <= n; i++) cin >> c[i];
	int maxi = n, i = n;
	sort(c + 1, c + 1 + n);
	for (int cnt = 0; ; ) {
		if (s[++id]) cnt++;
		if (cnt == m) break;
	}
	while (id > 0) {
		if (s[id]) {
			while (i > sum[id] + 1) i--;
			ans *= maxi - i;
			ans %= 998244353;
			maxi--;
		}
		id--;
		while (!s[id]) id--;
	}
	ans *= f(n - m);
	ans %= 998244353;
	cout << ans << '\n';
	return 0;
}
