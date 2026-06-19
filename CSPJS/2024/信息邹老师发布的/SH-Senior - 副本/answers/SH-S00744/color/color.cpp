#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 20005
using namespace std;
int T;

int n;
int a[N];
ll dp[N];
int same[N];

void solve(){
	memset(dp,0,sizeof dp);
	memset(same,0,sizeof same);
	scanf("%d",&n);
	a[-1]=-111;
	for (int i = 1; i <=n; ++i){
		scanf("%d",&a[i]);
	}
	for (int i = 1; i <= n; ++i){
		dp[i]=dp[i-1];
		for (int j = 1; j < i; ++j){
			if (a[i]!=a[j])continue;
			dp[i]=max(dp[i],dp[j]+same[j+1]+a[i]);
		}
		if (a[i]==a[i-1]){
		for (int j = 1; j <= i; ++j){
			same[j]+=a[i];
		}
	}
	}
	
	printf("%lld\n",dp[n]);

}


signed main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);

	int t;
	scanf("%d",&t);
	for (T = 1; T <= t; ++T){
		solve();
	}
}