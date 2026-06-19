#include <bits/stdc++.h>
using namespace std;

int n, m, ansh, ansl, f, k;
int a[105];

bool cmp(int a, int b) {
	return a > b;
}

void dfs(int i, int x, int y, bool ok, int updown) {
	if (i == k) {
		cout << y << " " << x;
		return;
	}
	if (x == n && ok) dfs(i + 1, x - 1, y, false, 0);
	else if (x == n && !ok) dfs(i + 1, x, y + 1, true, 0);
	else if (x == 1 && ok) dfs(i + 1, x + 1, y, false, 1);
	else if (x == 1 && !ok) dfs(i + 1, x, y + 1, true, 1);
	else if (updown) dfs(i + 1, x + 1, y, false, 1);
	else if (!updown) dfs(i + 1, x - 1, y, false, 0);
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	f = a[1];
	sort(a + 1, a + n * m + 1, cmp);
//	for (int i = 1; i <= n * m; i++) {
//		cout << a[i] << " ";
//	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == f) {
			k = i;
			break;
		}
	}
	dfs(1, 1, 1, false, 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

