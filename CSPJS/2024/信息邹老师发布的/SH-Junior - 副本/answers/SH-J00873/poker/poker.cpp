#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string S1 = "DCHS", S2 = "A23456789TJQK";

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	set<string> S;
	string s = "";
	for (auto i : S1) {
		for (auto j : S2) {
			S.insert(s + i + j);
		}
	}
	int n;
	cin >> n;
	while (n--) {
		string x;
		cin >> x;
		if (S.count(x)) {
			S.erase(x);
		}
	}
	cout << S.size();
	return 0;
}

