#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int p = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= m; j++)
			{
				cnt++;
				if (a[cnt] == p)
				{
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
		else if (i % 2 == 0)
		{
			for (int j = m; j >= 1; j--)
			{
				cnt++;
				if (a[cnt] == p)
				{
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
} 
