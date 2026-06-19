#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,h = 0,a[999];
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= a[];i++)
	{
		if (a[i] == 0)
		{ 
			if (a[i] - h == 0)
			{
				cout << h << endl;
			}
			else if (a[i] - h <= 0)
			{
				cout << -1 << endl;
			}
		}
		else
		{
			cout << -1 << endl;
		}
		h++;
	}
	return 0;
}
