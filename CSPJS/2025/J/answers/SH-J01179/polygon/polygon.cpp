#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MOD = 998244353;
int n;
ll a[5010];
ll ans=0;

void dfs(int x, ll nowsum=0, ll nowmax = 0) {
	if (x==n+1) {
		if (nowsum > 2 * nowmax) ans=(ans+1) % MOD;	
		return;
	}
	dfs(x+1, nowsum+a[x], max(nowmax,a[x]));
	dfs(x+1, nowsum, nowmax);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	ll sm=0, mmx = 0;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]), sm+=a[i], mmx = max(mmx, a[i]);
	if (n<=20){
		dfs(1);
		printf("%lld\n", ans); // 保分 
		return 0;
	}
	vector<vector<vector<int>>> dp(n+5, vector<vector<int>>(sm+5, vector<int>(mmx+5)));
	dp[n][0][0]=1;
	dp[n][a[n]][a[n]]=1; 
	for (int i=n;i;i--) {
		for (ll nsum=sm;~nsum;nsum--) {
			for (ll nmax=mmx;~nmax;nmax--) {
				dp[i][nsum][nmax] += dp[i+1][nsum][nmax];
				if (nsum + a[i] <= sm) dp[i][nsum+a[i]][max(nmax, a[i])] += dp[i+1][nsum][nmax];
			}
		}
	}
	// for (int i=1;i<=sm;i++) for (int j=1;j<=mmx;j++) cout<<dp[1][i][j]<<" \n"[j==mmx];
	// for (int i=1;i<=sm;i++) {for (int j=1;j<=mmx;j++) {if (i>2*j)cout<<dp[1][i][j]<<" ";} cout<<endl;}
	for (int i=1;i<=sm;i++) {for (int j=1;j<=mmx;j++) {if (i>2*j)ans+=dp[1][i][j];} /*cout<<endl;*/}//2023 CSP-J T1 血淋淋的教训 
	printf("%lld\n", ans);
	return 0;
}
