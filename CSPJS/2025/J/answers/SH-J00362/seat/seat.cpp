#include <iostream>
using namespace std;

int n, m, a[102], c, s, p = 1;

int main()
{
freopen("seat.in", "r", stdin);
freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n * m; i++)
	{
		cin >> a[i];
		if (a[i] > a[1])
		{
			p++;
		}
	}
	c = p / n, s = p % n;
	if (s == 0)
	{
		if (c % 2 == 1)
		{
			cout << c << ' ' << n;
		}
		else
		{
			cout << c << ' ' << 1;
		}
	}
	else
	{
		if ((c + 1) % 2 == 1)
		{
			cout << c + 1 << ' ' << s;
		}
		else
		{
			cout << c + 1 << ' ' << n - s + 1;
		}
	}
fclose(stdin);
fclose(stdout);
	return 0;
}
