#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x, y;

struct node
{
	int id, s;
}a[100005];

bool cmp(node x, node y)
{
	return x.s > y.s;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i].s;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i].id == 1)
		{
			if (i % n == 0)
			{
				x = i / n;
				y = n;
				if (x % 2 == 0)
				{
					y = 1;
				}
			}
			else
			{
				x = i / n + 1;
				y = i % n;
				if (x % 2 == 0)
				{
					y = n - y + 1;
				}
			}
			break;
		}
	}
	cout << x << " " << y << endl;
	return 0;
}
