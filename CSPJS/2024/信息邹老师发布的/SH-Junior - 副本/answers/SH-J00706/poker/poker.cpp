#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
map <string, int> mp; 
int ans = 52;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		mp[s]++;
	}
	for (auto v : mp)
	{
		ans--;
	}
	cout << ans;
}
