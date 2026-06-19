#include <iostream>
#include <algorithm>

int n, m;
int a[110];

int cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
		std::cin >> a[i];
	int sr = a[1];
	std::sort(a + 1, a + n * m + 1, cmp);
	int idx = 1;
	for (int i = 1; i <= n * m; ++i)
	{
		if (a[i] == sr)
		{
			idx = i;
			break;
		}
	}
	int col = (idx - 1) / n + 1;
	int rol;
	if (col % 2 == 0)
		rol = n - (idx - 1) % n;
	else
		rol = (idx - 1) % n + 1;
	std::cout << col << ' ' << rol;
	return 0;
}

