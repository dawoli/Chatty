// Problem URL: https://www.luogu.com.cn/contest/327733
// Start Time: 2026/8/14 13:00:45

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;

int n;
int ans[6] = {0, 0, 0, 1, 2, 4};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cout << ans[n] << endl;
	return 0;
}