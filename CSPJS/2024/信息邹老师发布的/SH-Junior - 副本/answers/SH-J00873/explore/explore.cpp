#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool A[1005][1005], B[1005][1005];

int nextX(int x, int d) {
	if (d == 1) x++;
	else if (d == 3) x--;
	return x;
}

int nextY(int y, int d) {
	if (d == 0) y++;
	else if (d == 2) y--;
	return y;
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m, k, x, y, d;
		cin >> n >> m >> k >> x >> y >> d;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char c;
				cin >> c;
				A[i][j] = c == '.';
				B[i][j] = false;
			}
		}
		B[x][y] = true;
		while (k--) {
			int newX = nextX(x, d), newY = nextY(y, d);
			if (1 <= newX && newX <= n && 1 <= newY && newY <= m && A[newX][newY]) {
				x = newX, y = newY;
				B[x][y] = true;
			} else {
				d = (d + 1) % 4;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ans += B[i][j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

