#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, x, y, d;
bool a[1005][1005], mp[1005][1005];

bool check(int x, int y) {
	if (x < 0) return false;
	if (x >= n) return false;
	if (y < 0) return false;
	if (y >= m) return false;
	if (mp[x][y]) return false;
	return true;
}

void run() {
	switch (d) {
		case 0:
			if (check(x, y + 1)) y++;
			else d = (d + 1) % 4;
			break;
		case 1:
			if (check(x + 1, y)) x++;
			else d = (d + 1) % 4;
			break;
		case 2:
			if (check(x, y - 1)) y--;
			else d = (d + 1) % 4;
			break;
		case 3:
			if (check(x - 1, y)) x--;
			else d = (d + 1) % 4;
			break;
	}
	a[x][y] = true;
}

int ans() {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(a[i][j]) {
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(a, 0, sizeof(a));
		cin >> n >> m >> k >> x >> y >> d;
		x--, y--;
		a[x][y] = true;
		for (int j = 0; j < n; j++) {
			getchar();
			for (int k = 0; k < m; k++) {
				char c;
				c = getchar();
				mp[j][k] = (c == 'x');
			}
		}
		for (int j = 0; j < k; j++) {
			run();
		}
		cout << ans() << endl;
	}
	return 0;
}
