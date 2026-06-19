#include<bits/stdc++.h>
using namespace std;
int n, cnt, ans;
string s;
map<string, int> mp;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s;
		if(mp[s] == 0)
		{
			cnt++;
		}
		mp[s]++;
	}
	ans = 52 - cnt;
	cout << ans;
	return 0;
}
