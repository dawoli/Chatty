#include <bits/stdc++.h>
using namespace std;

int pokers[14][4];
char colours[4] = {'D', 'C', 'H', 'S'};

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	int n;
	cin >> n;
	
	string s;
	int num, color;
	for (int i = 0; i < n; i++) {
		cin >> s;
		
		if (s[1] == 'A') {
			num = 1;
		}
		else if (s[1] == 'T') {
			num = 10;
		}
		else if (s[1] == 'J') {
			num = 11;
		}
		else if (s[1] == 'Q') {
			num = 12;
		}
		else if (s[1] == 'K') {
			num = 13;
		}
		else {
			num = s[1] - '0';
		}
		
		for (int i = 0; i < 4; i++) {
			if (s[0] == colours[i]) {
				color = i;
			}
		}
		
		pokers[num][color] = 1;
	}
	
	int count = 0;
	for (int i = 1; i <= 13; i++) {
		for (int j = 0; j < 4; j++) {
			if (pokers[i][j] == 0) {
				count++;
			}
		}
	}
	
	cout << count;
	return 0;
}
