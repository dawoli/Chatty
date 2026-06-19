#include <bits/stdc++.h>
using namespace std;
int n, x, y, cnt;
string p;
bool f[4][13];
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	while (n --) {
		cin >> p;
		if (p[0] == 'D') x = 0;
		else if (p[0] == 'C') x = 1;
		else if (p[0] == 'H') x = 2;
		else if (p[0] == 'S') x = 3;
		if (p[1] == 'A') y = 0;
		else if (p[1] == 'T') y = 9;
		else if (p[1] == 'J') y = 10;
		else if (p[1] == 'Q') y = 11;
		else if (p[1] == 'K') y = 12;
		else y = p[1] - '0' - 1;
		f[x][y] = 1;
	}
	for (int i = 0; i < 4; i ++){
		for (int j = 0; j < 13; j ++){
			if (!f[i][j]) cnt ++;
		}
	}
	cout << cnt;
	return 0;
}

