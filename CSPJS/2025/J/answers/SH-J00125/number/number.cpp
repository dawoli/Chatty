#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char s[1000005];
	cin >> s;
	int len = strlen(s);
	int a[310] = {};
	for(int i = 0; i < len; i++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			a[s[i]]++;
		}
	}
	for(char i = '9'; i >= '0'; i--)
	{
		if(a[i] >= 0)
		{
			for(int j = 0; j < a[i]; j++)
			{
				cout << i;
			}
		}
	}
	return 0;
}
