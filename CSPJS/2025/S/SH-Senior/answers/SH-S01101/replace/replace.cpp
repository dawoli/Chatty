#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

const int P = 28;
ull p[200005];
ull hsh[200005][2];
ull h[2][2000005];
int n, q;
string s[200005][2], t[2];

int init(string s) {
	ull h = 0;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		h = h * P + s[i]-'a'+1;
	}
	return h;
}
ull Hash(int l, int r, int idx) {
	if (l > r) return -1;
	return h[idx][r] - h[idx][l-1] * p[r-l+1];
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = p[i-1] * P;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		hsh[i][0] = init(s[i][0]);
		hsh[i][1] = init(s[i][1]);
	}
	while (q--) {
		cin >> t[0] >> t[1];
		int len = t[0].size();
		if (len != t[1].size()) { cout << "0\n"; continue; }
		t[0] = ' ' + t[0]; t[1] = ' ' + t[1];
		for (int i = 1; i <= len; i++) {
			h[0][i] = h[0][i-1]*P+t[0][i]-'a'+1;
			h[1][i] = h[1][i-1]*P+t[1][i]-'a'+1;
		}
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			int x = s[i][0].size();
			for (int j = 1; j+x-1 <= len; j++) {
				if (Hash(1, j-1, 0) != Hash(1, j-1, 1)) break;
				if (Hash(j, j+x-1, 0) == hsh[i][0] && Hash(j, j+x-1, 1) == hsh[i][1]
				 && Hash(j+x, len, 0) == Hash(j+x, len, 1))
					cnt++;
			}
		}
		cout << cnt << '\n';
	}


	return 0;
}
