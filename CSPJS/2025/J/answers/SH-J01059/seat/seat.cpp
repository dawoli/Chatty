#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
	return a > b; 
} 

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, arr[105];
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
	{
		cin >> arr[i];
	}
	int t = arr[1];
	sort(arr + 1, arr + n * m + 1, cmp);
	int p;
	for (int j = 1; j <= n * m; ++j)
	{
		if (arr[j] == t)
		{
			p = j;
			break;
		}
	}
	int c, r;
	if (p <= n)
	{
		c = 1;
		r = p;
	}
	else
	{
		c = p / n + 1;
		if ((c - 1) * n == p) c--;
		if (c % 2 == 0)
		{
			r = n - ((p - 1) % n);
		}
		else
		{
			r = p % n;
			if (r == 0) r = n;
		}
	}
	cout << c << " " << r;
	return 0;
}
