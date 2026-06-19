#include<bits/stdc++.h>
using namespace std;
#define int long long

string sk[100];
int n, res, dp[110], mxn, resi, v[10] = {6,2,5,5,4,5,6,3,7,6}, rp;
int np[10] = {8,0,1,2,4,7};

void dfs(int v,int x){
	if(v > 100) return;
	if(x > dp[v]) return;
	dp[v] = min(dp[v],x);
}

signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	for(int i = 1; i <= 9; i++) dfs(v[i],i);
	dp[2] = 1, dp[3] = 7, dp[4] = 4, dp[5] = 2, dp[6] = 6, dp[7] = 8;
	for(int i = 2; i <= 100; i++){
		for(int j = 0; j <= 5; j++){
			if(i+v[np[j]] <= 100)
				dp[i+v[np[j]]] = min(dp[i+v[np[j]]],dp[i]*10+np[j]);
		}
	}
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		if(n == 1){
			cout << -1 << "\n";
			continue;
		}
		if(n <= 100){
			cout << dp[n] << "\n";
			continue;
		}
		rp = (n-49) % 49 + 49;
		cout << dp[rp];
		n -= rp;
		n /= 7;
		for(int i = 1; i <= n; i++) cout << 8;
		cout << "\n";
	}
}
