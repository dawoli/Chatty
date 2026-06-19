#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int a[1000005], now;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i])) a[++now] = s[i] - '0';
	}
	sort(a + 1, a + now + 1);
	for (int i = now; i >= 1; i--) cout << a[i];
 } 
