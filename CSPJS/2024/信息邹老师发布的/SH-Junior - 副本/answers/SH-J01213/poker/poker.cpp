#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		mp[s]++;
		if (mp[s] == 1) cnt++;
	}
	cout << 52 - cnt;
	return 0;
}
