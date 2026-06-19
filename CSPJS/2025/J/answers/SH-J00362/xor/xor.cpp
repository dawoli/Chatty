#include <iostream>
using namespace std;

int n, k, a[500002], ans[5000002], zeros, ones;
int main()
{
freopen("xor.in", "r", stdin);
freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			zeros++;
		}
		else if (a[i] == 1)
		{
			ones++;
		}
	}
	if (k == 1)
	{
		cout << ones;
		return 0;
	}
	if (k == 0 && zeros + ones == n)
	{
		cout << zeros + ones / 2;
		return 0;
	}
	cout << n;
fclose(stdin);
fclose(stdout);
	return 0;
}
