// Problem URL: https://www.luogu.com.cn/problem/P3536
// Finish Time: 2026/8/12 10:29:28 AC
// Finish Time: 2026/8/12 10:26:47 TLE 97pts
// Finish Time: 2026/8/12 10:19:08 TLE 85pts
// Finish Time: 2026/8/12 10:09:40 WA/TLE 26pts
// Finish Time: 2026/8/11 15:26:14 TLE 28pts
// Finish Time: 2026/8/11 15:09:35 TLE 25pts
// Finish Time: 2026/8/11 15:07:59 TLE 25pts
// Finish Time: 2026/8/11 15:05:07 WA/TLE/RE 23pts
// Finish Time: 2026/8/11 14:55:07 WA/RE 23pts
// Finish Time: 2026/8/11 14:50:41 TLE 25pts
// Finish Time: 2026/8/11 14:48:51 TLE 25pts
// Finish Time: 2026/8/11 14:43:35 TLE 23pts
// Start Time: 2026/8/11 14:23:24

#include <bits/stdc++.h>
#define endl '\n'
#define int unsigned long long
using namespace std;
const int MAXN = 1e6 + 6;
const int MAXM = MAXN;

int						 n, m, a, _b, s[MAXN], cnt = 0;
bitset<MAXM>			 b;
unordered_map<int, bool> c;
vector<int>				 g;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> _b;
		b[_b] = true;
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		int _a = a;
		int x  = s[a];
		if (x * a >= MAXM)
		{
			cnt += a;
			continue;
		}
		while (_a--)
		{
			cnt++;
			x++;
			while (c[x * a])
			{
				x++;
				if (x * a >= MAXM)
				{
					cnt += _a;
					goto end;
				}
			}
			c[x * a] = true;
			if (x * a < MAXM)
			{
				if (b[x * a])
				{
					g.push_back(cnt);
					b[x * a] = false;
				}
			}
			else
			{
				cnt += _a;
				break;
			}
		}
	end:
		s[a] = x;
	}

	cout << g.size() << endl;
	// sort(g.begin(), g.end());
	for (auto i : g)
		cout << i << endl;
	return 0;
}