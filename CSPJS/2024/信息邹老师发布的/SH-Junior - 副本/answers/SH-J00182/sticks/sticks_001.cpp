# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, n;

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%lld", &T);
	while (T--)
	{
		scanf("%lld", &n);
		if (n % 7 == 0)
		{
			for (int i = n / 7; i >= 1; i--) putchar('8');
			putchar('\n');
			continue;
		}
		if (n == 1)
		{
			puts("-1");
			continue;
		}
		if (n % 7 == 1)
		{
			printf("10");
			for (int i = 1; i < n / 7; i++) putchar('8');
			putchar('\n');
			continue;
		}
		if (n % 7 == 2)
		{
			putchar('1');
			for (int i = 1; i <= n / 7; i++) putchar('8');
			putchar('\n');
			continue;
		}
		if (n % 7 == 3)
		{
			if (n == 3)
			{
				puts("7");
				continue;
			}
			printf("22");
			for (int i = 1; i < n / 7; i++) putchar('8');
			putchar('\n');
			continue;
		}
		if (n % 7 == 4)
		{
			if (n == 4)
			{
				puts("4");
				continue;
			}
			printf("20");
			for (int i = 1; i < n / 7; i++) putchar('8');
			putchar('\n');
			continue;
		}
		if (n % 7 == 5)
		{
			putchar('2');
			for (int i = 1; i <= n / 7; i++) putchar('8');
			putchar('\n');
			continue;
		}
		if (n % 7 == 6)
		{
			putchar('6');
			for (int i = 1; i <= n / 7; i++) putchar('8');
			putchar('\n');
			continue;
		}
	}
	return 0;
}
/*
1  -1
8  10
15 108

2  1
9  18
16 188

3  7
10 22
17 228

4  4
11 20
18 208

5  2
12 28
19 288

6  6
13 68 
20 688
*/
