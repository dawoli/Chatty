#include <bits/stdc++.h>
using namespace std;

int T, n, ans, col[20], A[200005]; 

int calc()
{
	int sum = 0, last[3];
	last[0] = last[1] = last[2] = 0;
	for (int i = 1; i <= n; i++)
	{
		int now = col[i];
		if (A[last[now]] == A[i])	sum += A[i];
		last[now] = i;
	}
	return sum;
}

void dfs(int step)
{
	if (step > n)
	{
		ans = max(ans, calc());
		return;
	}
	col[step] = 0;
	dfs(step + 1);
	col[step] = 1;
	dfs(step + 1); 
}

void solve1()// 20pts
{
	dfs(1);
	cout << ans << endl;
	ans = 0;
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	if (n <= 15)	solve1();
}

int main()
{
	freopen ("color.in", "r", stdin);
	freopen ("color.out", "w", stdout);
	cin >> T;
	while (T--)	solve();
	return 0;
}

// 1. 14:48 : 通过所有 n <= 15 样例 -> 20pts
