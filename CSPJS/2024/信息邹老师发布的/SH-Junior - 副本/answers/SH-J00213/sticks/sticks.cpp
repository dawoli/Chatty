#include <bits/stdc++.h>
using namespace std;
const int h[100] = { 0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888, 1088, 1888, 2008, 2088, 2888, 6888, 8888, 10888, 18888, 20088, 20888, 28888, 68888, 88888, 108888, 188888, 200888, 208888, 288888, 688888, 888888, 1088888, 1888888, 2008888, 2088888, 2888888, 6888888, 8888888, 10888888, 18888888, 20088888, 20888888, 28888888, 68888888, 88888888 };

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		if (n <= 50) {
			printf("%d\n", h[n]);
		} else if (n % 7 == 0) {
			for (int i = 0; i < n / 7; ++i) printf("8");
			printf("\n");
		} else if (n % 7 == 1) {
			printf("10");
			for (int i = 0; i < n / 7 - 1; ++i) printf("8");
			printf("\n");
		} else if (n % 7 == 2) {
			printf("1");
			for (int i = 0; i < n / 7; ++i) printf("8");
			printf("\n");
		} else if (n % 7 == 3) {
			printf("200");
			for (int i = 0; i < n / 7 - 2; ++i) printf("8");
			printf("\n");
		} else if (n % 7 == 4) {
			printf("20");
			for (int i = 0; i < n / 7 - 1; ++i) printf("8");
			printf("\n");
		} else if (n % 7 == 5) {
			printf("2");
			for (int i = 0; i < n / 7; ++i) printf("8");
			printf("\n");
		}  else if (n % 7 == 6) {
			printf("6");
			for (int i = 0; i < n / 7; ++i) printf("8");
			printf("\n");
		}
	}
	return 0;
}
