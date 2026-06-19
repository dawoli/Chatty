#include <bits/stdc++.h>
using namespace std;
const int val[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;
int work(int x)
{
	int ret = 0;
	do {
		ret += val[x % 10];
		x /= 10;
	} while (x);
	return ret;
}
void solveBF()
{
	if (n == 1)
	{
		puts("-1");
		return;
	}
	for (int i = 1; 1; ++i)
		if (work(i) == n)
		{
			printf("%d\n", i);
			return;
		}
}
void solve()
{
	int k = n / 7,r = n % 7;
	if (r == 0) {for (int i = 1; i <= k; ++i) printf("8"); puts("");}
	else if (r == 1)
	{
		if (n == 1) puts("-1");
		else {printf("10"); for (int i = 1; i <= k - 1; ++i) printf("8"); puts("");}
	}
	else if (r == 2) {printf("1"); for (int i = 1; i <= k; ++i) printf("8"); puts("");}
	else if (r == 3)
	{
		if (n == 3) puts("7");
		else if (n == 10) puts("22");
		else {printf("200"); for (int i = 1; i <= k - 2; ++i) printf("8"); puts("");}
	}
	else if (r == 4)
	{
		if (n == 4) puts("4");
		else {printf("20"); for (int i = 1; i <= k - 1; ++i) printf("8"); puts("");}
	}
	else if (r == 5) {printf("2"); for (int i = 1; i <= k; ++i) printf("8"); puts("");}
	else {printf("6"); for (int i = 1; i <= k; ++i) printf("8"); puts("");}
}
void mian()
{
	scanf("%d", &n);
	if (n <= 50)
		solveBF();
	else
		solve();
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) mian();
	return 0;
}