#include<bits/stdc++.h>
using namespace std;
#define int long long
//point 1~20
#define MOD 998244353

#define N 5005
int a[N], dp[12502505];

int read(){
	char c = getchar(), res = 0;
	while('0' > c || '9' < c){
		c = getchar();
	}
	while('0' <= c && '9' >= c){
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}

signed main(){
//	freopen("polyon.in", "r", stdin);
//	freopen("polyon.out", "w", stdout);
	int n = read(), s = 0;
	for(int i = 1;i <= n;i++){
		a[i] = read();
	}
	for(int i = 1;i < n;i++){
		s += a[i];
	}
	sort(a + 1, a + 1 + n);
	if(a[n] == 1){//point 15~20
		int ans = 0;
		for(int i = 3;i <= n;i++){//length
			ans += n - i + 1;
			ans %= MOD;
		}
		cout << ans;
	}else{//point 1~25 O(n\max a_i^2)
		int ans = 0;
		dp[0] = 1;
		for(int i = 1;i < n;i++){//prevent the application from adding again in order to avoid making mistakes
			for(int j = s;j >= a[i];j--){
				dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
			}
			
			for(int j = a[i + 1] + 1;j <= s;j++){
				ans = (ans + dp[j]) % MOD;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
