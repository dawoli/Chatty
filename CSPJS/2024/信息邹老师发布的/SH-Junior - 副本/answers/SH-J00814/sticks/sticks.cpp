#include <iostream>
#include <cstdio>
using namespace std;
int t,n,len,k;
void print1(int x)
{
	if (len == 1)
	{
		if (k >= 6)
		{
			cout << -1;len--;return;
		}
		else if (k == 5)
		{
			cout << 1;len--;return;
		}
		else if (k == 4)
		{
			cout << 7;len--;return;
		}
		else if (k == 3)
		{
			cout << 4;len--;return;
		}
		else if (k == 2)
		{
			cout << 2;len--;return;
		}
		else if (k == 1)
		{
			if (x == 0)
			{
				cout << 6;len--;return;
			}
			else
			{
				cout << 0;len--;return;
			}
		}
		else if (k == 0)
		{
			cout << 8;len--;return;
		}
	}
	if (k >= 5)
	{
		cout << 1;
		k -= 5;
		len--;
	}
	else if (k >= 2)
	{
		cout << 2;
		k -= 2;
		len--;
	}
	else if (k >= 1)
	{
		if (x == 0)
		{
			cout << 6;k -= 1;len--;
		}
		else
		{
			cout << 0;k -= 1;len--;
		}
	}
	else
	{
		cout << 8;
		len--;
	}
}
void print2()
{
	if (len == 0) return;
	int num = k;
	for (int i = 1;i <= num;i++)
	{
		cout << 0;
		k--;
		len--;
		if (len == 1)
		{
			print1(1);
			return;
		}
	}
	for (int i = 1;i <= len;i++) cout << 8;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n;
		if (n%7 == 0) len = n/7;
		else len = n/7+1;
		k = 7*len-n;
		print1(0);
		print2();
		cout << endl;
	}
	return 0;
}
