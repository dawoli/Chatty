// Problem URL: https://www.luogu.com.cn/problem/P12225
// Finish Time: 2026/10/2 12:32:58 TLE 65pts
// Finish Time: 2026/10/2 12:30:33 TLE/RE 65pts
// Start Time: 2026/10/2 12:10:38

#include <bits/stdc++.h>
#define int int
#define endl '\n'
#define MAX 0
#define MIN 1
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
const int			   MAXN = 1e5 + 5;

int		   n, k, a;
ll		   mxs, mns;
double	   ans2;
deque<pii> mx, mn;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (!mx.empty() && mx.front().second < i - k + 1)
			mx.pop_front();
		if (!mn.empty() && mn.front().second < i - k + 1)
			mn.pop_front();
		while (!mx.empty() && mx.back().first <= a)
			mx.pop_back();
		mx.push_back({a, i});
		while (!mn.empty() && mn.back().first >= a)
			mn.pop_back();
		mn.push_back({a, i});
		if (i >= k)
			mxs += mx.front().first, mns += mn.front().first;
	}
	ans2 = (double)(mxs - mns) / (n - k + 1);
	cout << fixed << setprecision(2) << ans2 << endl;
	return 0;
}

/*
 * 经验总结：
 * - 两人独立等概率选择窗口，利用期望线性性，答案等于所有窗口最大值之和减去最小值之和，再除以窗口数。
 * - 用两个单调队列分别维护当前窗口最大值和最小值；队首越界时删除，队尾被新元素支配时删除。
 * - 容易错的地方：若枚举两人选择的窗口组合，会达到 O((N-K+1)^2)；化简后只需分别统计两组窗口极值。
 * - 关键结论/技巧：设窗口数 M=N-K+1，则 E[max(X)-min(Y)]=(sum(max)-sum(min))/M。
 * - 复杂度：时间 O(N)，空间 O(K)。
 */