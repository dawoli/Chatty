#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
int a[200];
int num;
int c, r;

bool CMP(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	num = a[1];
	sort(a + 1, a + n * m + 1, CMP);
	for (int i = 1; i <= n * m; i++) 
		if (num == a[i]) {
			num = i - 1;
			break;
		}
	c = num / n + 1;
	if (c % 2 == 0) r = n - num % n; 
	else r = num % n + 1;
	cout << c << ' ' << r << endl;
	return 0;
}
