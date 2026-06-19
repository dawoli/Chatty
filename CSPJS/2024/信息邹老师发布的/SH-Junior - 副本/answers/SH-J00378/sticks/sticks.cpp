#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int t, stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long dp[maxn], w[maxn];

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	memset(dp, 0x00, sizeof(dp));
	while(t--){
		int n;
		cin >> n;
		for(int i = 0;i<=n;i++){
			if(i <= 1) dp[i] = 1e9;
			long long res = 1e9;
			for(int j = 0;j<10;j++){
				if(j == 0 && i == n) continue;
				if(stick[j] > i) continue;
				if(stick[j] == i){
					if(j < res){
						w[i] = 1;
						res = j;
					}
				}
				if(stick[j] < i){
					long long nf = j*pow(10, w[i-stick[j]])+dp[i-stick[j]];
					//cout << j << " " << nf << endl;
					if(nf < res){
						w[i] = w[i-stick[j]]+1;
						res = nf;
					}
				}
			}
			dp[i] = res;
			//cout << i << " " << dp[i] << endl;
		}
		if(dp[n] == 1e9) cout << -1 << endl;
		else cout << dp[n] << endl;
	}
	return 0;
}
