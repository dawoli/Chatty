#include <bits/stdc++.h>
using namespace std;
long long T, n, dgt = 0; 
char ans[14286], frame[6] = {'8', '0', '2', '4', '7', '1'};
void f()
{
	if(n == 1)
	{
		cout << -1 << endl;
	}
	else if(n % 7 == 0)
	{
		while(n)
		{
			n -= 7;
			cout << 8;
		}
		cout << endl;
	}
	else
	{
		int c = 7 - n % 7;
		n += c;
		dgt = n / 7;
		if(dgt == 1 && c != 1)
		{
			cout << frame[c];
		}
		else if(dgt == 1)
		{
			cout << 6;
		}
		else if(c >= 5)
		{
			c -= 5;
			ans[1] = '1';
		}
		else if(c != 1)
		{
			ans[1] = '2';
			c -= 2;
		}
		else
		{
			ans[1] = '8';
		}
		for(int i = 2;i <= dgt;i++)
		{
			if(i == dgt)
			{ 
				ans[i] = frame[c];	
			}
			else if(c >= 1)
			{
				c -= 1;
				ans[i] = '0'; 
			}
			else
			{
				ans[i] = '8';
			}	
		}
		for(int i = 1;i <= dgt;i++)
		{
			cout << ans[i];
		}
		cout << endl;
	}
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	for(int i = 0;i < T;i++)
	{
		cin >> n;
		f();
	}
	return 0;
}
