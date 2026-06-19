#include <bits/stdc++.h>
using namespace std;
int n, a[100005], m, ans, p;
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1])
		{
			ans = max(ans - m, 0);
			ans += m;
			m = 1;
		}
		else
		{
			m++;
		}
	}
	cout << max(ans - m, 0) + m;
}
