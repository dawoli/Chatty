#include <bits/stdc++.h>
using namespace std;
int T, n;
bool flag = false;
string ans = "", dp[100005];
int numcnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

bool check(string ans, string num){
	if(ans.size() != num.size()) return ans.size() > num.size();
	for(int i = 0; i < ans.size(); i++)
		if(ans[i] != num[i]) return ans[i] > num[i];
	return true;
}

string to_string(int i){
	if(i == 0) return "0";
	else if(i == 1) return "1";
	else if(i == 2) return "2";
	else if(i == 3) return "3";
	else if(i == 4) return "4";
	else if(i == 5) return "5";
	else if(i == 6) return "6";
	else if(i == 7) return "7";
	else if(i == 8) return "8";
	else return "9";
}
 
void dfs(int now, string num, bool flag0){
	if(now > n) return;
	if(now == n){
		flag = true;
		if(check(ans, num)) ans = num;
		return;
	}
	for(int i = 0; i <= 9; i++){
		if(!flag0 && i == 0) continue;
		dfs(now+numcnt[i], num+to_string(i), true);
	}
}

int main(){
	freopen("sticks1.in", "r", stdin);
	//freopen("sticks.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		ans = "";
		int tmp = 125000;
		while(tmp--) ans += '8';
		if(n >= 20){
			dfs(0, "", false);
			if(!flag) cout << -1 << endl;
			else cout << ans << endl;
			continue;
		}
		for(int i = 1; i <= n; i++) dp[i] = ans;
		dp[2] = "1", dp[3] = "7", dp[4] = "4", dp[5] = "2", dp[6] = "6", dp[7] = "8";
		for(int i = 8; i <= n; i++){
			for(int j = 2; j <= 7; j++)
				if(check(dp[i], dp[i-j])){
					if(j == 6) dp[i] = dp[i-j] + '0';
					else dp[i] = dp[i-j] + dp[j];
				}
		}
		if(dp[n] == ans) cout << -1 << endl;
		else cout << dp[n] << endl;
	}
	
	return 0;
}
