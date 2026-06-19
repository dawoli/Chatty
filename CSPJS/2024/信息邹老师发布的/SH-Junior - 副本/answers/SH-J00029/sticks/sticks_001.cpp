#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int t, dic[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(n == 1)
			cout << -1 << endl;
		else if(n == 2)
			cout << 1 << endl;
		else if(n == 3)
			cout << 7 << endl;
		else if(n == 4)
			cout << 4 << endl;
		else if(n == 5)
			cout << 2 << endl;
		else if(n == 6)
			cout << 6 << endl;
		else if(n == 7)
			cout << 8 << endl;
		else if(n == 8)
			cout << 10 << endl;
		else if(n == 9)
			cout << 24 << endl;
		else if(n == 18)
			cout << 208 << endl;
		else if(n % 7 == 0)
		{
			for(int i = 1; i <= n / 7; i++)
				cout << 8;
			cout << endl;
		}
		else if(n % 6 == 0)
		{
			cout << 6;
			for(int i = 1; i <= n / 6 - 1; i++)
				cout << 0;
			cout << endl;
		}
		else if(n % 5 == 0)
		{
			for(int i = 1; i <= n / 5; i++)
				cout << 2;
			cout << endl;
		}
		else if(n % 4 == 0)
		{
			for(int i = 1; i <= n / 4; i++)
				cout << 4;
			cout << endl;
		}
		else if(n % 3 == 0)
		{
			for(int i = 1; i <= n / 3; i++)
				cout << 7;
			cout << endl;
		}
		else if(n % 2 == 0)
		{
			for(int i = 1; i <= n / 2; i++)
				cout << 1;
			cout << endl;
		}
		else if(n % 7 == 1)
		{
			for(int i = 0; i < 10; i++)
				if(dic[i] == n % 6)
				{
					cout << i;
					break;
				}
					
			for(int i = 1; i <= n / 6; i++)
				cout << 0;
			cout << endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
