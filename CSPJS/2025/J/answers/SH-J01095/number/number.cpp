#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int> v;
	for (auto c : s) {
		if (isdigit(c)) {
			v.push_back(c - '0');
		}
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << "\n";

	return 0;
}
