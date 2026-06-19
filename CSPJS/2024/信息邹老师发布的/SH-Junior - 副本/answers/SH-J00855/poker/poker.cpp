#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int lst[5][15];

int change(char s) {
	if (s == 'A') return 1;
	else if (s == 'T') return 10;
	else if (s == 'J') return 11;
	else if (s == 'Q') return 12;
	else if (s == 'K') return 13;
	else if (s == 'D') return 1;
	else if (s == 'C') return 2;
	else if (s == 'H') return 3;
	else if (s == 'S') return 4;
	else return s - '0';
}

signed main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if (!lst[change(s[0])][change(s[1])]) {
			lst[change(s[0])][change(s[1])] = 1;
			ans++;
		}
	}
	cout << 52 - ans;
}
