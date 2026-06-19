#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, k, q, l[N], r, c;
vector<int> s[N]; 
bool flag;
void dfs(int x, int num, int cnt)
{
	if (flag)
		return;
	if (cnt == r)
	{
		if (num == c)
			flag = 1;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (x == i)
			continue;
		for (int j = 1; j <= l[i]; j++)
			if (s[i][j] == num)
				for (int o = j + 1; o <= l[i] && o - j < k; o++)
					dfs(i, s[i][o], cnt + 1);
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++)
		{
			cin >> l[i];
			s[i].resize(l[i] + 1);
			for (int j = 1; j <= l[i]; j++)
				cin >> s[i][j];
		}
		while (q--)
		{
			cin >> r >> c;
			flag = 0;
			for (int i = 1; i <= n; i ++)
				dfs(i, 1, 0);
			cout << flag << "\n";
		}
	}
}
