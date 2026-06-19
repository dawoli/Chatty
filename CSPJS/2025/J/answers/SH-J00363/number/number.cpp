#include <bits/stdc++.h>
using namespace std;

string st, s, ans, sd;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> st;
	int len = st.size();
	for (int i = 0; i < len; i++) {
		if (st[i] >= '0' && st[i] <= '9') {
			s += st[i];
		}
	}
	len = s.size();
	sd = "9876543210";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < len; j++) {
			if (s[j] == sd[i]) {
				ans += s[j];
			}
		}
	}
	cout << ans;
	return 0;
}
