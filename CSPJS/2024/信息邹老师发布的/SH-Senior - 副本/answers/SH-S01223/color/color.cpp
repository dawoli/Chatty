#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[210000];
int dp[210000];
int b[210000];
int tmp[1100000];
signed main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<=n+1;i++) a[i] = b[i] = dp[i] = 0;
		for(int i=0;i<=1000000;i++) tmp[i] = -1e16;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)b[i] = b[i-1] + (a[i] == a[i-1] ? a[i] : 0);
		a[0] = -1;
		int mx = 0;
		for(int i=1;i<=n;i++){
//			dp[i] = 0;
//			for(int j=0;j<i;j++){
//				dp[i] = max(dp[i], dp[j] + (a[i+1]==a[j] ? a[j] : 0) + b[i] - b[j+1]);
//			}
			dp[i] = max(mx + b[i], tmp[a[i+1]] + b[i] + a[i+1]);
			mx = max(mx, dp[i] - b[i+1]);
			tmp[a[i]] = max(tmp[a[i]], dp[i] - b[i+1]);
	//		cout << i << ' ' <<dp[i] << endl;
		}
		cout << dp[n] <<endl;
	}
}
