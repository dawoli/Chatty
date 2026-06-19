#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, a[5010], ans;
void work1() {
	ans = 1;
	for(int i = 1; i <= n; i++) ans = ans * 2 % mod;
	ans = (ans - n * (n - 1) / 2 % mod + mod) % mod;
	ans = (ans - n + mod) % mod;
	ans = (ans - 1 + mod) % mod;
	cout << ans << "\n";
}
void dfs(int x, int sum, int maxx, int num) {
	if(x > n) {
		if(sum > 2 * maxx && num >= 3) ans++;
		return ;
	}
	//if(num + n - x < 2) return ;
	dfs(x + 1, sum + a[x], a[x], num + 1);
	dfs(x + 1, sum, maxx, num);
}
void work2() {
	dfs(1, 0, 0, 0);
	cout << ans << "\n";
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(a[n] == 1) work1();
	else work2();
	return 0;
}
