#include <iostream>
#include <algorithm>

int n, m;
int a[105];
int b[15][15];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		std::cin >> a[i];
	int c = a[1];
	std::sort(a + 1, a + n * m + 1, cmp);
	bool flag = 1;
	int k = 1, j;
	for (int i = 1; i <= m; i++) {
		if (flag) {
			flag = 0; 
			for (j = 1; j <= n; j++)
				b[i][j] = a[k], k++;
		} else {
			flag = 1;
			for (j = n; j >= 1; j--)
				b[i][j] = a[k], k++;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (c == b[i][j]) {
				std::cout << i << ' ' << j;
				return 0;
			}
}
