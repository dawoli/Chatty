#include <bits/stdc++.h>
using namespace std;

int sum[500005];
int a[500005];
int dp[20005][20005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k; 
	cin >> n >> k;
	for(int i = 1; i <= n; i++){ 
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		int sum_ = 0;
		for(int j = i; j <= n; j++){
			sum_ = sum_ ^ a[j];
			if(sum_ == k){
				dp[i][j] = 1;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			for(int k = i; k < j; k++){
				dp[i][j] = max(dp[i][j],
				dp[i][k] + dp[k + 1][j]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
} 
