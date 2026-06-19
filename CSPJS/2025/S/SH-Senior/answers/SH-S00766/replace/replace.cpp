// 10pts

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int n, q;
map <string, string> mp;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	while (n--)
	{
		string str1, str2;
		cin >> str1 >> str2;
		mp[str1] = str2;
	}
	while (q--)
	{
		string str1, str2;
		cin >> str1 >> str2;
		int ans = 0;
		for (int i = 0; i < str1.size(); i++)
		{
			for (int j = i; j < str1.size(); j++)
			{
//				cout << str1.substr(i, j - i + 1) << ", ";
				if (mp.find(str1.substr(i, j - i + 1)) != mp.end())
				{
//					cout << str1.substr(0, i) + mp[str1.substr(i, j - i + 1)] + str1.substr(j + 1) << " ";
					if (str1.substr(0, i) + mp[str1.substr(i, j - i + 1)] + str1.substr(j + 1) == str2) ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}
