#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num1(char c)
{
	if (c == 'D')
	{
		return 1;
	}
	else if (c == 'C')
	{
		return 2;	
	}
	else if (c == 'H')
	{
		return 3;	
	}
	else if (c == 'S')
	{
		return 4;	
	}
}

int num2(char c)
{
	if (c > '1' && c <= '9')
	{
		return c - '0';
	}
	else
	{
		if (c == 'A')
		{
			return 1;
		}
		else if (c == 'T')
		{
			return 10;
		}
		else if (c == 'J')
		{
			return 11;
		}
		else if (c == 'Q')
		{
			return 12;
		}
		else
		{
			return 13;
		}	
	}
}

struct poker
{
	int x;
	int y;
};

bool cmp (poker a, poker b)
{
	if (a.y == b.y)
	{
		return a.x > b.x;
	}
	return a.y > b.y;
}

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	string s[52];
	poker p[52];
	int ans = 52 - n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		p[i].x = num1(s[i][0]);
		p[i].y = num2(s[i][1]);
	}
	sort(p, p + n, cmp);
	for (int i = 1; i < n; ++i)
	{
		if (p[i].x == p[i - 1].x && p[i].y == p[i - 1].y)
		{
			ans += 1;
		}
	}
	cout << ans;
	
	return 0;
}
