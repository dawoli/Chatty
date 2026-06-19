#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[101];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
	{
		cin >> a[i];
	}
	int num = a[1];
	sort(a + 1, a + n * m + 1);
	int x = lower_bound(a + 1, a + n * m + 1, num) - a;
	x = n * m - x + 1;
	int c = (n + x - 1) / n;
	cout << c << " ";
	if (c % 2 == 1)
	{
		if (x % n == 0)
		{
			cout << n; 
		}
		else
		{
			cout << x % n;
		}
	}
	else
	{
		if (x % n == 0)
		{
			cout << 1; 
		}
		else
		{
			cout << n - x % n + 1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
