#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)
	{
		cin >> a[i];
	}
	int f = a[1], p;
	sort(a+1, a+n*m+1);
	for(int i = n*m; i>=1; i--)
	{
		if(a[i] == f)
		{
			p = n*m-i+1;
			break;
		}
	}
	int y, x;
	if(p % m == 0)
	{
		y = p/m;
		if(y % 2 == 0)
		{
			x = 1;
		}
		else
			x = n;
	}
	else
	{
		y = p/m+1;
		int q = p%m;
		if(y % 2 == 0)
		{
			x = n-q+1;
		}
		else
			x = q;
	}
	cout << y << " " << x;
	return 0;
}
