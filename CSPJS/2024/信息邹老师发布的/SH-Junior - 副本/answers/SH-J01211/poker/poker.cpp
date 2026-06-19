#include <iostream>
#include <cstdio>
using namespace std;
int M[14][5], n, c, d, cc = 0;
char a, b;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b >> a;
		switch (a)
		{
			case 'A': c = 1; break;
			case 'T': c = 10; break;
			case 'J': c = 11; break;
			case 'Q': c = 12; break;
			case 'K': c = 13; break;
			default: c = a - '0';
		}
		switch (b)
		{
			case 'D': d = 1; break;
			case 'C': d = 2; break;
			case 'H': d = 3; break;
			case 'S': d = 4;
		}
		M[c][d]++;
	}
	for (int i = 1; i <= 13; i++)
		for (int j = 1; j <= 4; j++)
			if (M[i][j] == 0) cc++;
	cout << cc << endl;
	return 0;
 } 
