#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	vector<int> tab(10);
	for(char c : s) {
		if('0' <= c && c <= '9') {
			tab[c - '0']++;
		}
	}
	for(int i = 9; i >= 0; i--) {
		while(tab[i]--) {
			cout << i;
		}
	}
	cout << '\n';
	return 0;
}
