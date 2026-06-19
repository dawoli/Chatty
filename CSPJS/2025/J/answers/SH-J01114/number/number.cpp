#include <bits/stdc++.h>
using namespace std;
string s;
int ans[1000006], wz = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); ++i) 
		if (s[i] <= '9' && s[i] >= '0') 
			ans[++wz] = s[i] - '0';
	sort(ans + 1, ans + wz + 1);
	if (ans[wz] == 0) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = wz; i >= 1; --i) cout << ans[i];
	return 0;
}

