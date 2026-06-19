#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	map<string, int> mp;
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		mp[str]++;
		if (mp[str] == 1) {
			cnt++;
		}
	}
	cout << 52 - cnt;
	return 0;
}
