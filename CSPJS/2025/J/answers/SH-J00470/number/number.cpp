#include <bits/stdc++.h>
using namespace std;

int a[105];
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for (int i = 0; i <= s.size()-1; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			int x = s[i]-'0';
			a[x]++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= a[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
 } 
