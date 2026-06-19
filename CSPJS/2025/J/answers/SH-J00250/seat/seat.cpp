#include <bits/stdc++.h>
using namespace std;

int a[225], b = 1;
int n, m;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n*m; ++i)
	{
		cin >> a[i];
		if (a[i] > a[1]) b++;
	}
	
	if (b <= n)
	{
		cout << 1 << ' ' << b;
		return 0;
	}
	if ((int)ceil(b*1.0/n) % 2 == 1)
	{
		cout << (int)ceil(b*1.0/n) << ' ' << b % n;
	}
	else
	{
		cout << (int)ceil(b*1.0/n) << ' ' << n - (b % n) + 1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
