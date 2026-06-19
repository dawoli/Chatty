#include <bits/stdc++.h>

using namespace std;

bool a[4][13];

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	while (n--){
		string s;
		cin >> s;
		
		char x = s[0], y = s[1];
		if (x == 'D') {
			if (y == 'A') {
				a[0][0] = true;
			} else if (y == 'T') {
				a[0][9] = true;
			} else if (y == 'J') {
				a[0][10] = true;
			} else if (y == 'Q') {
				a[0][11] = true;
			} else if (y == 'K') {
				a[0][12] = true;
			} else {
				a[0][y-'0'-1] = true;
			}
		} else if (x == 'C') {
			if (y == 'A') {
				a[1][0] = true;
			} else if (y == 'T') {
				a[1][9] = true;
			} else if (y == 'J') {
				a[1][10] = true;
			} else if (y == 'Q') {
				a[1][11] = true;
			} else if (y == 'K') {
				a[1][12] = true;
			} else {
				a[1][y-'0'-1] = true;
			}
		} else if (x == 'H') {
			if (y == 'A') {
				a[2][0] = true;
			} else if (y == 'T') {
				a[2][9] = true;
			} else if (y == 'J') {
				a[2][10] = true;
			} else if (y == 'Q') {
				a[2][11] = true;
			} else if (y == 'K') {
				a[2][12] = true;
			} else {
				a[2][y-'0'-1] = true;
			}
		} else if (x == 'S') {
			if (y == 'A') {
				a[3][0] = true;
			} else if (y == 'T') {
				a[3][9] = true;
			} else if (y == 'J') {
				a[3][10] = true;
			} else if (y == 'Q') {
				a[3][11] = true;
			} else if (y == 'K') {
				a[3][12] = true;
			} else {
				a[3][y-'0'-1] = true;
			}
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (!a[i][j]) {
				cnt++;
			}
		}
	}
	
	printf("%d\n", cnt);
	
	return 0;
}

