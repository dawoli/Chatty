#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
ll T, n, m, k, x00, y00, d00;
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
char maze[1001][1001];
bool vst[1001][1001];
bool valid(ll x, ll y){
	if (x <= 0 || x > n){
		return 0;
	}
	if (y <= 0 || y > m){
		return 0;
	}
	if (maze[x][y] == 'x'){
		return 0;
	}
	return 1;
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%lld", &T);
	for (ll asd = 1;asd <= T;asd++){
		memset(vst, 0, sizeof(vst));
		ll ans = 0;
		scanf("%lld%lld%lld", &n, &m, &k);
		scanf("%lld%lld%lld", &x00, &y00, &d00);
		vst[x00][y00] = 1;
		for (ll i = 1;i <= n;i++){
			for (ll j = 1;j <= m;j++){
				cin >> maze[i][j];
			}
		}
		for (ll i = 1;i <= k;i++){
			if (valid(x00 + dx[d00], y00 + dy[d00])){
				x00 += dx[d00];
				y00 += dy[d00];
				vst[x00][y00] = 1;
			}else{
				d00 = (d00 + 1) % 4;
			}
		}
		for (ll i = 1;i <= n;i++){
			for (ll j = 1;j <= m;j++){
				if (vst[i][j]){
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
