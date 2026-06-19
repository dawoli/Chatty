#include<iostream>
#include<cstring>
using namespace std;

int num[10];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < num[i]; j++) {
			cout << i;
		}
	}
	
	return 0;
}  
