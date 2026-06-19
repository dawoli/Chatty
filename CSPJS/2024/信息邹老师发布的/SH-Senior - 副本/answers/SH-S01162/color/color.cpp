#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+10, M = 1e6+10;
int n, a[N], dp[N], b[N], mxdp[M], ans, cnt, add;

signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		cnt = 0;
		ans = 0;
		add = 0;
		for(int i = 1; i <= n; i++){
			int ax;
			cin >> ax;
			if(ax == a[cnt]) add += ax;
			else {
				a[++cnt] = ax;
			}
		}
		for(int i = 1; i < M; i++) mxdp[i] = -i;
		for(int i = 1; i <= cnt; i++){
			dp[i] = max(dp[i-1],mxdp[a[i]]+a[i]);
			mxdp[a[i-1]] = max(mxdp[a[i-1]],dp[i]);
		}
		for(int i = 1; i <= cnt; i++) ans = max(ans,dp[i]);
		cout << ans+add << endl;
		ans = 0;
	}
}
