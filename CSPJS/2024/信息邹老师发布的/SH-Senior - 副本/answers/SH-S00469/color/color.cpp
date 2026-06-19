#include<bits/stdc++.h>
using namespace std;
long long t, n, a[200010], f[200010], dp[200010], lan[1000010], pre[200010];
void solve(){
	scanf("%lld", &n);
	memset(lan, 0, sizeof lan);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		f[i] = f[i - 1] + a[i] * (a[i] == a[i - 1]);
		pre[i] = lan[a[i]];
		lan[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		if(pre[i] == 0){
			dp[i] = dp[i - 1];
			continue;
		}
		else if(pre[i] == i - 1){
			dp[i] = dp[pre[i]] + a[i];
		}
		else{
			dp[i] = max(dp[pre[i] + 1] + a[i] + f[i - 1] - f[pre[i] + 1], dp[i - 1]);
		}
	}
	printf("%lld\n", dp[n]);
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &t);
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
