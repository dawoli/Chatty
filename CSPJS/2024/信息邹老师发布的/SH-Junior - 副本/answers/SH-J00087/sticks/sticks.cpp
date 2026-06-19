#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int s,T,a[55];
bool flag = 0,flag1 = 0;
string MAXN,dp[1005][1005],minn;
string b[8] = {"","","1","7","4","2","0","8"};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> T;
	for(int i = 1;i <= T;i++){
		cin >> a[i];
		s = max(s,a[i]);
		if(a[i] % 7 != 0) flag = 1;
		if(a[i] != (a[i] / 7) * 7 + 1) flag1 = 1;
	}
	if(!flag){
		for(int i = 1;i <= T;i++){
			for(int j = 1;j <= a[i] / 7;j++)
				cout << "8";
			cout << endl;
		}
		return 0;
	}
	if(!flag1){
		for(int i = 1;i <= T;i++){
			cout << "10";
			for(int j = 1;j <= a[i] / 7 - 1;j++)
				cout << "8";
			cout << endl;
		}
		return 0;
	}
	for(int i = 1;i <= s / 2;i++)
		MAXN = MAXN + "9";
	for(int i = 0;i <= s;i++)
		for(int j = 0;j <= s;j++)
			dp[i][j] = MAXN;
	dp[1][2] = "1";
	dp[1][5] = "2";
	dp[1][6] = "6";
	dp[1][4] = "4";
	dp[1][3] = "7";
	dp[1][7] = "8";
	for(int i = 2;i <= s / 2;i++){
		for(int j = s;j >= 2;j--){
			for(int k = 2;k <= min(7,j);k++){
				if(dp[i - 1][j - k] == MAXN) continue;
				if(dp[i - 1][j - k] + b[k] < dp[i][j]){
					dp[i][j] = dp[i - 1][j - k] + b[k];
				}
			}
		}
	}
	for(int i = 1;i <= T;i++){
		minn = MAXN;
		for(int j = 1;j <= s/2;j++){
			if(minn > dp[j][a[i]]){
				minn = dp[j][a[i]];
			}
			if(dp[j][a[i]] != MAXN) break;
		}
		if(minn != MAXN) cout << minn << endl;
		else cout << -1 << endl;
	}
	return 0;
}
