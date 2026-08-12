// Problem URL: https://www.luogu.com.cn/problem/P1966
// Finish Time: 2026/7/28 21:32:53 AC
// Start Time: 2026/7/28 20:56:56

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define ll long long

const int mod = 1e8 - 3;
int		  n, t[200005], q[100005];
int		  num[100005], idx[100005], num2[100005], idx2[100005];
ll		  ans;

auto lowbit(const int &x)
{
	return x & -x;
}

auto add(int x)
{
	while (x <= n)
	{
		t[x]++;
		t[x] %= mod;
		x += lowbit(x);
	}
}

auto sum(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += t[x];
		if (ret > mod)
			ret -= mod;
		x -= lowbit(x);
	}
	return ret % mod;
}

auto cmp(int x, int y)
{
	return num[x] < num[y];
}

auto cmp2(int x, int y)
{
	return num2[x] < num2[y];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i], idx[i] = i;
	for (int i = 1; i <= n; i++)
		cin >> num2[i], idx2[i] = i;

	sort(idx + 1, idx + 1 + n, cmp);
	sort(idx2 + 1, idx2 + 1 + n, cmp2);

	for (int i = 1; i <= n; i++)
		q[idx[i]] = idx2[i];
	for (int i = n; i >= 1; i--)
	{
		add(q[i]);
		ans = (ans + sum(q[i] - 1)) % mod;
	}
	cout << ans % mod << endl;
	return 0;
}