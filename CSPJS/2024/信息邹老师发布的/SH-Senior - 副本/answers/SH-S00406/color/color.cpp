#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int n , a[200005] , last[1000005];
ll maxn;
bool c[200005];
void dfs(int id)
{
	if (id == n + 1)
	{
		memset(last , -1 , sizeof(last));
		ll sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (last[c[i]] != -1 && a[last[c[i]]] == a[i]) sum += a[i];
			last[c[i]] = i;
		}
		maxn = max(maxn , sum);
		return;
	}
	if (a[id] == a[id - 1])
	{
		c[id] = c[id - 1];
		dfs(id + 1);
		return;
	}
	c[id] = 0;
	dfs(id + 1);
	c[id] = 1;
	dfs(id + 1);
}
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	c[1] = 0;
	maxn = 0;
	dfs(2);
	cout << maxn << endl;
}
int main()
{
	freopen("color.in" , "r" , stdin);
	freopen("color.out" , "w" , stdout);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
