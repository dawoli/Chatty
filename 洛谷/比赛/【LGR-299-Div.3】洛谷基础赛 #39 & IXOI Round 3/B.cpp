// Problem URL: https://www.luogu.com.cn/contest/311135
// Finish Time: 2026/9/6 14:20:03 AC
// Finish Time: 2026/9/6 14:17:13 WA 10pts
// Start Time: 2026/9/6 13:57:20

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 1e5 + 5;

string s;
int	   n, ans = 0;

void clean(int x)
{
	for (int i = x; i <= n; i += x)
	{
		if (s[i - 1] == '0')
			s[i - 1] = '1';
		else
			s[i - 1] = '0';
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		if (s[i - 1] == '0')
		{
			ans++;
			clean(i);
		}
	}
	cout << ans << endl;
	return 0;
}

// Deep in the dark, I don't need the light
// There's a ghost inside me
// It all belongs to the other side
// We live, we love, we lie