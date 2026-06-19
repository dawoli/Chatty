#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, a[5010], ans, c[5010][5010];
bool flag = true;

void dfs(int step, int maxn, int sum){
	if (step > n){
		if (sum > 2*maxn)
			ans++;
		ans %= mod;
		return;
	}
	dfs(step+1, maxn, sum);
	dfs(step+1, max(maxn, a[step]), sum+a[step]);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != 1)
			flag = false;
	}
	if (n <= 20){
		dfs(1, 0, 0);
		cout << ans << endl;
	} else if (flag){
		c[1][1] = 1;
		for (int i = 2; i <= n; i++){
			for (int j = 1; j <= i; j++){
				c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
			}
		}
		for (int i = 3; i <= n; i++){
			ans = (ans+c[n][i])%mod;
		}
		cout << ans << endl;
	}
	return 0;
}
