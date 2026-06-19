#include<bits/stdc++.h>
using namespace std;
int a[105], ans[15][15];
int f[5] = {0, 1, 2, 3, 2};
int cmd(int a, int b) {
	if(a > b) return true;
	return false;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int x, y;
	int ax = 1, ay = 1, aax, aay, m;
	cin >> x >> y;
	for(int i = 1; i <= x * y; i++) {
		cin >> a[i];
	}
	m = a[1];
	sort(a + 1, a + x * y + 1, cmd);
	int k = f[1];
	for(int i = 1; i <= x * y; i++) {
		ans[ax][ay] = a[i];
		aax = ax;
		aay = ay;
		if(k == 1) {
			aax++;
		} else if(k == 2) {
			aay++;
		} else {
			aax--;
		}
		if(aax > y - 1) k++;
		else if(aax < 2) k--;
		else if(aay % 2 == 0 and k == 2) k++;
		ax = aax;
		ay = aay;
	}
	for(int i = 1; i <= x; i++) {
		for(int j = 1; j <= y; j++) {
			if(ans[i][j] == m) {
				cout << j << " " << i;
				break;
			}
		}
	}
	return 0;
}
