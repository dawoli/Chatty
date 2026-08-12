// Problem URL: https://www.luogu.com.cn/contest/325521
// Finish Time: 2026/8/3 09:35:07 AC
// Finish Time: 2026/8/2 11:36:27 WA 92pts
// Finish Time: 2026/8/2 11:21:29 WA 20pts
// Finish Time: 2026/8/1 15:55:38 WA 16pts
// Finish Time: 2026/8/1 15:33:58 WA 16pts
// Start Time: 2026/8/1 14:03:27

#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAXN = 1e5 + 5;

int			 n, d[MAXN], ans = 0;
bitset<MAXN> t;

bool equal(const double &a, const double &b)
{
	return fabs(a - b) < 1e-6;
}

auto &pre(int x)
{
	return d[x - 1];
}

auto &nxt(int x)
{
	return d[x];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++)
	{
		bool in;
		cin >> in;
		t[i] = in;
	}

	int len = 0;
	for (int i = 1; i <= n; i++)
	{
		if (t[i])
			len++;
		else if (len)
		{
			vector<int> pos;
			int			sum = pre(i - len);
			pos.push_back(sum);
			for (int j = i - len; j < i; j++)
			{
				sum += nxt(j);
				pos.push_back(*(--pos.end()) + nxt(j));
			}
			auto it	 = pos.begin();
			int	 cnt = 1;
			for (int j = i - len; j < i; j++)
			{
				if (!(sum * cnt / (len + 1) == *it && sum * cnt % (len + 1) == 0))
					ans++;
				it++;
				cnt++;
			}
			// cout << "len: " << len << ", sum: " << sum << ", ans: " << ans << endl;
			// for (auto &x : pos)
			// 	cout << x << " ";
			// cout << (double)sum / (len + 1) << endl;
			len = 0;
		}
	}

	cout << ans;
	return 0;
}