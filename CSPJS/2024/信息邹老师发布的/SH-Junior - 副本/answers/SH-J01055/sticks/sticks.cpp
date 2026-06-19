# include<bits/stdc++.h>
using namespace std;
int arr[10] {6,2,5,5,4,5,6,3,7,6};

unsigned long long dp[100005];
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		if(n%7==0){
			for(;n;n-=7){
				cout << "8";
			}
			cout << endl;
			continue;
		}
		if(n<=1)cout << -1 << endl;
		if(n<=1)continue;
		memset(dp,ULLONG_MAX,sizeof(dp));
		dp[0] = dp[1] = 0;
		dp[2] = 1;
		dp[3] = 7;
		dp[4] = 4;
		dp[5] = 2;
		dp[6] = 6;
		dp[7] = 8;
		dp[8] = 26;
		dp[9] = 28;
		for(int i = 10; i <= n; i++) {
			for(int j = 0; j < 10; j++) {
				if(i==6&&j==0)continue;
				if(arr[j]<=i)
					dp[i] = min(dp[i],dp[i-arr[j]]*10+j);
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}
