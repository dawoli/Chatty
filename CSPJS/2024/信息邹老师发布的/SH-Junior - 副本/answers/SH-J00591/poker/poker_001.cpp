#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, t[5][20];
string str;
ll x, y;

int main() {
	freopen ("poker.in", "r", stdin);
	freopen ("poker.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> str;
		if (str[0] == 'D') x = 1;
		if (str[0] == 'C') x = 2;
		if (str[0] == 'H') x = 3;
		if (str[0] == 'S') x = 4;
		
		if (str[1] == 'T') y = 10;
		else if (str[1] == 'J') y = 11;
		else if (str[1] == 'Q') y = 12;
		else if (str[1] == 'K') y = 13;
		else if (str[1] == 'A') y = 1;
		else y = str[1] - '0';
		t[x][y]++;
	}
	ll cnt = 0;
	for (ll i = 1; i <= 4; i++) {
		for (ll j = 1; j <= 13; j++) {
			if (t[i][j] == 0) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
