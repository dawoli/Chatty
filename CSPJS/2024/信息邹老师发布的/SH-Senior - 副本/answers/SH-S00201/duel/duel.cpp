#include <iostream>
using namespace std;
const int N = 100005;
int n, ans, x, a[N];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> x;
		a[x] ++;
	}
	for (int i = 1; i < N;i ++)
	{
		ans = max(ans, a[i]);
	}
	cout << ans;
	return 0;
}
