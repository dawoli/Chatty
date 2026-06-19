#include <bits/stdc++.h>
using namespace std;
int num[10] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in ","r",stdin);
	freopen("sticks.out ","w",stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		if (n <= 1) -1;
		else if (n % 7 == 0 && n >= 21)
		{
			cout << 100;
			for (int i = 1;i < n/7-1;i++) cout << 8;
			cout << endl;
		}
		else if (n % 7 == 1)
		{
			cout << 10;
			for (int i = 1;i < n/7;i++) cout << 8;
			cout << endl;
		}
		else
		{
			vector<int> vec;
			int wz =int((n/7.0)+0.999);
			for (long long i = pow(10,wz-1);i <= pow(10,wz);i++)
			{
				int x= i;
				int sum = 0;
				while (x)
				{
					sum += num[x%10];
					x/=10;
				}
				if (sum == n)
				{
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}
