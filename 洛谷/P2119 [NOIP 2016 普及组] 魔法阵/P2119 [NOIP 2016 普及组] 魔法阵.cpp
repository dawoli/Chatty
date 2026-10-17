// Problem URL: https://www.luogu.com.cn/problem/P2119 [NOIP 2016 普及组] 魔法阵
// Finish Time: 2026/10/7 14:58:07 TLE 60pts
// Start Time: 2026/10/7 14:44:46

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXM = 4e4 + 4;

int n, m, ans[MAXM][5];
struct node
{
	int id, v;
} x[MAXM];

bool operator<(const node &x, const node &y)
{
	return x.v < y.v;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> x[i].v;
		x[i].id = i;
	}
	sort(x + 1, x + m + 1);
	for (int a = 1; a <= m; a++)
	{
		for (int b = a + 1; b <= m; b++)
		{
			if (x[b].v == a[x].v)
				continue;
			for (int c = b + 1; c <= m; c++)
			{
				if (x[c].v == x[b].v)
					continue;
				for (int d = c + 1; d <= m; d++)
				{
					if (x[d].v == x[c].v)
						continue;
					if (x[b].v - x[a].v == (x[d].v - x[c].v) * 2 && (x[b].v - x[a].v) * 3 < (x[c].v - x[b].v))
						ans[x[a].id][1]++, ans[x[b].id][2]++, ans[x[c].id][3]++, ans[x[d].id][4]++;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i][1] << " "
			 << ans[i][2] << " "
			 << ans[i][3] << " "
			 << ans[i][4] << endl;
	}
	return 0;
}