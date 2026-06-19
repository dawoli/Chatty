#include <bits/stdc++.h>
using namespace std;

int T, n[60] = {};
int a[20] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108};
int s, r;

int turnR (int m)
{
	switch (m)
	{
		case 0:
			return 888;
			break;
		case 1:
			return 108;
			break;
		case 2:
			return 188;
			break;
		case 3:
			return 200;
			break;
		case 4:
			return 208;
			break;
		case 5:
			return 288;
			break;
		case 6:
			return 688;
			break;
		default:
			return 5;
			break;
	}
}

int main ()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);	
	cin >> T;
	for (int i = 1; i <= T; i++)
		cin >> n[i];
	for (int i = 1; i <= T; i++)
	{
		if (n[i] < 15)
			cout << a[n[i]] << endl;
		else
		{
			s = n[i] / 7;
			r = n[i] % 7;
			cout << turnR(r);
			for (int j = 1; j <= s - 2; j++)
				cout << 8;
			cout << endl;
		}
	}
	return 0;
}
