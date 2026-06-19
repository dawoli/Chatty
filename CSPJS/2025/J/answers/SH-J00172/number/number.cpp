#include <bits/stdc++.h>
using namespace std;

int num[15];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i])) num[s[i]-'0']++;
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= num[i]; j++) cout << i;
	}
	return 0;
}
