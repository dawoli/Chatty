// Problem URL: https://www.luogu.com.cn/problem/P3855
// Finish Time: 2026/10/4 17:41:17 AC
// Finish Time: 2026/10/4 17:39:15 WA 90pts
// Finish Time: 2026/10/4 17:19:11 MLE 40pts
// Start Time: 2026/10/4 16:27:34

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 3e1 + 1;

int	 n, m;
pii	 s1, s2, t;
char a[MAXN][MAXN];
pii	 dir[4][2] =
	{
		{{1, 0}, {1, 0}},
		{{-1, 0}, {-1, 0}},
		{{0, -1}, {0, 1}},
		{{0, 1}, {0, -1}}};

struct Hash
{
	size_t operator()(const pair<pii, pii> &p) const
	{
		size_t h = 0;
		h		 = h * 31 + p.first.first;
		h		 = h * 31 + p.first.second;
		h		 = h * 31 + p.second.first;
		h		 = h * 31 + p.second.second;
		return h;
	}
};

unordered_set<pair<pii, pii>, Hash> s;

int dis(pii p, pii t)
{
	return abs(p.first - t.first) + abs(p.second - t.second);
}

char read(pii x)
{
	return a[x.first][x.second];
}

struct state
{
	int r;
	pii p1, p2;
	int pre;
	state() = default;
	state(int r, pii p1, pii p2):
		r(r), p1(p1), p2(p2)
	{
		pre = r + max(dis(p1, t), dis(p2, t));
	}
	bool operator<(const state &other) const
	{
		return pre > other.pre;
	}
};

priority_queue<state> q;

int Astar(state x)
{
	q.push(x);
	while (!q.empty())
	{
		const auto x = q.top();
		q.pop();
		if (s.find({x.p1, x.p2}) != s.end())
			continue;
		s.insert({x.p1, x.p2});
		if (x.p1 == x.p2 && x.p1 == t)
			return x.r;
		for (const auto &y : dir)
		{
			pii nx = {x.p1.first + y[0].first, x.p1.second + y[0].second};
			pii ny = {x.p2.first + y[1].first, x.p2.second + y[1].second};
			if (read(nx) == '#')
				nx = x.p1;
			else if (read(nx) == 'X')
				continue;
			if (read(ny) == '#')
				ny = x.p2;
			else if (read(ny) == 'X')
				continue;
			q.push({x.r + 1, nx, ny});
		}
	}
	return -1;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			switch (a[i][j])
			{
			case 'G':
				s1 = {i, j};
				break;
			case 'M':
				s2 = {i, j};
				break;
			case 'T':
				t = {i, j};
			}
		}
	int ans = Astar({0, s1, s2});
	if (ans == -1)
		cout << "no" << endl;
	else
		cout << ans << endl;
	return 0;
}