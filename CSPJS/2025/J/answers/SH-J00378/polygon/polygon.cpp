#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, arr[long(1e5)], maxi = 0, sum = 0;
	cin >> n;
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		maxi = max(maxi, arr[i]);
	}
	if (maxi * 2 < sum) cout << 1;
	else cout << 0;
	return 0;
}
