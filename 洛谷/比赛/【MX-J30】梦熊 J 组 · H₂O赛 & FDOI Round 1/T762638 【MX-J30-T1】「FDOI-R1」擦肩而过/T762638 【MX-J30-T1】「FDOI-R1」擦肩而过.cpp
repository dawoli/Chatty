// Problem URL: https://www.luogu.com.cn/problem/T762638?contestId=327902
// Start Time: 2026/5/30 11:09:05

#include <bits/stdc++.h>
#define int long long
using namespace std;
int x, a, b, t;
void Main()
{
	cin >> x >> a >> b >> t;
	int ans = 0;
	if(a + b == 0)
	{
		cout << 0 << '\n';
		return;
	}
	int c1, c2;
	c1 = (x - t) / (a + b);
	c2 = (x + t) / (a + b);
	if(c1 >= 0)
		ans++;
	if(c2 >= 0 && c2 != c1)
		ans++;
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--)
	{
		Main();
	}
	return 0;
}