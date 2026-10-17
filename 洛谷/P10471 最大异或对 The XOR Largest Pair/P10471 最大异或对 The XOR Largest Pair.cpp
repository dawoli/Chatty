// Problem URL: https://www.luogu.com.cn/problem/problem/P10471 最大异或对 The XOR Largest Pair
// Finish Time: 2026/10/11 17:40:05 AC
// Start Time: 2026/10/11 16:50:18

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   N = 10000010;

int n, A[N];
int son[N][2], idx, ans;

void insert(int x)
{
	int p = 0;
	for (int i = 31; i >= 0; --i)
	{
		int k = (x >> i) & 1;
		if (!son[p][k])
			son[p][k] = ++idx;
		p = son[p][k];
	}
}

int query(int x)
{
	int p = 0, ans = 0;
	for (int i = 31; i >= 0; --i)
	{
		int k = (x >> i) & 1;
		if (!son[p][k ^ 1])
			p = son[p][k];
		else
			p = son[p][k ^ 1], ans ^= (1 << i);
	}
	return ans;
}

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
		insert(A[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		ans = max(ans, query(A[i]));
	}
	cout << ans;
	return 0;
}