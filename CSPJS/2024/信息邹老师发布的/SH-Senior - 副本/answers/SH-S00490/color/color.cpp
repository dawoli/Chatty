#include <bits/stdc++.h>
using namespace std;
int t, a[200005], ans, n;
void dfs(int pos, int curl, int curr, int sum)
{
	if(pos == n+1)
	{
		ans = max(ans, sum);
		return ;
	}
	dfs(pos+1, pos, curr, (a[curl] == a[pos])*a[pos]+sum);
	dfs(pos+1, curl, pos, (a[curr] == a[pos])*a[pos]+sum);
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		memset(a, 0, sizeof(a));
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n; i++) cin >> a[i];
		dfs(1,0,0,0);
		cout << ans;
	}
	return 0;
}
