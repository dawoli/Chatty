#include <bits/stdc++.h>
using namespace std;

bool a[5][15];

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n, t;
	string tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp[0] == 'D') t = 0;
		else if (tmp[0] == 'C') t = 1;
		else if (tmp[0] == 'H') t = 2;
		else t = 3;
		if (tmp[1] == 'T') a[t][10] = 1;
		else if (tmp[1] == 'J') a[t][11] = 1;
		else if (tmp[1] == 'Q') a[t][12] = 1;
		else if (tmp[1] == 'K') a[t][13] = 1;
		else if (tmp[1] == 'A') a[t][1] = 1;
		else a[t][tmp[1]-48] = 1;
	}
	int c = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			if (!a[i][j]) c++;
		}
	}
	cout << c;
	return 0;
}
