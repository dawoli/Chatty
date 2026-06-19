#include <bits/stdc++.h>
using namespace std;

int a[10];
string s;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	
	for(int i = 0; i < s.size(); i++)
		if(isdigit(s[i]))
			a[s[i] - '0']++;
	for(int i = 9; i >= 0; i--)
		while(a[i]--)
			printf("%d", i);
	return 0;
}
