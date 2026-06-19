#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1, c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, biao[40] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888, 1088, 1888, 2008, 2088, 2888, 6888, 8888, 10888, 18888, 20088, 20888, 28888, 68888, 88888, 108888, 188888, 200888, 208888};
//                     1  2  3  4  5  6  7  8   9   10  11  12  13  14  15   16   17   18   19   20   21   22
void solve()
{
	scanf("%d", &n);
	if (n <= 38) {
		printf("%d\n", biao[n]);
		return ;
	}
	if (n < 7) {
		if (n == 2) puts("1");
		else if (n == 3) puts("7");
		else if (n == 4) puts("4");
		else if (n == 5) puts("2");
		else if (n == 6) puts("6");
		return ;
	}
	if (n % 7 == 0) { // DONE
		for (int i = 0; i < n / 7; ++i) putchar('8');
	}
	else if (n % 7 == 1) { // DONE
		n -= 1;
		printf("1");
		for (int i = 0; i < n / 7; ++i) putchar('8');
	}
	else if (n % 7 == 2) {
		n -= 2;
		printf("1");
		for (int i = 0; i < n / 7; ++i) putchar('8');
	}
	else if (n % 7 == 3) { // DONE
		n -= 17;
		printf("200");
		for (int i = 0; i < n / 7; ++i) putchar('8');
	}
	else if (n % 7 == 4) { // DONE
		n -= 11;
		printf("20");
		for (int i = 0; i < n / 7; ++i) putchar('8');
	}
	else if (n % 7 == 5) { // DONE
		n -= 17;
		printf("200");
		for (int i = 0; i < n / 7; ++i) putchar('8');
	}
	else if (n % 7 == 6) { // DONE
		n -= 6;
		printf("6");
		for (int i = 0; i < n / 7; ++i) putchar('8');
	}
	printf("\n");
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}

