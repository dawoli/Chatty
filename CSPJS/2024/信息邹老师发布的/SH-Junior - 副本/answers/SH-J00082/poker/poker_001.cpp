#include <bits/stdc++.h>
using namespace std;

string a = "0DCHS";
string b = "0A23456789TJQK";
int n;
map<string, bool> mp;

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			string str = "";
			string sa = "", sb = "";
			sa = a[i], sb = b[j];
			str = sa + sb;
			mp[str] = false;
		}
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		mp[s] = true;
	}
	int cnt = 0;
	for (auto m: mp)
	{
		if (m.second == false) cnt++;
	}
	cout << cnt;
	return 0;
}
