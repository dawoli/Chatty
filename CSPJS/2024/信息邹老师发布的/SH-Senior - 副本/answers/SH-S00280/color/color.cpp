#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T, n, A[N];
int pow(int a, int b) {
	int ans = 1;
	for (int i = 1; i <= b; i++) ans *= a;
	return ans;
}
int clr(int i, int n) {
	return n & (1 << (i - 1));
}
void solveBF() {
	int ans = 0;
	for (int i = 0; i < pow(2, n); i++) {
		int lr = 0, lb = 0, sum = 0;
		for (int j = 1; j <= n; j++) {
			if (clr(j, i)) {
				if (A[j] == A[lr]) sum += A[j];
				lr = j;
			} else {
				if (A[j] == A[lb]) sum += A[j];
				lb = j;
			}
		}
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", A + i);
		if (n <= 15) solveBF();
		else solveBF();
	}
	return 0;
}
