#include <bits/stdc++.h>
#define int128 unsigned long long
using namespace std;
int128 n, t[1000001];
int main ()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int128 i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			t[++n] = s[i] - '0';
	}
	sort(t + 1, t + n + 1);
	for (int128 i = n; i >= 1; i--)
		cout << char(t[i] + '0');
	return 0;
}
