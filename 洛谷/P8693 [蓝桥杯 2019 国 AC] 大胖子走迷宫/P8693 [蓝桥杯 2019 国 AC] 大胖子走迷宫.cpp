// Problem URL: https://www.luogu.com.cn/problem/P8693
// Finish Time: 2026/9/8 16:44:38 MLE 19pts
// Finish Time: 2026/9/8 16:37:04 TLE/MLE 9pts
// Start Time: 2026/9/7 16:37:58

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
const int			   MAXN = 3e2 + 2;

int					 n, k;
vector<vector<char>> a;
pii					 dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dis(int x, int y)
{
	return n - 2 - x + n - 2 - y;
}

struct node
{
	int x, y, d;
	int pior;
	node() = default;
	node(int __x, int __y, int __d): x(__x), y(__y), d(__d)
	{
		pior = dis(__x, __y) + d;
	}
};

bool operator<(const node &__a, const node &__b)
{
	return __a.pior > __b.pior;
}

bool test(int x, int y, int sz)
{
	const int r = sz / 2;
	for (int i = x - r; i <= x + r; i++)
	{
		if (i < 1 || i > n)
			return false;
		for (int j = y - r; j <= y + r; j++)
		{
			if (j < 1 || j > n)
				return false;
			if (a[i][j] == '*')
				return false;
		}
	}
	return true;
}

int Astar()
{
	priority_queue<node> q;
	q.push({3, 3, 0});
	while (!q.empty())
	{
		auto tmp = q.top();
		q.pop();
		// cout << tmp.x << " " << tmp.y << " " << tmp.d << endl;
		if (tmp.x == n - 2 && tmp.y == n - 2)
		{
			return tmp.d;
		}
		int sz = 5;
		if (tmp.d >= k)
			sz = 3;
		if (tmp.d >= 2 * k)
			sz = 1;
		for (int i = 0; i < 4; i++)
		{
			int x1 = tmp.x + dir[i].first;
			int y1 = tmp.y + dir[i].second;
			if (test(x1, y1, sz))
			{
				q.push({x1, y1, tmp.d + 1});
			}
		}
		if (sz != 1)
			q.push({tmp.x, tmp.y, tmp.d + 1});
	}
	return -1;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	a.resize(n + 1, vector<char>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	cout << Astar() << endl;
	return 0;
}
// 制作一个名为“踩蟑螂&摘葡萄”的单文件HTML游戏，“踩蟑螂”类似打地鼠，玩家需要用鞋底拍死出现的蟑螂，“采葡萄“则是玩家用竹筐需要接住快速下落的葡萄，进入后是一个票提，点击下面的开始按钮后选择难度，然后