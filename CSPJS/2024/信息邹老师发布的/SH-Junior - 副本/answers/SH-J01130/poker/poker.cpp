#include <bits/stdc++.h>
using namespace std;
bool poke[57] = {};
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	memset(poke, 0, sizeof(poke));
	int p, q, sum = 0;
	int n;
	char x[7];
	cin >> n;
	for (int i = 0; i < n; i++)    // O(n)
	{
		cin >> x;
		switch(x[0])
		{
			case 'D': p = 0; break;
			case 'C': p = 1; break;
			case 'H': p = 2; break;
			case 'S': p = 3; break;
		}
		switch(x[1])
		{
			case 'A': q = 0; break;
			case '2': q = 1; break;
			case '3': q = 2; break;
			case '4': q = 3; break;
			case '5': q = 4; break;
			case '6': q = 5; break;
			case '7': q = 6; break;
			case '8': q = 7; break;
			case '9': q = 8; break;
			case 'T': q = 9; break;
			case 'J': q = 10; break;
			case 'Q': q = 11; break;
			case 'K': q = 12; break;
		}
		poke[p * 13 + q] = 1;
	}
	for (int i = 0; i < 52; i++)
	{
		if (!poke[i]) sum++;
	}
	cout << sum << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
