#include <bits/stdc++.h>
using namespace std;
int a[105];
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,s;
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	s = a[1];
	for (int i = 1;i <= n * m;i++)
	{
		for (int j = i + 1;j <= n * m;j++)
		{
			if (a[i] < a[j])
			{
				int b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
	}
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == s)
		{
			s = i;
		}
	}
	if (s % n == 0) 
	{
		c = s / n;
	}
	else
	{
		c = s / n + 1;
	}
	if (c % 2 == 1)
	{
		if (s % n == 0)
		{
			r = n;
		}
		else
		{
			r = s % n; 
		}
	}
	else
	{
		if (s % n == 0)
		{
			r = 1;
		}
		else
		{
			r = n - s % n + 1;
		}
	}
	cout << c << " " << r;
	return 0;
}
