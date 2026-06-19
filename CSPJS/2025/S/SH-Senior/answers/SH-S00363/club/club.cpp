#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];

bool cmp(int x, int y) {
	return x > y; 
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int x, y;
			scanf("%d%d%d", &a[i], &x, &y);
		}
		sort(a+1, a+n+1, cmp);
		int sum = 0;
		for (int i = 1; i <= n/2; i++) {
			sum += a[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}
