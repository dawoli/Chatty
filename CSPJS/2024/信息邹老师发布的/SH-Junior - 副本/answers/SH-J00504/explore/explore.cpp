#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m, k, x, y, d, ans, mp[1010][1010];
bool vis[1010][1010];
char c;

signed main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				cin >> c;
				vis[i][j] = false;
				if(c == 'x') mp[i][j] = 1;
				else mp[i][j] = 0;
			}
		}
		ans = 0;
		vis[x][y] = true;
		
		while(k--) {
			int p, q;
			if(d == 0) p = x, q = y + 1;
			if(d == 1) p = x + 1, q = y;
			if(d == 2) p = x, q = y - 1;
			if(d == 3) p = x - 1, q = y;
			if(mp[p][q] == 1 || p < 1 || q < 1 || p > n || q > m) d = (d + 1) % 4;
			else x = p, y = q, vis[x][y] = true;
			//cout << x << " " << y << endl;
		}
		
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				if(vis[i][j] == true) ans++;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
