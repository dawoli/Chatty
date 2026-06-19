#include <iostream> 
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int a[N], n, ans = 0;

void dfs(int x, int lr, int lb, int sum)
{
	if (x > n)
	{
		ans = max(ans, sum);
		return;
	}
	if (lr != 0 && a[lr] == a[x]) dfs(x + 1, x, lb, sum + a[x]);
	else dfs(x + 1, x, lb, sum);
	if (lb != 0 && a[lb] == a[x]) dfs(x + 1, lr, x, sum + a[x]);
	else dfs(x + 1, lr, x, sum);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		dfs(1, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
