#include <bits/stdc++.h>
using namespace std;
int d[35] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888, 1088, 1888, 2008, 2088, 2888, 6888};
int t, n;
int main ()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n <= 10)
		{
			cout << d[n] << endl;
		}
		else
		{
			if (n % 7 == 0)
			{
				while (n)
				{
					n -= 7;
					putchar('8');
				}
			}
			else if (n % 7 == 1)
			{
				cout << "10";
				n -= 8;
				while (n)
				{
					n -= 7;
					putchar('8');
				}
			}
			else if (n % 7 == 2)
			{
				cout << "1";
				n -= 2;
				while (n)
				{
					n -= 7;
					putchar('8');
				}
			}
			else if (n % 7 == 3)
			{
				cout << "200";
				n -= 17;
				while (n)
				{
					n -= 7;
					putchar('8');
				}
			}
			else if (n % 7 == 4)
			{
				cout << "20";
				n -= 11;
				while (n)
				{
					n -= 7;
					putchar('8');
				}
			}
			else if (n % 7 == 5)
			{
				cout << "2";
				n -= 5;
				while (n)
				{
					n -= 7;
					putchar('8');
				}
			}
			else if (n % 7 == 6)
			{
				putchar('6');
				n -= 6;
				while (n)
				{
					n -= 7;
					putchar('8');
				}
			}
			cout << endl;
		}
	}
}
/*#include <bits/stdc++.h>
using namespace std;
long long n, ans, d[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long dfs(long long x, int m)
{
	if (m == 0)
	{
		return x;
	}
	else if (m == 1)
	{
		return 1e18;
	}
	long long ans = 1e18;
	for (int i = 0; i <= 9; i++)
	{
		if (m >= d[i])
		{
			ans = min(ans, dfs(x * 10 + i, m - d[i]));
		}
	}
	return ans;
}
int main()
{
	for (int n = 1; n <= 27; n++)
	{
		ans = 1e18;
		for (int i = 1; i <= 9; i++)
			if (n >= d[i])
				ans = min(ans, dfs(i, n - d[i]));
		if (ans == 1e18)
			cout << "-1, ";
		else
			cout << ans << ", ";
	}
}*/
