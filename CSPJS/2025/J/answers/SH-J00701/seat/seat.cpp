#include <bits/stdc++.h>
using namespace std;

int a[10010];
//230138

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int N = n * m;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + N + 1, cmp);
	for (int i = 1; i <= N; i++)
	{
		if (a[i] == r)
		{
			r = i;
			break;
		}
	}
	int x = r / n + 1, y = 0;
	if (x % 2 == 0)
	{
		if (r % n == 0)
		{
			y = n;
			x--;
		}
		else y = (n + 1) - (r % n);
	}
	else if (x % 2 == 1)
	{
		if (r % n == 0)
		{
			y = 1;
			x--;
		}
		else y = (r % n);
	}
	cout << x << " " << y << endl;
	return 0;
}

