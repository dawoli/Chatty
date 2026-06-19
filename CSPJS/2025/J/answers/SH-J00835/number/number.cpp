#include <bits/stdc++.h>
using namespace std;
string s;
int num[10];
int k = 0;
bool b = false;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int sz = s.size();
	while(sz--)
	{
		if ((s[k] >= '0') && (s[k] <= '9'))
		{
			num[s[k] - '0']++;
			if (s[k] != '0')
			{
				b = true;
			}
		}
		k++;
	}
	if (b)
	{
		for (int i = 9; i >= 0; i--)
		{
			while(num[i]--)
			{
				cout << i;
			}
		}
	}
	else
	{
		cout <<'0';
	}
	return 0;
}
