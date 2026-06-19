#include <bits/stdc++.h>
using namespace std;
string tot = "";
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (char c : s)
		if (c >= '0' && c <= '9') tot += c;
	sort(tot.begin(), tot.end());
	for (int i = tot.size() - 1; i >= 0; i--)
		cout << tot[i];
	return 0;
}
