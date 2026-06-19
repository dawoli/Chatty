#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll n; scanf("%lld", &n);
	if (n % 7 == 0)
	{
		for (ll i = 1; i <= n / 7; i++) printf("8");
		printf("\n");
	}
	else if (n % 7 == 1)
	{
		if (n == 1) puts("-1");
		else
		{
			printf("10");
			for (ll i = 1; i <= (n - 8) / 7; i++) printf("8");
			printf("\n");
		}
	}
	else if (n % 7 == 2)
	{
		printf("1");
		for (ll i = 1; i <= (n - 2) / 7; i++) printf("8");
		printf("\n");
	}
	else if (n % 7 == 3)
	{
		if (n == 3) puts("7");
		else
		{
			printf("22");
			for (ll i = 1; i <= (n - 10) / 7; i++) printf("8");
			printf("\n");
		}
	}
	else if (n % 7 == 4)
	{
		if (n == 4) puts("4");
		else
		{
			printf("20");
			for (ll i = 1; i <= (n - 11) / 7; i++) printf("8");
			printf("\n");
		}
	}
	else if (n % 7 == 5)
	{
		printf("2");
		for (ll i = 1; i <= (n - 5) / 7; i++) printf("8");
		printf("\n");
	}
	else
	{
		printf("6");
		for (ll i = 1; i <= (n - 6) / 7; i++) printf("8");
		printf("\n");
	}
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	ll T; scanf("%lld", &T);
	while (T--) solve();
	return 0;
}
