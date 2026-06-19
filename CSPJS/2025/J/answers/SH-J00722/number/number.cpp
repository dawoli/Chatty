#include <iostream>
#include <cstdio>
using namespace std;

string s;
long long n[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (n[i] != 0) {
			for (long long j = 0; j < n[i]; j++) {
				cout << i;
			}
		}
	}
	fclose(stdin); 
	fclose(stdout);
	return 0;
} 
