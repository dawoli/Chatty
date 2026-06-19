#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5010], ans, c[5010][5010];
void dfs(int pos, int sum, int mx, bool c, int ls, int lx){
	if (pos > n) return ;
	if (sum > mx * 2 && (sum != ls || mx != lx)){
		ans++;
		ans %= mod;
//		printf("%d %d %d %d\n", sum, mx, ls, lx);
	}
	
//	cout << pos << endl;
	dfs(pos + 1, sum + a[pos + 1], max(mx, a[pos + 1]), 1, sum, mx);
	dfs(pos + 1, sum, mx, 0, sum, mx);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	for (int i = 1; i <= 5000; i++)
		c[i][0] = c[i][i] = 1;
	c[1][1] = c[2][1] = 1;
	for (int i = 2; i <= 5000; i++)
		for (int j = 1; j < i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	cin >> n;
	int mx = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mx = max(mx, a[i]);
	if (mx == 1){
		for (int i = 3; i <= n; i++)
			ans += c[n][i];
	}
	else {
		dfs(1, a[1], a[1], 1, -1, -1);
		dfs(1, 0, 0, 0, -1, -1);
	}
	cout << ans << endl;
	return 0;
}

