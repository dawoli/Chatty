#include <bits/stdc++.h>
using namespace std;

int n, q;
map<int, vector<pair<int, int> > > nww;

string s1[100010], s2[100010];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
		nww[s1[i].find('b')-s2[i].find('b')].push_back(make_pair(s1[i].find('b'), s1[i].size()-s1[i].find('b')));
	}
	if (q == 1)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << 0 << endl;
			return 0;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s1[i].size() > t1.size() || s2[i].size() > t2.size())	continue;
			for (int j = 0; j <= t1.size()-s1[i].size(); j++)
			{
				string z1 = t1.substr(j, s1[i].size()), z2 = t2.substr(j, s2[i].size());
				if (s1[i] == z1 && s2[i] == z2 && t1.substr(0, j)+z2+t1.substr(j+s1[i].size()) == t2)
					ans++;
			}
		}
		cout << ans << endl;
	}
	else if (n <= 1000 && q <= 1000)
	{
		while (q--)
		{
			string t1, t2;
			cin >> t1 >> t2;
			if (t1.size() != t2.size())
			{
				cout << 0 << endl;
				continue;
			}
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				if (s1[i].size() > t1.size() || s2[i].size() > t2.size())	continue;
				for (int j = 0; j <= t1.size()-s1[i].size(); j++)
				{
					string z1 = t1.substr(j, s1[i].size()), z2 = t2.substr(j, s2[i].size());
					if (s1[i] == z1 && s2[i] == z2 && t1.substr(0, j)+z2+t1.substr(j+s1[i].size()) == t2)
						ans++;
				}
			}
			cout << ans << endl;
		}
	}
	else
	{
		while (q--)
		{
			string t1, t2;
			cin >> t1 >> t2;
			int ans = 0;
			if (t1.size() != t2.size())
			{
				cout << 0 << endl;
				continue;
			}
			int tmp = t1.find('b') - t2.find('b');
			for (int i = 0; i < nww[tmp].size(); i++)
			{
				if (t1.find('b') >= nww[tmp][i].first && t1.size() - t1.find('b') >= nww[tmp][i].second)
					ans++;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
