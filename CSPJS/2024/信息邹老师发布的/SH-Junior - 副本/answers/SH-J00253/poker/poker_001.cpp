#include <bits/stdc++.h>
using namespace std;

int n, ans;
bool p[10][20];

void change(char s[])
{
	int x, y;
	char hua[10] = {'D', 'C', 'H', 'S'};
	for (int i = 0; i < 4; i++)
	{
		if (s[0] == hua[i])
		{
			x = i + 1;
			break;
		}
	}
	char dian[20] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	for (int i = 0; i < 13; i++)
	{
		if (s[1] == dian[i])
		{
			y = i + 1;
			break;
		}
	}
	p[x][y] = true;
}

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char s[5];
		cin >> s;
		change(s);
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			ans += p[i][j];
		}
	}
	cout << 52 - ans << endl;
	return 0;
}
