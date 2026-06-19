#include <bits/stdc++.h>
using namespace std;
const int R = 100010;

int cnt[R];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	int maxr = 0;
	for (int i = 1; i <= n; i++)
	{
		int r;
		cin >> r;
		cnt[r]++;
		maxr = max(maxr, r);
	}
	int last = 0, ans = n;
	for (int i = 1; i <= maxr; i++)
	{
		if (cnt[i] != 0)
		{
			ans -= min(last, cnt[i]);
			last = max(last, cnt[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
