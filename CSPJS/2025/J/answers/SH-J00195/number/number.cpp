#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

string s;
vector<int> num;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char c : s) {
		if (c >= '0' and c <= '9') {
			num.push_back(c - '0');
		}
	}
	sort(num.begin(), num.end(), greater<int>());
	if (x[0] == 0) {
		cout << 0;
	} else {
		for (auto x : num) {
			cout << x;
		}
	}
	return 0;
}
