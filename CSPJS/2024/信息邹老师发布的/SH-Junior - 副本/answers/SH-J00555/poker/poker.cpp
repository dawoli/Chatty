#include <bits/stdc++.h>

using namespace std;

set<string> card;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "r", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string c;
		cin >> c;
		card.insert(c);
	}
	
	cout << 52 - card.size();
}
