#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 205
#define M 100005 
ll t, n, a[M][3], b[M], dp[2][N][N][N], ans;
void solveBF(){
	for(ll l = 0; l <= 1; l++){
		for(ll i = 0; i <= n / 2; i++){
			for(ll j = 0; j <= n / 2; j++){
				for(ll k = 0; k <= n / 2; k++){
					dp[l][i][j][k] = -1e9;
				}
			}
		}
	}
	dp[0][0][0][0] = 0;
	for(ll l = 1; l <= n; l++){
		for(ll i = 0; i <= n / 2; i++){
			for(ll j = 0; j <= n / 2; j++){
				for(ll k = 0; k <= n / 2; k++){
					if(i == 0 && j == 0 && k == 0) continue;
					if(i) dp[l % 2][i][j][k] = max(dp[l % 2][i][j][k], dp[(l - 1) % 2][i - 1][j][k] + a[l][1]);
					if(j) dp[l % 2][i][j][k] = max(dp[l % 2][i][j][k], dp[(l - 1) % 2][i][j - 1][k] + a[l][2]);
					if(k) dp[l % 2][i][j][k] = max(dp[l % 2][i][j][k], dp[(l - 1) % 2][i][j][k - 1] + a[l][3]);
				}
			}
		}
	}
	ans = 0;
	for(ll i = 0; i <= n / 2; i++){
		for(ll j = 0; j <= n / 2; j++){
			for(ll k = 0; k <= n / 2; k++){
				if(i + j + k != n) continue;
				ans = max(ans, dp[0][i][j][k]);
			}
		}
	}
	cout << ans << endl;
}
void solveA(){
	ans = 0;
	for(ll i = 1; i <= n; i++) b[i] = a[i][1];
	sort(b+1, b+n+1);
	for(ll i = n; i >= n / 2; i++){
		ans += b[i];
	}
	cout << ans << endl;
}
void solveB(){
	for(ll l = 0; l <= 1; l++){
		for(ll i = 0; i <= n / 2; i++){
			for(ll j = 0; j <= n / 2; j++){
				for(ll k = 0; k <= 0; k++){
					dp[l][i][j][k] = -1e9;
				}
			}
		}
	}
	dp[0][0][0][0] = 0;
	for(ll l = 1; l <= n; l++){
		for(ll i = 0; i <= n / 2; i++){
			for(ll j = 0; j <= n / 2; j++){
				for(ll k = 0; k <= 0; k++){
					if(i == 0 && j == 0 && k == 0) continue;
					if(i) dp[l % 2][i][j][k] = max(dp[l % 2][i][j][k], dp[(l - 1) % 2][i - 1][j][k] + a[l][1]);
					if(j) dp[l % 2][i][j][k] = max(dp[l % 2][i][j][k], dp[(l - 1) % 2][i][j - 1][k] + a[l][2]);
					if(k) dp[l % 2][i][j][k] = max(dp[l % 2][i][j][k], dp[(l - 1) % 2][i][j][k - 1] + a[l][3]);
				}
			}
		}
	}
	ans = 0;
	for(ll i = 0; i <= n / 2; i++){
		for(ll j = 0; j <= n / 2; j++){
			for(ll k = 0; k <= 0; k++){
				if(i + j < n / 2) continue;
				ans = max(ans, dp[0][i][j][k]);
			}
		}
	}
	cout << ans << endl;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		bool A = 1, B = 1;
		cin >> n;
		for(ll i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][3]) A = B = 0;
			if(a[i][2]) A = 0;
		}
		if(A){
			solveA();
		}else if(B){
			solveB();
		}else{
			solveBF();
		}
	}
	return 0;
} 
