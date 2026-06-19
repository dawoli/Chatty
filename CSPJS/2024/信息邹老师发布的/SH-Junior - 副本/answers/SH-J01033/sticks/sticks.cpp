#include <cstdio>
#include <iostream>
using namespace std;
int a[51];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < 2) cout << -1 << endl;
		else if (a[i] % 7 == 0)
		{
			a[i] /= 7;
			for (int j = 1; j <= a[i]; j++) cout << 8;
			cout << endl;
		}
		else if (a[i] % 7 == 1)
		{
			cout << 10;
			a[i] -= 8;
			a[i] /= 7;
			for (int j = 1; j <= a[i]; j++) cout << 8;
			cout << endl;
		}
		else if (a[i] % 7 == 2)
		{
			cout << 1;
			a[i] -= 2;
			a[i] /= 7;
			for (int j = 1; j <= a[i]; j++) cout << 8;
			cout << endl;
		}
		else if (a[i] % 7 == 3)
		{
			cout << 7;
			a[i] -= 3;
			a[i] /= 7;
			for (int j = 1; j <= a[i]; j++) cout << 8;
			cout << endl;
		}
		else if (a[i] % 7 == 4)
		{
			cout << 4;
			a[i] -= 4;
			a[i] /= 7;
			for (int j = 1; j <= a[i]; j++) cout << 8;
			cout << endl;
		}
		else if (a[i] % 7 == 5)
		{
			cout << 2;
			a[i] -= 5;
			a[i] /= 7;
			for (int j = 1; j <= a[i]; j++) cout << 8;
			cout << endl;
		}
		else if (a[i] % 7 == 6)
		{
			cout << 6;
			a[i] -= 6;
			a[i] /= 7;
			for (int j = 1; j <= a[i]; j++) cout << 8;
			cout << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
