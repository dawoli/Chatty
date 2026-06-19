#include <bits/stdc++.h>
using namespace std;
bool a[100][100];
int main(){
	ios::sync_with_stdio(false);
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	memset(a, false, sizeof(a));
	int n;
	cin >> n;
	for (int k = 1; k <= n; k++){
		char x, y;
		cin >> x >> y;
		int i, j;
		if (x == 'D') i = 1;
		if (x == 'C') i = 2;
		if (x == 'H') i = 3;
		if (x == 'S') i = 4;
		if (y == 'A') j = 1;
		if (y >= '2' && y <= '9') j = int(y) - int('0');
		if (y == 'T') j = 10;
		if (y == 'J') j = 11;
		if (y == 'Q') j = 12;
		if (y == 'K') j = 13;
		a[i][j] = true;
	}
	int cnt = 0;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
			if (a[i][j] == true)
				cnt++;
	int ans = 52 - cnt;
	cout << ans << endl;
	return 0;
}
