#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3 + 3,mod = 998244353,Np = 5e6 + 3;
int n,a[N],s[N],ans;
int dp[3][Np],tp[N],C[N][N];
bool flagA = 1;
void taskA(){
	int ans = 0;
	C[1][1] = 1;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= i;j++){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if(i == n && j >= 3) ans += C[i][j];
		}
	}
	cout << ans;
	return;
}
void dfs(int u,int sum,int mx){
	if(u == n + 1){
		if(sum > 2*mx) ans++;
		ans %= mod;
		return;
	}
	dfs(u + 1,sum,mx);
	dfs(u + 1,sum + a[u],max(mx,a[u]));
	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);//Don't forget freopen(stdin)!
	freopen("polygon.out","w",stdout);//Don't forgrt freopen(stdout)!
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] > 1) flagA = 0;
	}
	if(flagA){
		taskA();
		return 0;
	}
//	sort(a + 1,a + n + 1);
//	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= s[n];j++){
//			dp[i & 1][j] = dp[(i - 1) & 1][j];
//			if(j > 2 * a[i] && i > 2)
//				dp[i & 1][j] += max(dp[(i - 1) & 1][j - a[i]],1ll);
//			dp[i & 1][j] %= mod;
////			cout << dp[i & 1][j] << ' ';
//		}
//		cout << endl;
//	}
////	int ans = 0;
//	for(int i = 1;i <= s[n];i++){
//		ans = (ans + dp[n & 1][i]) % mod;
//	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}

