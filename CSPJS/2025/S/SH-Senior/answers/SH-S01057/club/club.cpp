#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005][4],dp[5005][5005],t,n,ans,sum,b[4];

void dfs(int step){
	if(step == n+1){
		ans = max(ans,sum);
		return;
	}
	for(int i=1;i <= 3;i++)
	if(b[i] < n/2){
		b[i]++;
		sum += a[step][i];
		dfs(step + 1);
		b[i]--;
		sum -= a[step][i];
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	while(t--){
		memset(dp,0,sizeof(dp));
		ans = -1;
		cin >> n;
		for(int i=1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1);
//		for(int i=1;i <= n;i++)
//			for(int j=n/2;j >= 1;j--)
//				for(int k=n/2;k >= 1;k--){
//					dp[j][k] = max(dp[j-1][k]+a[i].a,dp[j][k-1]+a[i].b);
//					if(i-j-k <= n/2) dp[j][k] = max(dp[j][k],dp[j][k]+a[i].c);
//					ans = max(ans,dp[j][k]);
//				}
		cout << ans << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
