#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		int n;
		cin >> n;
		if (n==1)
		{
			cout << -1 << endl;
			continue;
		}
		if (n%7==0)
		{
			for (int j=1;j<=n/7;j++)
			{
				cout << '8';
			}
			cout << endl;
			continue;
		}
		if (n==2)
		{
			cout << 1 << endl;
			continue;
		}
		if  (n==3)
		{
			cout << 7 << endl;
			continue;
		}
		if  (n==4)
		{
			cout << 4 << endl;
			continue;
		}
		if  (n==5)
		{
			cout << 2 << endl;
			continue;
		}
		if  (n==6)
		{
			cout << 6 << endl;
			continue;
		}
		if  (n==7)
		{
			cout << 8 << endl;
			continue;
		}
		if (n%7<=2)
		{
			cout << 1;
			for (int j=1;j<=n/7;j++)
			{
				if (j<=	2-n%7)
				{
					cout << 0;
				}
				else
				{
					cout << 8;
				}
			}
			cout << endl;
			continue;
		}
		if (n/7>=5-n%7 && n%7<=5)
		{
			cout << 2;
			for (int j=1;j<=n/7;j++)
			{
				if (j<=5-n%7)
				{
					cout << 0;
				}
				else
				{
					cout << 8;
				}
			}
			cout << endl;
			continue;
		}
		if (n/7>=4-n%7 && n%7<=4)
		{
			cout << 4;
			for (int j=1;j<=n/7;j++)
			{
				if (j<=4-n%7)
				{
					cout << 0;
				}
				else
				{
					cout << 8;
				}
			}
			cout << endl;
			continue;
		}
		cout << 6;
		for (int j=1;j<=n/7;j++)
		{
			if (j<=6-n%7)
			{
				cout << 0;
			}
			else
			{
				cout << 8;
			}
		}
		cout << endl;
	}
	return 0;
}
