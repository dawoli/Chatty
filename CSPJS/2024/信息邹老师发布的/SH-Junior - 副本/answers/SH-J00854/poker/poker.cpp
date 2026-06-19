#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

signed main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	int cnt = 52;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		if(!mp.count(s))
		{
			mp[s] = 1;
			cnt--;
		}
	}
	cout << cnt;
	return 0;
 } 
