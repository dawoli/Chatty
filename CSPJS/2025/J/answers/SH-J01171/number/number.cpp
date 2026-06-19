#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if ('0' <= c && c <= '9') {
			int digit = c - '0';
			cnt[digit]++;
		}
	}
	
	for (int i = 9; i >= 0; --i) {
		for (int j = 1; j <= cnt[i]; ++j) {
			cout << i;
		}
	}
	
	return 0;
}
