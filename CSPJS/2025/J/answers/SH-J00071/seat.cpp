#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res;
}

const int N = 105;
int n, m, a[N];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n * m; ++i) a[i] = read();
	int cnt = 0;
	for (int i = 1; i <= n * m; ++i)
		if (a[i] >= a[1]) ++cnt;
	int c = (cnt - 1) / n + 1;
	int r = (cnt - 1) % n + 1;
	if (!(c & 1)) r = n - r + 1;
	cout << c << " " << r << endl;
	return 0;
}