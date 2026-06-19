#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200010;
ll T;
ll n, A[N];
ll c[30];
ll dp[2010][2010][2];
ll f[N][4];
bool vst[N];
ll ans;
void dfs(ll now) {
	if(now >= n + 1) {
		ll val = 0, x = 0, y = 0;
		for(ll i = 1; i <= n; i++) {
			if(c[i] == 0) {
				if(A[i] == x) val += A[i];
				x = A[i];
			} else {
				if(A[i] == y) val += A[i];
				y = A[i];
			}
		}
		ans = max(ans, val);
		return;
	}
	c[now] = 0;
	dfs(now + 1);
	c[now] = 1;
	dfs(now + 1);
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		for(ll i = 1; i <= n; i++) scanf("%lld", &A[i]);
		if(n <= 15) {
			ans = 0;
			dfs(1);
			printf("%lld\n", ans);
		}
		else if(n <= 2000){
			ans = 0;
			for(ll j = 0; j <= n; j++)
				dp[0][j][0] = dp[0][j][1] = 0;
			for(ll i = 1; i <= n; i++) {
				dp[i][i - 2][0] = dp[i][i - 2][1] = 0;
				for(ll j = 0; j <= i - 3; j++)
					dp[i][j][0] = dp[i - 1][j][0] + (A[i] == A[i - 1] ? A[i] : 0);
				for(ll k = 0; k <= i - 3; k++)
					dp[i][i - 2][0] = max(dp[i][i - 2][0], dp[i - 1][k][1] + (A[i] == A[i - 1] ? A[i] : 0));
				for(ll j = 0; j <= i - 3; j++)
					dp[i][j][1] = dp[i - 1][j][0] + (A[i] == A[j] ? A[i] : 0);
				for(ll k = 0; k <= i - 3; k++)
					dp[i][i - 2][1] = max(dp[i][i - 2][1], dp[i - 1][k][1] + (A[i] == A[i - 2] ? A[i] : 0));
			}
			for(ll j = 0; j <= n - 2; j++)
				ans = max(ans, max(dp[n][j][0], dp[n][j][1]));
			printf("%lld\n", ans);
		} else {
			ans = 0;
			memset(vst, 0, sizeof vst);
			f[0][0] = f[0][1] = f[0][2] = f[0][3] = 0;
			for(ll i = 1; i <= n; i++) {
				if(i >= 4) vst[A[i - 3]] = 1;
				f[i][0] = f[i][1] = f[0][2] = f[0][3] = 0;
				f[i][0] = max(f[i - 1][0], f[i - 1][2]) + (A[i] == A[i - 1] ? A[i] : 0);
				f[i][2] = max(f[i - 1][1], f[i - 1][3]) + (A[i] == A[i - 1] ? A[i] : 0);
				f[i][1] = max(f[i - 1][2] + (A[i] == A[i - 3] ? A[i] : 0), f[i - 1][0] + vst[A[i]] ? A[i] : 0);
				f[i][3] = max(f[i - 1][1], f[i - 1][3]) + (A[i] == A[i - 2] ? A[i] : 0);
			}
			ans = max(max(f[n][0], f[n][1]), max(f[n][2], f[n][3]));
			printf("%lld\n", ans);
		}
	}
	return 0;
}
