#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int score = a[1];
	sort(a + 1, a + n * m + 1);
	reverse(a + 1, a + n * m + 1);
	int pos = -1;
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == score)
		{
			pos = i;
			break;
		}
	}
	int col, row;
	if (pos % n == 0)
		col = pos / n;
	else
		col = pos / n + 1;
	if (col % 2 == 1)
	{
		row = pos % n;
		if (pos % n == 0)
			row += n;
	}
	else
	{
		row = n - pos % n + 1;
		if (pos % n == 0)
			row -= n;
	}
	cout << col << " " << row;
	return 0;
}
