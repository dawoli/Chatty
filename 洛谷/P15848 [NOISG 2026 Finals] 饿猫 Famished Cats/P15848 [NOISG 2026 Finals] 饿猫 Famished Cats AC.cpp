// Problem URL: https://www.luogu.com.cn/problem/P15848 [NOISG 2026 Finals] 饿猫 / Famished Cats
// Finish Time: 2026/10/24 12:48:34 AC
// Finish Time: 2026/10/22 21:43:25 WA 7pts
// Finish Time: 2026/10/21 21:31:57 WA
// Start Time: 2026/10/21 17:04:53

#include <bits/stdc++.h>
#define int ll
#define endl '\n'
#define opp(i) (n - (i) + 1)
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 5e5 + 5;

int					n, x, d[MAXN], f[MAXN];
int					tf[MAXN], pf[MAXN], pd[MAXN], fu, exs = 0;
int					ans = 0, s = 0;
priority_queue<pii> q;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
		pd[i] = pd[i - 1] + d[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i];
		pf[i] = pf[i - 1] + f[i];
		tf[i] = f[i];
	}
	for (int i = 1; i <= n / 2; i++)
		if (tf[i] < tf[opp(i)])
			swap(tf[i], tf[opp(i)]);
	fu = x;
	for (int i = 1; i <= n; i++)
	{
		x -= d[i];
		if (x < 0)
			break;
		x += tf[i];
		ans++;
	}
	cout << ans << " ";
	x = fu;
	for (int i = 1; i <= min(ans, n / 2); i++)
	{
		x -= d[i];
		while (x < 0 && !q.empty())
		{
			x += q.top().first;
			exs += q.top().first;
			swap(f[-q.top().second], f[opp(-q.top().second)]);
			q.pop();
			s++;
		}
		if (f[i] < f[opp(i)])
			q.push({f[opp(i)] - f[i], -i});
		x += f[i];
		while (opp(i) <= ans && pf[opp(i) - 1] + fu + exs < pd[opp(i)] && !q.empty())
		{
			x += q.top().first;
			exs += q.top().first;
			swap(f[-q.top().second], f[opp(-q.top().second)]);
			q.pop();
			s++;
		}
	}
	cout << s << endl;
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：取堆顶补油后忘记 q.pop()，同一对会被反复 swap（换两次等于没换），次数和收益都虚增；
 *   油暂时为负不代表到不了，不要回滚已做的交换或提前 break。
 * - 关键结论/技巧：每对对称位只能互换且两侧燃料总量不变，把大的放近端可求 D；
 *   一次交换等价于对 b[p+1..n-p+1] 区间加收益，用前缀和 + 累计收益 exs 判远端可达性。
 * - 复杂度：O(n log n)
 */