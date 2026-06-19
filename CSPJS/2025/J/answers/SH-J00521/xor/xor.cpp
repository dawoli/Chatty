#include <bits/stdc++.h>
using namespace std;
int a[500005];
int dp[500005];
struct edge
{
	int l, r;
} e[500005];
int get_xor(int l, int r)
{
	return dp[r] ^ dp[l - 1];
}
int get_highest_xor_p(int k, int ind)
{
	for (int i = ind; i >= 1; i--)
	{
		if (get_xor(i, ind) == k)
			return i;
	}
	return -1;
}
bool cmp(edge a, edge b)
{
	return a.r < b.r;
}
int index_p = 0;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i] = dp[i - 1] ^ a[i];
	}
	for (int i = n; i >= 1; i--)
	{
		int p = get_highest_xor_p(k, i);
		if (p == -1)
			continue;
		index_p++;
		e[index_p].l = p;
		e[index_p].r = i;
	}
	sort(e + 1, e + index_p + 1, cmp);
	int now_r = 0;
	long long ans = 0;
	for (int i = 1; i <= index_p; i++)
	{
		if (e[i].l > now_r)
		{
			ans++;
			now_r = e[i].r;
		}
	}
	cout << ans;
	return 0;
} 
