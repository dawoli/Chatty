#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int cnt[200];

long long dp[10010];

int main(){
	cnt[0] = 6;
	cnt[1] = 2;
	cnt[2] = 5;
	cnt[3] = 5;
	cnt[4] = 4;
	cnt[5] = 5;
	cnt[6] = 6;
	cnt[7] = 3;
	cnt[8] = 7;
	cnt[9] = 6;
	
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;
	
	for (int _ = 0; _ < T; _++){
		cin >> n;
		memset(dp, 0, sizeof(dp));
		
		dp[0] = 0;
		
		for (int i = 1; i <= n; i++){
			dp[i] = -1;
			for (int choice = 0; choice <= 9; choice++){
				int idx = i - cnt[choice];
				if (choice == 0 && dp[idx] == 0){
					continue;
				}
				if (idx >= 0 && idx <= n){
					if ((dp[idx] * 10 + choice < dp[i] || dp[i] == -1) && dp[idx] != -1){
						dp[idx] = max(dp[idx], (long long)(0));
						dp[i] = dp[idx] * 10 + choice;
					}
				}
			}
		}
		cout << dp[n] << endl;
	}
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
