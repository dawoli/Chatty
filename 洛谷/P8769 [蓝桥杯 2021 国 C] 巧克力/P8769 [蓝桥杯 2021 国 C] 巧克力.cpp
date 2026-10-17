// Problem URL: https://www.luogu.com.cn/problem/P8769 [蓝桥杯 2021 国 C] 巧克力
// Finish Time: 2026/10/11 21:33:22 AC
// Start Time: 2026/10/11 20:57:55

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 1e5 + 5;

struct node
{
	int	 a, b, c;
	bool operator<(const node &B) const
	{
		if (a == B.a)
		{
			return b > B.b;
		}
		return a > B.a;
	}
} w[100010];

bool cmp(node a, node b)
{
	return a.b < b.b;
}

int					 n, x, ans, mx = INT_MIN;
priority_queue<node> q;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> x >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i].a >> w[i].b >> w[i].c;
		mx = max(mx, w[i].b);
	}
	if (mx < x)
	{
		cout << "-1" << endl;
		return 0;
	}
	sort(w + 1, w + 1 + n, cmp);
	int top = n;
	for (int i = x; i != 0; i--)
	{
		while (w[top].b >= i)
		{
			q.push(w[top--]);
		}
		if (q.empty())
		{
			cout << -1 << endl;
			return 0;
		}
		ans += q.top().a;
		auto tmp = q.top();
		q.pop();
		tmp.c--;
		if (tmp.c == 0)
			continue;
		q.push(tmp);
	}
	cout << ans << endl;
	return 0;
}