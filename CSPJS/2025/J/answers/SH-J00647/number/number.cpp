#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int a[1000006];
string s;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			a[++t] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + t);
	for (int i = t; i >= 1; i--)
	{
		cout << a[i];
	}
	cout << "\n";
	return 0;
}
