#include <bits/stdc++.h>
using namespace std;

int poker[52];

int calculate_a(char n)
{
	if (n == 'A')
		return 0;
	else if (n == 'T')
		return 9;
	else if (n == 'J')
		return 10;
	else if (n == 'Q')
		return 11;
	else if (n == 'K')
		return 12;
	else
		return n-49;
}

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n, num=0, ans=0;
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		string a;
		cin >> a;
		if (a[0] == 'D')
		{
			num += calculate_a(a[1]);
		}
		else if (a[0] == 'C')
		{
			num += 13;
			num += calculate_a(a[1]);
		}
		else if (a[0] == 'H')
		{
			num += 26;
			num += calculate_a(a[1]);
		}
		else if (a[0] == 'S')
		{
			num += 39;
			num += calculate_a(a[1]);
		}
		poker[num] = 1;
		num = 0;
	}
	for (int i=1; i<=52; i++)
	{
		if (poker[i-1] == 0)
			ans += 1;
	}
	cout << ans;
	return 0;
}
