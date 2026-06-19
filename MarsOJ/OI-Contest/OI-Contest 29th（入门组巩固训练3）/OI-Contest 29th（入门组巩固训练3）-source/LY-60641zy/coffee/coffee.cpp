#include <bits/stdc++.h>
using namespace std;
int a[8], n, m, ans, t, sum;
string s;
int main()
{
	freopen("coffee.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--)
	{
		sum = ans = 0;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= 5; i++)
		{
			int cnt = 0;
			for (int j = 1; j <= 8; j++)
			{
				cin >> s;
				if(s == "math") cnt++;
			}
			a[i] = cnt;
			sum += cnt;
		}
		cin >> n >> m;
		for(int i = m; i <= 7; i++)
			ans += a[i];
		n = n - (7 - m + 1);
		ans += n / 7 * sum;
		n %= 7;
		for(int i = 1; i <= n; i++)
			ans += a[i];
		cout << ans << '\n';
	}
	return 0;
}
