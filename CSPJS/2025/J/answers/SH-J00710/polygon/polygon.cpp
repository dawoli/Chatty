#include<bits/stdc++.h>

using namespace std;
const int N = 5e3+40;
int n, a[N], dp1[5005][5005], dp2[5005][5005];
int mod = 998244353, maxa = 0, ans;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxa = max(maxa, a[i]);
//		s[i] = s[i-1]+a[i];
	}
	sort(a+1, a+n+1);
	dp1[0][0] = 1; dp2[0][0] = 1;
	for(int i = 1; i <= n; i++){
		dp2[0][i] = 2*dp2[0][i-1]; dp1[0][i] = 1;
	} 
//	cout << maxa << endl;
	for(int i = 1; i <= maxa; i++){
		for(int j = 1; j < n; j++){
			if(a[j] > i){
				dp1[i][j] = dp1[i][j-1];
				dp2[i][j] = dp2[i][j-1]*2+1;
			}else{
				dp1[i][j] = dp1[i][j-1]+dp1[i-a[j]][j-1];
				dp1[i][j] %= mod;
				dp2[i][j] = dp2[i-a[j]][j-1]+dp2[i][j-1];
				dp2[i][j] %= mod;
			}
//			cout << dp2[i][j] << " ";
		}
//		cout << "\n";
	}
	for(int i = 3; i <= n; i++){
		ans += dp2[a[i]][i-1]-dp1[a[i]][i-1];
		ans %= mod;
	}
	cout << ans;
	return 0;
}
