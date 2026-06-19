#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 200005, mod = 1e18 + 9;

struct re
{
	string a, b;
	bool operator <(const re &e) const
	{
		return a.size() < e.a.size();
	}
} s[N];

int n, q;



signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	
	for (int i = 1;i <= n; ++ i)
		cin >> s[i].a >> s[i].b;
	
	sort(s + 1, s + n + 1);
	
	while (q --)
	{
		string aa, bb;cin >> aa >> bb;
		int ans = 0;
		for (int i = 1; i <= n; ++ i)
		{
			string ss = aa;
			for (int j = 0; j < aa.size(); ++ j)
			{
				if (s[i].a.size() + j > aa.size()) continue;
				bool flag = false;
				for (int k = j;k < s[i].a.size() + j; ++ k)
				{
					if (aa[k] != s[i].a[k - j]) { break;}
					ss[k] = s[i].b[k - j];
					if (k - j == s[i].a.size() - 1) flag = true;
				}
				if (flag && ss == bb) ans ++;
				ss = aa;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
 } 
