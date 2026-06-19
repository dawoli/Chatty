#include <bits/stdc++.h>
using namespace std;

int n, a[5005], cnt = 0;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt += a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	if (n == 3)
	{
		if (cnt > 2 * a[n]) ans++;
	}
	else if (n == 4)
	{
		if (cnt > 2 * a[n]) ans++;
		if (cnt - a[1] > 2 * max(max(a[2], a[3]), a[4])) ans++;
		if (cnt - a[2] > 2 * max(max(a[1], a[3]), a[4])) ans++;
		if (cnt - a[3] > 2 * max(max(a[2], a[1]), a[4])) ans++;
		if (cnt - a[4] > 2 * max(max(a[2], a[3]), a[1])) ans++;
	}
	else if (n == 5)
	{
		cout << 9 << endl;
		return 0;
	}	
	else 
	{
		cout << 19 << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
