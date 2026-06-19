#include <bits/stdc++.h>
using namespace std;

string s[110];
map<string, int> mp;

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	int ans = 52;
	for (int i = 1; i <= n; i++)
	{
		if (!mp.count(s[i]))
		{
			mp[s[i]] = 1;
			ans--;
		}
	}
	cout << ans << endl;
	return 0;
}
