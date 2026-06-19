#include <bits/stdc++.h>
using namespace std;

bool card[5][15];

int main()
{
	freopen("poker.in", "r", stdin); 
	freopen("poker.out", "w", stdout); 
	int n, res = 52;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		char typ_c = s[0];
		char num_c = s[1];
		int typ = 0, num = 0;
		if (num_c == 'A')
			num = 1;
		else if (num_c == 'T')
			num = 10;
		else if (num_c == 'J')
			num = 11;
		else if (num_c == 'Q')
			num = 12;
		else if (num_c == 'K')
			num = 13;
		else
			num = num_c - '0';
		
		if (typ_c == 'D')
			typ = 1;
		else if (typ_c == 'C')
			typ = 2;
		else if (typ_c == 'H')
			typ = 3;
		else if (typ_c == 'S')
			typ = 4;
		if (!card[typ][num])
		{
			card[typ][num] = true;
			res -= 1;
		}
	}
	cout << res << endl;
	return 0;
}

