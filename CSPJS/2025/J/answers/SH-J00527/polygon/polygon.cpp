#include <bits/stdc++.h>
using namespace std; 
int n, ans, maxn;
int a[10005];
void dfs(int n, int sum, int num, int k, int maxn) {
	if(n == k) {
		if(num <= 1) return ;
		if(sum > maxn) ans++;
		return ;
	}
	dfs(n+1, sum, num, k, maxn);
	dfs(n+1, sum+a[n], num+1, k, maxn);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if(maxn == 1) {
		ans = 1;
		for(int i = 1; i <= n; i++) ans = ans * 2 % 998244353;
		ans = ans-1-n-n*(n-1)/2;
		cout << (ans + 998244353) % 998244353;
	}
	else {
		sort(a+1, a+n+1);
		for(int i = 3; i <= n; i++) {
			dfs(1, 0, 0, i, a[i]);
		}
		cout << ans % 998244353;
	}
	return 0;
}
