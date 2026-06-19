#include <bits/stdc++.h>
#define N 202
#define ll long long
using namespace std;

int T;
int n;
int a[N][3];
ll dp[N][N][N];

void init(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		for (int j = 1; j <= 3; ++j){
			scanf("%d",&a[i][j]);
		}
	}

}

void solve(){
	memset(dp,0,sizeof dp);
	for (int i = 1; i <= n; ++i){
		for (int v1 = 0; v1 <= n/2; ++v1){
			for (int v2 = 0; v2 <= min(n/2,i-v1); ++v2){
				if (i-v1-v2 >= n/2 or i-v1-v2<0)continue;
				if (i-v1-v2 >= 1)
					dp[i][v1][v2]=max(dp[i][v1][v2],
						dp[i-1][v1][v2]+a[i][3]);
				if (v1>=1)
					dp[i][v1][v2]=max(dp[i][v1][v2],
						dp[i-1][v1-1][v2]+a[i][1]);
				if (v2>=1)
					dp[i][v1][v2]=max(dp[i][v1][v2],
						dp[i-1][v1][v2-1]+a[i][2]);
			}
		}
	}
	ll ans = 0;
	for (int v1 = 0; v1 <= n/2; ++v1){
		for (int v2 = 0; v2 <= n/2; ++v2){
			if (n-v1-v2 >= n/2)continue;
			ans = max(ans,dp[n][v1][v2]);
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	scanf("%d",&T);

	while (T--){
		init();
		solve();
	}

}