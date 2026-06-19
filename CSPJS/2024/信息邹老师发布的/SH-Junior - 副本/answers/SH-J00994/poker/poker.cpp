#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
set<string> s;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(ll i = 1; i <= n; i++) {
		string t;
		cin >> t;
		s.insert(t);
	}
	cout << 52-s.size() << endl;
	return 0;
}

