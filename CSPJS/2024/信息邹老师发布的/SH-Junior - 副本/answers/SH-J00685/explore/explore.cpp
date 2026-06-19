#include <bits/stdc++.h>
using namespace std;

int q;
char a[1005][1005];
bool flag[1005][1005];

int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> q;
	while(q--) {
		memset(flag,false,sizeof(flag));
		int n,m,k;
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		int x0,y0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		for(int i = 1; i <= k; i++) {
			flag[x][y] = true;
			if(d == 0) {
				x0 = x;
				y0 = y + 1;
			}
			if(d == 1) {
				x0 = x + 1;
				y0 = y;
			}
			if(d == 2) {
				x0 = x;
				y0 = y - 1;
			}
			if(d == 3) {
				x0 = x - 1;
				y0 = y;
			}
			if(x0 <= 0 || x0 > n || y0 <= 0 || y0 > m || a[x0][y0] == 'x') {
				d = (d + 1) % 4;
				continue;
			}
			x = x0,y = y0;
		}
		int ans = 0;
		flag[x][y] = true;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(flag[i][j]) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
