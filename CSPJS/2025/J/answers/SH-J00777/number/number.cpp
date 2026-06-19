#include <bits/stdc++.h>
using namespace std;
string s;
int a[10] = {};
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
			a[int(s[i]) - int('0')]++;
	}
	for(int i = 9; i >= 0; i--)
	{
		if(a[i] == 0)
			continue;
		for(int j = 0; j < a[i]; j++)
			printf("%d", i);
	}
	printf("\n");
	return 0;
}
