#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	cin >>n >>m;
	for (int i = 1; i <= n * m; i++)
		cin >>a[i];
	int W = a[1];
	sort(a + 1, a +n * m +1, greater<int>());
	int x = 1, y = 0;
	for (int i = 1; i <= n * m; i++) {
		if (x % 2 == 1) y++;
		else y--;
		if (y > n) x++, y = n;
		else if (y < 1) x++, y = 1;
		if (a[i] == W) cout << x << " " <<y <<"\n";
	}
	return 0;
}
