#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string, bool> mp;

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n, cnt = 52;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (!mp[s])
		{
			mp[s] = true;
			cnt--;
		}
	}
	cout << cnt << endl;
	return 0;
} 
