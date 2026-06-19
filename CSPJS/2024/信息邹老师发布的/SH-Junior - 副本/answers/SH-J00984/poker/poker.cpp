#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
char c, d;
bool b[5][15] = {};

int turnC (char ch)
{
	switch (ch)
	{
		case 'D':
			return 1;
			break;
		case 'C':
			return 2;
			break;
		case 'H':
			return 3;
			break;
		case 'S':
			return 4;
			break;
		default:
			return 0;
			break;
	}
}

int turnD (char ch)
{
	if ('2' <= ch && ch <= '9')
		return ch - '0';
	switch (ch)
	{
		case 'A':
			return 1;
			break;
		case 'T':
			return 10;
			break;
		case 'J':
			return 11;
			break;
		case 'Q':
			return 12;
			break;
		case 'K':
			return 13;
			break;
		default:
			return 0;
			break;
	}
}

int main ()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c >> d;
		b[turnC(c)][turnD(d)] = true;
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			if (!b[i][j])
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
