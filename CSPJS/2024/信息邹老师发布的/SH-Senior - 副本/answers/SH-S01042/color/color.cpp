#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 102;
int T;
int n, a[N]; 
int dp[N][N][N];
/*
dp i j k表示i号结尾颜色为0，且最后一位颜色为1的编号为j，且倒数第二颜色为0 
*/

void test() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++)	{
		for(int j=0; j<=i-2; j++) for(int k=0; k<=j-1; k++) {
			dp[i][j][k] = dp[i-1][j][k] + (a[i] == a[i-1]) * a[i];
		}
		int j = i-1;
		for(int k=0; k<=j-1; k++) {
			dp[i][j][k] = 0;
			for(int t=0; t<=k-1; t++) 
				dp[i][j][k] = max(dp[i][j][k], dp[j][k][t] + (a[i] == a[k]) * a[i]);
		}
	}
//	for(int i=1; i<=n; i++) for(int j=1; j<=i-1; j++) for(int k=0; k<=j-1; k++) cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
	int ans = 0;
	for(int j=0; j<=n-1; j++) for(int k=0; k<=j-1; k++) ans = max(ans, dp[n][j][k]);
	cout << ans << endl;
}

signed main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while(T--) test();
	return 0;
}

