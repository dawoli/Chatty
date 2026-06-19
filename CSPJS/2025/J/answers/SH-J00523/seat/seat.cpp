#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int R = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int s;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == R) {
			s = i;
		}
	}
	int c = (s + n - 1) / n;
	int r = s - (c - 1) * n;
	if (c % 2 == 0) {
		r = n - r + 1;
	}
	cout << c << " " << r;
	return 0;
}
