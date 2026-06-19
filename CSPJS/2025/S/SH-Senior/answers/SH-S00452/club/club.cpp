#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MAXN = 1e5 + 5;
ll T, n, a[MAXN][3], f[200 + 5][100 + 5][100 + 5];
void solve(){
	cin >> n;
	for(int i  = 1; i <= n; i++)cin >> a[i][1] >> a[i][2] >> a[i][3];
	f[1][1][0] = a[1][1];
	f[1][0][1] = a[1][2];
	f[1][0][0] = a[1][3];
	for(int i = 2; i <= n; i++)
		for(int j = 0; j <= n / 2; j++)
			for(int k = 0; k <= n / 2; k++)
				if(0 <= i - j - k && i - j - k <= n / 2){
					f[i][j][k] = max((j - 1 >= 0 ? f[i - 1][j - 1][k] + a[i][1] : 0), max((k - 1 >= 0 ? f[i - 1][j][k - 1] + a[i][2] : 0), (i - 1 - j - k >= 0 ? f[i - 1][j][k] + a[i][3] : 0)));
					// cout << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << endl;
				}
	ll ans = 0;
	for(int j = 0; j <= n / 2; j++)
		for(int k = 0; k <= n / 2; k++)
			if(0 <= n - j - k && n - j - k <= n / 2)
				ans = max(ans, f[n][j][k]);
	cout << ans << endl;
}
signed main(){
	cin.tie(0) -> sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
