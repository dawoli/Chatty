#include <bits/stdc++.h>

using namespace std;

const int N = 111;
int n, m, a[N], x, l;

bool cmp(const int &x, const int &y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	l = n * m - 1;
	scanf("%d", &x);
	for (int i = 1; i <= l; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + l + 1, cmp);
	for (int i = 1, r = 1, c = 1; i <= l; i++) {
		if (x > a[i]) {
			printf("%d %d\n", r, c);
			return 0;
		}
		if (c == n && (r & 1) || c == 1 && (r ^ 1))
			++r;
		else if (r & 1)
			++c;
		else
			--c;
	}
	printf("%d %d\n", m, n);
	return 0;
}
