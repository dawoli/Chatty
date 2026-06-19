#include<bits/stdc++.h>
using namespace std;
set<string> s;
int n;
string ipt;
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ipt;
		s.insert(ipt);
	}
	cout << 52 - s.size();
	return 0;
}
