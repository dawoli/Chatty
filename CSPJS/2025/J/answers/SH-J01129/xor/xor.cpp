#include <bits/stdc++.h>
using namespace std;
//#define int long long
int n,k;
int a[500500];
int sum[500500];
int dp[500500];
map<int,int> mp;
map<int,bool> cnt;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
	}
	cnt[0]=1;
//	for(int i = 1;i <= n;i++) cout << sum[i] << " ";
	for(int i = 1;i <= n;i++) {
		dp[i]=dp[i-1];
		int Target = k^sum[i];
		if(cnt[Target]) dp[i]=max(dp[i],mp[Target]+1);
		cnt[sum[i]]=1;
		mp[sum[i]]=max(mp[sum[i]],dp[i]);
	}
//	for(int i = 1;i <= n;i++) cout << dp[i] << " ";
//	cout << endl;
	cout << dp[n] << endl;
	return 0;
}
