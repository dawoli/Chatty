#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
map<string, int> mp;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		mp[s]++;
	}
	cout << 52 - mp.size();
}
