#include <iostream>
#include <algorithm>
using namespace std;
int n, m, mb, cur, a[100001];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	mb = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= m; j++)
			{
				++cur;
				if (a[cur] == mb)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
		else
		{
			for (int j = m; j >= 1; j--)
			{
				++cur;
				if (a[cur] == mb)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
神秘模拟？期望 AC 
*/
