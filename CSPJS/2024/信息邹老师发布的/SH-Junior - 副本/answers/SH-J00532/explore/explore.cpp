#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, m, k, x, y, d;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		char pos[1005][1005];
		bool book[1005][1005];
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> pos[i][j];
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) book[i][j] = 0;
		book[x][y] = 1;
		while (k--){
			if (d == 0){
				if (pos[x][y + 1] != '.') d = (d + 1) % 4;
				else y++;
			} else if (d == 1){
				if (pos[x + 1][y] != '.') d = (d + 1) % 4;
				else x++;
			} else if (d == 2){
				if (pos[x][y - 1] != '.') d = (d + 1) % 4;
				else y--;
			} else if (d == 3){
				if (pos[x - 1][y] != '.') d = (d + 1) % 4;
				else x--;
			} book[x][y] = 1;
		} long long ans = 0;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (book[i][j]) ans++;
		cout << ans << endl;
	} return 0;
}
