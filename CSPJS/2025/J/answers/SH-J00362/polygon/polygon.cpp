#include <iostream>
using namespace std;

int n, a[5002], ans;
int main()
{
freopen("polygon.in", "r", stdin);
freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (n == 3)
	{
		if (a[1] + a[2] + a[3] > 2 * max(max(a[1], a[2]), a[3]))
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	for (int i = 3; i <= n; i++)
	{
		int f = 1, s = 1;
		for (int j = n; j >= n - i + 1; j--)
		{
			f *= i;
		}
		for (int j = s; j >= 3; j--)
		{
			s *= j;
		}
		ans += f / s;
	}
	cout << ans;
fclose(stdin);
fclose(stdout);
	return 0;
}
