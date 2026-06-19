#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, k, a[N], cnt, m;

int xbor(int x, int y) {
	if (x == y) return x;
	int l, sum, mul;
	string sx = "", sy = "", s = "";
	while (x > 0) {
		if (x % 2) sx += '1';
		else sx += '0';
		x /= 2;
	}
	while (y > 0) {
		if (y % 2) sy += '1';
		else sy += '0';
		y /= 2;
	}
	if (sx.size() >= sy.size()) {
		l = sy.size();
		for (int i = l - 1; i >= 0; i--)
			if (sx[i] == sy[i]) s += '0';
			else s += '1';
		s = sx.substr(0, sx.size() - l) + s;
	} else {
		l = sx.size();
		for (int i = l - 1; i >= 0; i--)
			if (sx[i] == sy[i]) s += '0';
			else s += '1';
		s = sy.substr(0, sy.size() - l) + s;
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		sum += s[i] * mul;
		mul *= 2;
	}
	return sum;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			cnt++;
			m = 0;
		}
		else {
			m = xbor(m, a[i]);
			if (m == k) {
				cnt++;
				m = 0;
			}	
		}
	}
	cout << cnt;
	return 0;	 
}
