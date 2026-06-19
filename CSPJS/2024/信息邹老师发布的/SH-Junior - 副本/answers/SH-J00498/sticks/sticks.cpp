#include <bits/stdc++.h>

using namespace std; 

int t; 
int n; 

int main()
{
	freopen("sticks.in", "r", stdin); 
	freopen("sticks.out", "w", stdout); 
	cin >> t; 
	while(t--)
	{
		n = 0; 
		cin >> n; 
		if(n == 1)
		{
			cout << -1; 
		}
		else if(n % 7 == 0)
		{
			for(int i = 1; i <= n / 7; i++)
			{
				cout << 8; 
			}
			cout << endl; 
		}
		else if(n % 7 == 1)
		{
			cout << 10; 
			n--; 
			n /= 7; 
			n--; 
			for(int i = 1; i <= n; i++)
			{
				cout << 8; 
			}
		}
		else if(n % 7 == 2)
		{
			cout << 1; 
			n -= 2; 
			n /= 7; 
			for(int i = 1; i <= n; i++)
			{
				cout << 8; 
			}
		}
		else if(n % 7 == 3)
		{
			if(n == 3)
			{
				cout << 7; 
			}
			else
			{
				cout << 22; 
				n -= 3; 
				n /= 7; 
				n--; 
				for(int i = 1; i <= n; i++)
				{
					cout << 8; 
				}
			}
		}
		else if(n % 7 == 4)
		{
			if(n == 4)
			{
				cout << 5; 
			}
			else
			{
				cout << 20; 
				n -= 4; 
				n /= 7; 
				n--; 
				for(int i = 1; i <= n; i++)
				{
					cout << 8; 
				}
			}
		}
		else if(n % 7 == 5)
		{
			cout << 2; 
			n -= 5; 
			n /= 7; 
			for(int i = 1; i <= n; i++)
			{
				cout << 8; 
			}
		}
		else if(n % 7 == 6)
		{
			cout << 6; 
			n -= 6; 
			n /= 7; 
			for(int i = 1; i <= n; i++)
			{
				cout << 8; 
			}
		}
		cout << endl; 
	}
	return 0; 
}
