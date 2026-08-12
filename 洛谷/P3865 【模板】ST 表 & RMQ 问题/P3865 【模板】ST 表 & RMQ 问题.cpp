// Problem URL: https://www.luogu.com.cn/problem/P3865
// Finish Time: 2026/7/18 18:35:37 AC
// Finish Time: 2026/7/18 18:25:18 WA
// Start Time: 2026/7/18 18:03:37

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 1e5 + 5;
const int		  logN = 16;

int f[logN + 1][MAXN], lg2[MAXN];

auto pre()
{
	lg2[1] = 0;
	for (int i = 2; i < MAXN; i++)
		lg2[i] = lg2[i / 2] + 1;
}

auto pow2(const int &x)
{
	return 1 << x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	pre();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> f[0][i];
	for (int j = 1; j <= logN; j++)
		for (int i = 1; i + pow2(j) - 1 <= n; i++)
			f[j][i] = max(f[j - 1][i], f[j - 1][i + pow2(j - 1)]);

	while (m--)
	{
		int l, r;
		cin >> l >> r;
		const int &k = lg2[r - l + 1];
		cout << max(f[k][l], f[k][r - pow2(k) + 1]) << endl;
	}
	return 0;
}