#include <iostream>
#include <stdio.h>
using namespace std; 

int n;
bool kards[55]; // 13+13+13+13
int ans;

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b;
		cin >> a >> b;
		int aa, bb;
		if (a == 'D')
		{
			aa = 1;
		}
		else if (a == 'C')
		{
			aa = 2;
		}
		else if (a == 'H')
		{
			aa = 3;
		}
		else if(a == 'S')
		{
			aa = 4;
		}
		if (b == 'A')
		{
			bb = 1;
		}
		else if (b == 'T')
		{
			bb = 10;
		}
		else if (b == 'J')
		{
			bb = 11;
		}
		else if (b == 'Q')
		{
			bb = 12;
		}
		else if (b == 'K')
		{
			bb = 13;
		}
		else if (b >= '2' && b <= '9')
		{
			bb = b - '0';
		}
		if (!kards[(aa - 1) * 13 + bb])
		{
			ans++;
			kards[(aa - 1) * 13 + bb] = true;
		}
	}
	cout << 52 - ans << endl;
	return 0;
}

// 0s 80
