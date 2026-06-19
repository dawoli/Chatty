#include<bits/stdc++.h>
using namespace std;
int n, m, a[110], p;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	sort(a + 2, a + n * m + 1);
	int p = upper_bound(a + 2, a + n * m + 1, a[1]) - a;
	p = n * m - p + 2;
	cout << (p + n - 1) / n << ' ';
	if ((p + n - 1) / n % 2 != 0)
	{
		if (p % n == 0)
			cout << n;
		else
			cout << p % n;
	}
	else
	{
		if (p % n == 0)
			cout << 1;
		else
	    	cout << n - p % n + 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
