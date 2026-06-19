#include <bits/stdc++.h>
using namespace std;

int a[] = {0,-1,1,7,4,2,0,8,10,18,22,20,28,68,88,108,188,206,208,288,688};

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++)
	{
		int n;
		cin >> n;
		if(n <= 20)
		{
			cout << a[n] << endl;
		}
		else if(n % 7 == 0)
		{
			for(int i = 1;i <= n / 7;i++)
			{
				cout << '8';
			}
			cout << endl;
		}
		else if(n % 7 == 1)
		{
			cout << "10";
			for(int i = 1;i <= n / 7 - 1;i++)
			{
				cout << '8';
			}
			cout << endl;
		}
	}
	return 0;
}
