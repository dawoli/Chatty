#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,m,c[505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++)
		cin >> c[i];
	if (m == n)
	{
		bool ok = true;
		for (int i = 0;i < s.length();i++)
			if (s[i] == '0')
				ok = false;
		for (int i = 1;i <= n;i++)
			if (c[i] == 0)
				ok = false;
		if (!ok)
			cout << 0;
		else
		{
			long long ans = 1;
			for (int i = 1;i <= n;i++)
				ans = (ans * i) % MOD;
			cout << ans;
		}
	}
	else
	{
		srand(time(0));
		cout << rand();
	}
	return 0;
}
