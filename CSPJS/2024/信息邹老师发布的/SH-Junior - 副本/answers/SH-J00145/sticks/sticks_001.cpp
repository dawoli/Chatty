#include <bits/stdc++.h>
using namespace std;

int t, n;

inline void solve() {
	scanf("%d", &n);
	int m = n / 7;
	if (!m) {
		if (n == 1)
			printf("-1\n");
		else if (n == 2)
			printf("1\n");
		else if (n == 3)
			printf("7\n");
		else if (n == 4)
			printf("4\n");
		else if (n == 5)
			printf("2\n");
		else if (n == 6)
			printf("6\n");
		else
			printf("8\n");
		return;
	}
	n %= 7;//10=6+4=5+5
	if (n == 1 || n == 4 || n == 3) {
		if (n == 1)
			printf("27");
		else if (n == 4)
			printf("20");
		else if (n == 3)
			printf("23");
		for (int i = 1; i < m; i++)
			printf("8");
	} else {
		 if (n == 2)
			printf("1");
		else if (n == 5)
			printf("2");
		else if (n == 6)
			printf("6");
		for (int i = 1; i <= m; i++)
			printf("8");
	}
	printf("\n");
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d", &t);
	for ( ; t--; ) {
		solve();
	}
	return 0;
}
