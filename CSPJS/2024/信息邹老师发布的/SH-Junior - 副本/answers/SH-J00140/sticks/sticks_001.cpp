#include<bits/stdc++.h>
using namespace std;

int y[10] = {6,2,5,5,4,5,6,3,7,6};
int f[51] = {0,-1,1,7,4,2,6,8};
 

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		if(n <= 6)
		{
			cout << f[n];
		}
		else if(n % 7 == 0 && n > 6)
		{
			for(int i = 1; i <= n / 7; i++)
			{
				cout << 8;
			}
		}
		else if(n % 7 == 1 && n > 6)
		{
			cout << 10;
			for(int i = 1; i <= ((n - 8) / 7); i++)
			{
				cout << 8;
			}
		}
		else if(n % 7 == 2 && n > 6)
		{
			cout << 1;
			for(int i = 1; i <= (n - 2) / 7; i++)
			{
				cout << 8;
			}
		}
		else if(n % 7 == 3 && n > 6)
		{
			cout << 22;
			for(int i = 1; i <= (n - 10) / 7; i++)
			{
				cout << 8;
			}
		}
		else if(n % 7 == 4 && n > 6)
		{
			cout << 20;
			for(int i = 1; i <= (n - 11) / 7; i++)
			{
				cout << 8;
			}
		}
		else if(n % 7 == 5 && n > 6)
		{
			cout << 2;
			for(int i = 1; i <= (n - 5) / 7; i++)
			{
				cout << 8;
			}
		}
		else if(n % 7 == 6 && n > 6)
		{
			cout << 6;
			for(int i = 1; i <= (n - 2) / 7; i++)
			{
				cout << 8;
			}
		}
		cout << endl;
	}
	return 0;
}
