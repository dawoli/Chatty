#include <iostream>

using namespace std;

int jud(char a) {
	if (a == 'D') return 1;
	else if (a == 'C') return 2;
	else if (a == 'H') return 3;
	else return 4;
}

int jud1(char a) {
	if (a == 'A') return 1;
	else if (a == 'T') return 10;
	else if (a == 'J') return 11;
	else if (a == 'Q') return 12;
	else if (a == 'K') return 13;
	return (a - '0');
}

int n, bkt[5][20];
string a[60];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int m = jud(a[i][0]);
		int n = jud1(a[i][1]);
		bkt[m][n]++;
		// cout << m << " " << n << "\n";
	}

	int cnt = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {
			if (bkt[i][j]) {
				cnt++;
				// cout << i << " " << j << " " << bkt[i][j] << "\n";
			}
		}
	}

	cout << 52 - cnt << "\n";

	return 0;
}
