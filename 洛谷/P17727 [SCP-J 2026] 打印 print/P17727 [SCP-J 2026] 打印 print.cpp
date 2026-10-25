// Problem URL: https://www.luogu.com.cn/problem/P17727 [SCP-J 2026] 打印 / print
// Finish Time: 2026/10/20 16:34:01 AC
// Start Time: 2026/10/20 16:27:34

#include <bits/stdc++.h>
#define int ll
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;

int n, m;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	n = (n + 1) / 2, m = (m + 1) / 2;
	if (m * 2 - 1 == n)
		cout << 0;
	else if (m * 2 <= n)
		cout << m;
	else
		cout << n - m + 1;
	return 0;
}

/*
 * 经验总结：
 * - 容易错的地方：n 是面数，A4 张数是 (n+1)/2；中间单张的判据是 2*p-1==k，不是 p==k/2+1。
 * - 关键结论/技巧：先把面号换算成 A4 张号，再分前半 / 后半 / 中位三种情况。
 * - 复杂度：O(1)
 */