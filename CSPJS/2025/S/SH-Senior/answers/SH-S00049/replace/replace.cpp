#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

string s1[5000005], s2[5000005];
int l[5000005];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s1[i] >> s2[i];
		l[i] = s1[i].size();
	}
	while (q--)
	{
		string t1, t2;
		int cnt = 0;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 1; i <= n; ++i)
		{
			int p = t1.find(s1[i]);
			if (p != t1.npos)
			{
				string x = t1;
				x.replace(p, l[i], s2[i]);
				if (x == t2)
					cnt++;
			}
		} 
		cout << cnt << endl;
	}
	return 0;
}
