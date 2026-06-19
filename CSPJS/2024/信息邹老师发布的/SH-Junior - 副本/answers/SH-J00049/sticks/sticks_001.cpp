#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int ans[15] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20};

string makeAns(int x)
{
	string s = "";
	if (x % 7 == 1)
	{
		x -= 7;
		s += "10";
	}
	if (x % 7 == 2)
	{
		s += '1';
	}
	if (x % 7 == 3)
	{
		x -= 14;
		s += "200";
	}
	if (x % 7 == 4)
	{
		x -= 7;
		s += "20";
	}
	if (x % 7 == 5)
	{
		s += '2';
	}
	if (x % 7 == 6)
	{
		s += '6';
	}
	for (int i = 1; i <= x / 7; ++i)
	{
		s += '8';
	}
	return s;
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n <= 12)
		{
			cout << ans[n] << endl;
		}
		else
		{
			cout << makeAns(n) << endl;
		}
	}
	return 0;
} 
