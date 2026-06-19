#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
int w[4][14];
char f[2];
int h, j;
int main(){
	freopen("poker.in", "w", stdin);
	freopen("poker.out", "r", stdout);
	for (int i = 0; i <= 3; i ++)
		for (int j = 0; j <= 13; j ++)
		    w[i][j] == 0;
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> f;
		if (f[0] == "D") h = 0;
		if (f[0] == "C") h = 1;
		if (f[0] == "H") h = 2;
		if (f[0] == "S") h = 3;
		if (f[1] == "T") j = 10;
	    if (f[1] == "J") j = 11;
		if (f[1] == "Q") j = 12;
		if (f[1] == "K") j = 13;
        if (f[1] == "A") j = 1;
        if (f[1] == "2") j = 2;
        if (f[1] == "3") j = 3;
        if (f[1] == "4") j = 4;
        if (f[1] == "5") j = 5;
        if (f[1] == "6") j = 6;
        if (f[1] == "7") j = 7;
        if (f[1] == "8") j = 8;
        if (f[1] == "9") j = 9;
		if (w[h][j] == 0) w[h][j] ++;
		else ans ++;
	}
	if (n < 52) ans += 52 - n;
	cout << ans;
	return 0;
}
