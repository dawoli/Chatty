#include <bits/stdc++.h>
using namespace std;
bool D[20];
bool C[20];
bool H[20];
bool S[20];
int main()
{
	freopen("poker.in ","r",stdin);
	freopen("poker.out ","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		if(s[0] == 'D')
		{
			if (s[1] == 'A')
				D[1] = 1;
			else if (s[1]-'1'+1 >= 2 && s[1]-'1'+1 <= 9)
				D[s[1]-'1'+1] = 1;
			else if (s[1] == 'T')
				D[10] = 1;
			else if (s[1] == 'J')
				D[11] = 1;
			else if (s[1] == 'Q')
				D[12] = 1;
			else if (s[1] == 'K')
				D[13] = 1;
		}
		if(s[0] == 'C')
		{
			if (s[1] == 'A')
				C[1] = 1;
			else if (s[1]-'1'+1 >= 2 && s[1]-'1'+1 <= 9)
				C[s[1]-'1'+1] = 1;
			else if (s[1] == 'T')
				C[10] = 1;
			else if (s[1] == 'J')
				C[11] = 1;
			else if (s[1] == 'Q')
				C[12] = 1;
			else if (s[1] == 'K')
				C[13] = 1;
		}
		if(s[0] == 'H')
		{
			if (s[1] == 'A')
				H[1] = 1;
			else if (s[1]-'1'+1 >= 2 && s[1]-'1'+1 <= 9)
				H[s[1]-'1'+1] = 1;
			else if (s[1] == 'T')
				H[10] = 1;
			else if (s[1] == 'J')
				H[11] = 1;
			else if (s[1] == 'Q')
				H[12] = 1;
			else if (s[1] == 'K')
				H[13] = 1;
		}
		if(s[0] == 'S')
		{
			if (s[1] == 'A')
				S[1] = 1;
			else if (s[1]-'1'+1 >= 2 && s[1]-'1'+1 <= 9)
				S[s[1]-'1'+1] = 1;
			else if (s[1] == 'T')
				S[10] = 1;
			else if (s[1] == 'J')
				S[11] = 1;
			else if (s[1] == 'Q')
				S[12] = 1;
			else if (s[1] == 'K')
				S[13] = 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 13; i++)
	{
		if (!D[i]) cnt++;
		if (!C[i]) cnt++;
		if (!H[i]) cnt++;
		if (!S[i]) cnt++;
	}
	cout << cnt;
	return 0;
}
