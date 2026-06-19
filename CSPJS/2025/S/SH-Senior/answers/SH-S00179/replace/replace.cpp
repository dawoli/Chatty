#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, q;
map <string, int> mp;

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] = i;
		mp[s2] = i;
	}
	
	while (q--)
	{
		int ans = 0;
		string s1, s2;
		cin >> s1 >> s2;
		
		s1 = " " + s1;
		s2 = " " + s2;
		

		if (s1.size() != s2.size())
		{
			cout << "0\n";
			continue;
		}
		
		int hd = -1, tl = -1;
		
		for (int i = 1; i <= s1.size(); i++)
		{
			if (s1[i] != s2[i])
			{
				if (hd == -1)
					hd = i;
				tl = i;
			}
		}
	
		for (int i = 1; i <= hd; i++)
		{
			
			for (int j = tl; j <= s1.size(); j++)
			{
				string s3 = "";
				string s4 = "";
				for (int k = i; k <= j; k++)
				{
					s3 += s1[k];
					s4 += s2[k];
				}
				if (mp[s3] == mp[s4] && mp[s3] != 0 && mp[s4] != 0)
				{
					ans++;
				}
					
			}
		}
		
		cout << ans << '\n';
	}
}
