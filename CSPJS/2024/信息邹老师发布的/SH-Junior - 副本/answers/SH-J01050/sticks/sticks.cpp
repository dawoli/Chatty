#include <iostream>
using namespace std;
int n, T, a[13] = {-1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68}, b[7] = {88, 108, 188, 206, 208, 288, 688};

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		if(n <= 13)
		{
			cout << a[n - 1];
		}
		else 
		{
			cout << b[n % 7];
			for(int i = 1;i <= (n - 14 - n % 7) / 7;i++)
			{
				cout << 8;
			}
		}
		cout << endl;
	}
	return 0;	
} 
