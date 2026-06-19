#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d;
bool vis[1005][1005];
char mp[1005][1005];
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--) {
		memset(vis, 0, sizeof vis);
		memset(mp, 0, sizeof mp);
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				cin >> mp[i][j];
			}
		}
		vis[x][y] = 1;
		while(k--) {
			int nx = x + dx[d], ny = y + dy[d];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.') {
				x = nx;
				y = ny;
			} 
			else {
				d = (d + 1) % 4;
			}
			vis[x][y] = 1;
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(vis[i][j]) {
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
// LIST OF ACCOUNTS TO ORZ
// ORZ JXY2011 
// ORZ LITTLEACBG
// ORZ LIAOYANXU
// ORZ COMPOSITE_FUNCTION
// ORZ TIANTIAN2021

// luogu account : 
// input this string into nutrimatic.org : nA{1,}ification
// choose one among all the result, for example a string s
// then change s into all capital letters
// change all the 'I' in s to '1', 'O' to '0'
// then the username is __ s __, where the s represents the string s after all the above operations
// for example : s = notification
// then the username is __N0T1F1CAT10N__ but it's wrong
// some guesses may be required

// SOLUTION :
// Obviously every J T2 should be easy.
// Simply doing the things the problem asked you to do is ok.
