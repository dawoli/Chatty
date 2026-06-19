#include <bits/stdc++.h>
using namespace std;

int n, m, x, num, ans, xn, xm;
int a[105];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
		if(i == 1) x = a[i];
	}
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= n * m; i++) {
		if(a[i] == x) {
			num = i;
			break;
		}
	}
	if(num % n == 0) xm = num / n;
	else xm = num / n + 1;
	if(xm % 2 == 1) {
		if(num % n == 0) xn = n;
		else xn = num % n;
	}
	else {
		if(num % n == 0) xn = 1;
		else xn = n - (num % n) + 1;
	}
	printf("%d %d", xm, xn);
	return 0;
}

