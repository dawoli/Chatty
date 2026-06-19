#include <bits/stdc++.h>
using namespace std;
#define N 1010
int t, n, m, k, x, y, d;
char mp[N][N];
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout); 
	cin >> t;
	while(t--) {
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) cin >> mp[i][j];
		while(k--) {
			mp[x][y] = '/';
			int x1 = x, y1 = y;
			if(d == 0) y1++;
			if(d == 1) x1++;
			if(d == 2) y1--;
			if(d == 3) x1--;
			if(1 > x1 || x1 > n || 1 > y1 || y1 > m) d = (d + 1) % 4;
			else if(mp[x1][y1] == 'x') d = (d + 1) % 4;
			else x = x1, y = y1;
		}
		mp[x][y] = '/';
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				ans += (mp[i][j] == '/');
		cout << ans << endl;
	}
	return 0;
}

