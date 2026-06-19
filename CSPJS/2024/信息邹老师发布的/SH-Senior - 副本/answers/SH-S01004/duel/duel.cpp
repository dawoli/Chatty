#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, tmp = 0;
int a[N] = {};
int b[N] = {};
int c[N] = {};
int h = 1, t = 1, fh = -1;
int ans = 0;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	while (true)
	{
		if (t < n)
		{
			t++;
			while (t < n && b[t] != 0)
				t++;
			if (a[h] < a[t] && (b[h] == 0 || b[h] == 1) && b[t] == 0)
			{
				b[h] = 2;
				b[t] = 1;
				h++;
			}
		}
		else if (h < t - 1)
		{
			if (fh == h)
				break;
			else
			{
				fh = h;
				t = h;
			}
		}
		else
			break;
	}
	for (int i = 1; i <= n; i++)
	{
		if (b[i] == 0)
			tmp++;
	}
	ans += tmp;
	for (int i = 1; i <= n; i++)
	{
		if (b[i] == 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
