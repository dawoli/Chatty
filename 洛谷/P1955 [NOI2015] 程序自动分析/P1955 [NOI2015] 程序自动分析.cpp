// Problem URL: https://www.luogu.com.cn/problem/P1955
// Finish Time: 2026/7/14 13:24:26 AC
// Start Time: 2026/7/14 13:03:55

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long	 ll;
typedef unsigned int uint;

const int				  MAXIJ = 1e9 + 9;
int						  n;
unordered_map<uint, uint> fa;

uint find(const uint &x)
{
	if (!fa.count(x))
		fa[x] = x;
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

auto merge(const uint &x, const uint &y)
{
	uint fx = find(x), fy = find(y);
	if (fx == fy)
		return false;
	fa[fx] = fy;
	return true;
}

auto solve()
{
	cin >> n;
	vector<pair<uint, uint>> ueq;
	fa.clear();
	for (int i = 1; i <= n; i++)
	{
		uint x, y, e;
		cin >> x >> y >> e;
		if (e)
			merge(x, y);
		else
			ueq.push_back({x, y});
	}
	for (auto &p : ueq)
	{
		const uint &x = p.first, &y = p.second;
		if (find(x) == find(y))
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}