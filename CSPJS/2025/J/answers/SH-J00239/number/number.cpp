#include <bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') a[s[i] - '0']++;
	}
	bool flag = 0;
	for (int i = 9; i > -1; i--) {
		for (int j = 0; j < a[i]; j++) {
			cout << i;
			if (!flag && i == 0) break;
			flag = 1;
		}
	}
	cout <<'\n';
	return 0;
}
