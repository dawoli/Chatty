#include<iostream>
using namespace std;
typedef long long ll;
const int x[7] = {0 , 1 , 2 , 4 , 6 , 7 , 8} , y[7] = {6 , 2 , 5 , 4 , 6 , 3 , 7};
ll minn;
void dfs(int n , ll ans)
{
	if (ans < 0) return;
	if (!n)
	{
		if (minn == -1 || minn > ans) minn = ans;
		return;
	}
	if (n >= y[0] && ans) dfs(n - y[0] , ans * 10);
	for (int i = 1; i < 7; i++)
		if (n >= y[i] && ans % 10 <= x[i]) dfs(n - y[i] , ans * 10 + x[i]);
}
void solve()
{
	int n; cin >> n;
	if (!(n % 7))
		for (int i = 1; i <= n / 7; i++) cout << 8;
	else if (n % 7 == 1 && n > 1)
	{
		cout << "10";
		for (int i = 1; i <= n / 7 - 1; i++) cout << 8;
	}
	else if (n <= 50)
	{
		minn = -1;
		dfs(n , 0);
		cout << minn;
	}
	else
	{
		int cnt = 0;
		while (n > 50)
		{
			n -= 7;
			cnt ++;
		}
		minn = -1;
		dfs(n , 0);
		cout << minn;
		for (int i = 1; i <= cnt; i++) cout << 8;
	}
	cout << endl;
}
int main()
{
	freopen("sticks.in" , "r" , stdin);
	freopen("sticks.out" , "w" , stdout);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
