#include <bits/stdc++.h>
using namespace std;

int n, a[100010][4], t[100010], v[100010], dp[110][110][110];
int ans;
bool flaga, flagb;

//void dfs(int step, int c1, int c2, int c3, int sum){
//	if (max(max(c1, c2), c3) > n/2) return;
//	if (step > n){
//		ans = max(ans, sum);
//		return;
//	}
//	dfs(step+1, c1+1, c2, c3, sum+a[step][1]);
//	dfs(step+1, c1, c2+1, c3, sum+a[step][2]);
//	dfs(step+1, c1, c2, c3+1, sum+a[step][3]);
//}

bool cmp(int s, int t){
	return s > t;
}

void solve(){
	flaga = true; flagb = true;
	ans = 0;
	memset(a, 0, sizeof a);
	memset(t, 0, sizeof t);
	memset(v, 0, sizeof v);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (a[i][2] || a[i][3])
			flaga = false;
		if (a[i][3])
			flagb = false;
	}
	if (n <= 200){
//		cout << 3 << " ";
		memset(dp, 0, sizeof dp);
		for (int i = 0; i <= n/2; i++){
			for (int j = 0; j <= n/2; j++){
				for (int k = 0; k <= n/2; k++){
					if (i+j+k > n) continue;
					if (i!=0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]+a[i+j+k][1]);
					if (j!=0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]+a[i+j+k][2]);
					if (k!=0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]+a[i+j+k][3]);
					if (i+j+k == n) ans = max(ans, dp[i][j][k]);
				}
			}
		}
		cout << ans << endl;
	} else if (flaga){
//		cout << 1 << " ";
		for (int i = 1; i <= n; i++){
			t[i] = a[i][1];
		}
		sort(t+1, t+n+1, cmp);
		for (int i = 1; i <= n/2; i++){
			ans += t[i];
		}
		cout << ans << endl;
	} else if (flagb){
//		cout << 2 << " ";
		for (int i = 1; i <= n; i++){
			t[i] = a[i][1];
			v[i] = a[i][2];
		}
		sort(t+1, t+n+1, cmp);
		sort(v+1, v+n+1, cmp);
		for (int i = 1; i <= n/2; i++){
			ans += t[i]+v[i];
		}
		cout << ans << endl;
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}

