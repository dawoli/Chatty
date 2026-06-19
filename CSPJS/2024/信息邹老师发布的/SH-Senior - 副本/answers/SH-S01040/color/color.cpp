#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 1;

int a[N], dp[N][N][N];

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
    	int n;
    	cin >> n;
    	for(int i = 1; i <= n; ++i) cin >> a[i];
    	memset(dp, -0x3f, sizeof dp);
    	dp[0][0][0] = 0;
    	int ans = 0;
    	for(int i = 1; i <= n; ++i) {
    		for(int lblue = 0; lblue <i ; ++lblue) {
    			for(int lred =0;lred<i;++lred) {
    				if(a[i]==a[lred]) dp[i][i][lblue]=max(dp[i][i][lblue], dp[i-1][lred][lblue]+a[i]);
    				else dp[i][i][lblue]=max(dp[i][i][lblue], dp[i-1][lred][lblue]);
    				ans=max(ans,dp[i][i][lblue]);
    				if(a[i]==a[lblue])dp[i][lred][i]=max(dp[i][lred][i], dp[i-1][lred][lblue] +a[i]);
    				else dp[i][lred][i]=max(dp[i][lred][i], dp[i-1][lred][lblue]);
    				ans=max(ans,dp[i][lred][i]);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
