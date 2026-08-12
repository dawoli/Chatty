// Problem URL: https://www.luogu.com.cn/contest/325521
// Finish Time: 2026/8/1 14:24:01 AC
// Start Time: 2026/8/1 14:03:27

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int	   n, x;
string s, ans;
bool   dir = 1; // 1是从左往右、前，0是从右往左、后

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	n = s.size();
	x = n + 1;
	ans.append(s);

	while (--x)
	{
		if (dir)
		{
			ans.append(s.substr(0, x));
		}
		else
		{
			string sub = s.substr(n - x, x);
			reverse(sub.begin(), sub.end());
			ans.append(sub);
		}
		dir ^= 1;
	}
	cout << ans;
	return 0;
}