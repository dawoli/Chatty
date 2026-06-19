#include <iostream>
using namespace std;
int n, q;
long long ans;
string t1, t2, s1[200001], s2[200001];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	while (q--)
	{
		ans = 0;
		cin >> t1 >> t2;
		for (int i = 1; i <= n; i++)
		{
			if (t1.find(s1[i]) != -1 && t2.find(s2[i]) != -1)
			{
				for (int j = 0; j < t1.size(); j++)
				{
					if (t1.substr(j, s1[i].size()) == s1[i])
					{
						long long cur = 0;
						string st = t1;
						for (int k = j; k < j + s1[i].size(); k++)
							st[k] = s2[i][cur++];
						if (st == t2) ++ans;					
					}
				}	
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
