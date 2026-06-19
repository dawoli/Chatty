#include<bits/stdc++.h>
using namespace std;

int t;
string dp[100005];

bool cmps(string a, string b){
	if (a.size() < b.size()) return true;
	else if (a.size() > b.size()) return false;
	return a < b;
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		dp[0]="-1"; dp[1]="-1"; dp[2]="1"; dp[3]="7"; dp[4]="4"; dp[5]="2"; dp[6]="0"; dp[7]="8";
		for (int i = 8; i <= n; i ++){
			dp[i] = "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
			for (int j = 2; j <= 7; j ++){
				if (dp[i-j] != "-1" && dp[i-j] != "0"){
					if (cmps(dp[i-j] + dp[j], dp[i])) dp[i] = dp[i-j] + dp[j];
				}
			}
		}
		if (n == 6) cout << 6 << endl;
		else{
			if (n % 7 == 0 && n >= 100){
				string a = "";
				for (int i = 1; i <= n/7; i ++){
					a = a + "8";
				}
				if (cmps(a, dp[n])) cout << a << endl; 
			}else{
				cout << dp[n] << endl;
			}
		}
	}
}
