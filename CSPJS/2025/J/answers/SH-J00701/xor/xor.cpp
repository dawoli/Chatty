#include <bits/stdc++.h>
using namespace std;

int a[500010], b[500010], e[500010];
//230138

int check (int i, int j)
{
	int ans = a[i];
	for (int l = i + 1; l <= j; l++)
	{
		ans ^= a[l];
	}
	return ans;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cur = 0, cnt = 0;
	cin >> n >> k;
	bool f = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 1) cnt++;
		if (a[i] != 1 && a[i] != 0) f = 0;
	}
	if (f == 1)
	{
		cout << cnt;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (check(i, j) == k)
			{
				cur++;
				b[cur] = i;
				e[cur] = j;
				//cout << i << " " << j << endl;
				break;
			}
		}
	}
	int last = 0, ans = 0;
	for (int i = 1; i <= cur; i++)
	{
		if (b[i] > last)
		{
			ans++;
			last = e[i];
		}
	}
	cout << ans << endl;
	return 0;
}
