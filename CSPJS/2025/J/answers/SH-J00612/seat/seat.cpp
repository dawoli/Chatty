#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, tmp;
int a[1003];
bool f, fy;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) 
		scanf("%d", &a[i]);
	tmp = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1;
	for (int k = 1; k <= n * m; k++) {
		if (tmp == a[k]) {
			cout << y << " " << x;
			return 0;
		}
		if (f == 0) {
			if (x == n) {
				y++;
				f = 1;
				continue;
			}
			x++;
		}
		else {
			if (x == 1) {
				y++;
				f = 0;
				continue;
			}
			x--;
		}
	}
	return 0;
}
