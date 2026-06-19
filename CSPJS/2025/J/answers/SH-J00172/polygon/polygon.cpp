#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int P = 998244353;
const int N = 5005;
LL a[N], n, ans[N], cnt;

void dfs(int step, int mx, int sum)
{
	if (step >= mx)
	{
		if (sum > a[mx]) ans[mx] = (ans[mx] + 1) % P;
		return;
	}
	dfs(step+1, mx, sum+a[step]);
	dfs(step+1, mx, sum);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a+1, a+n+1);
	if (n < 3)
	{
		cout << 0 << endl;
		return 0;
	}
	if (n == 3)
	{
		if (a[1] + a[2] > a[3]) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	for (int i = 3; i <= n; i++)
	{
		dfs(1, i, 0);
		cnt = (cnt + ans[i]) % P;
	}
	cout << cnt << endl;
	return 0;
}
