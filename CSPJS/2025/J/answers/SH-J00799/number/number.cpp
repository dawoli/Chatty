#include <bits/stdc++.h> 
using namespace std;

string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j <= s.size(); j++) {
			if (s[j] == (char)(i + '0')) cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
