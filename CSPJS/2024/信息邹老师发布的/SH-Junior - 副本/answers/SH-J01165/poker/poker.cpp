#include<bits/stdc++.h>
using namespace std;

string c;
int n;
set<string> s;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "r", stdout);
	cin >> n;
	while(n--) {
		cin >> c;
		s.insert(c);
	}
	cout << 52 - s.size() << '\n';
	return 0;
}
