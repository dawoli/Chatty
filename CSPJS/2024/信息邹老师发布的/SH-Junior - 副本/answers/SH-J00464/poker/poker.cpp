#include <bits/stdc++.h>
using namespace std;
map <string, int> mp;
string c[4]={"D", "C", "H", "S"};
string num[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
int n, ans;
int main()
{
	freopen("poker.in","r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n;i++)
	{
		string s;
		cin >> s;
		mp[s]++;
	}
	for(int i=0; i<=3; i++)
	{
		for(int j = 0; j <= 12; j++)
		{
			if(mp[c[i]+num[j]]== 0) ans++;
		}
	}
	cout << ans;
	return 0;
}
