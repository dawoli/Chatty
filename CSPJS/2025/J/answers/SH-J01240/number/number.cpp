#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
string s;
int cnt[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] >= '0' && s[i] <= '9')
			cnt[s[i] - '0'] ++;		
	}
	for (int i = 9; i >= 0; i --)
		for (int j = 1; j <= cnt[i]; j ++)
			cout << i;
	return 0;
}
