#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
struct Node { int s, id; } a[105];
bool operator <(Node x, Node y) {
	return x.s > y.s;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n*m; i++) scanf("%d", &a[i].s), a[i].id = i;
	sort(a+1, a+n*m+1);
	int f = 1, x = 0, y = 1;
	for (int i = 1; i <= n*m; i++) {
		x += f;
		if (a[i].id == 1) {
			printf("%d %d\n", y, x);
			return 0;
		}
		if (i % n == 0) {
			y++;
			f = -f;
			x -= f;
		}
	}
	return 0;
}