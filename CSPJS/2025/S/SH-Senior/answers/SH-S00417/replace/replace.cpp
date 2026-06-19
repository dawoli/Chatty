#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q, ans;
string s[N][2], a, b;
bool check(int i)
{
	int j = 0, k = 0;
	for (j = 0; j < a.size(); j++)
	{
		int last = j;
		for (k = 0; k < s[i][0].size() && j < a.size(); k++, j++)
		{
			if (a[j] != s[i][0][k] || b[j] != s[i][1][k])
				break;
		}
		if (k == s[i][0].size())
			break;
		if (a[j] != b[j])
			return 0;
		j = last;
	}
	if (k == s[i][0].size())
	{
		while (j < a.size())
			if (a[j] != b[j])
				return 0;
			else
				j++;
	}
	else
		return 0;
	return 1;
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][0] >> s[i][1];
	while (q--)
	{
		ans = 0;
		cin >> a >> b;
		if (a.size() != b.size())
		{
			cout << 0 << "\n";
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			if (s[i][0].size() > a.size())
				continue;
			if (check(i))
				ans++;
		}
		cout << ans << "\n";
	}
}
// 50
