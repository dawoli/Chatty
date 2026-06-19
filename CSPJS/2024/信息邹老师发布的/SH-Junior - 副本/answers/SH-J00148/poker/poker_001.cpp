#include <iostream>
using namespace std;
int n, ans = 52;
char c1, c2;
bool f[5][20];
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout); 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c1 >> c2;
		int a, b;
		if (c1 == 'D') b = 1;
		if (c1 == 'C') b = 2;
		if (c1 == 'H') b = 3;
		if (c1 == 'S') b = 4;
		if (c2 == 'J') a = 11;
		else if (c2 == 'T') a = 10;
		else if (c2 == 'Q') a = 12;
		else if (c2 == 'K') a = 13;
		else if (c2 == 'A') a = 1;
		else a = c2 - '0';
		f[b][a] = 1;
	}
	for (int i = 1; i <= 4; i++) for (int j = 1; j <= 13; j++) ans -= f[i][j];
	cout << ans << endl;
	return 0;
}
