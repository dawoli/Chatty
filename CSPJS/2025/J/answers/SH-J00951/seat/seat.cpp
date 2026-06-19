#include <bits/stdc++.h>
using namespace std;

int n, m, a[110], k, dos, l, h;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	k = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) 
		if (a[i] == k) {
			dos = i;
			break;
		}
	l = (dos - 1) / n + 1;
	k = dos % n;
	if (k == 0) k = n;
	if (l % 2) h = k;
	else h = n - k + 1;
	cout << l << ' ' << h;
	return 0; 
}
