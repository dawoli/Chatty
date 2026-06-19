#include <bits/stdc++.h>
using namespace std;
string s;
vector<char> v;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if (c - '0' >= 0 && c - '0' <= 26) {
			v.push_back(c);
		}
	}
	sort(v.begin(), v.end());
	for (auto it = v.end() - 1; it >= v.begin(); --it) cout << *it;
	return 0;
} 
