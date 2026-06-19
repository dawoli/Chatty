#include<bits/stdc++.h>
using namespace std;
char ct[1001][1001];
bool play[1001][1001] = {false};
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int n,m,k;
		int cnt = 0;
		cin >> n >> m >> k;
		int x,y,v;
		cin >> x >> y >> v;
		for(int j = 1; j <= n; j++) {
			string s;
			cin >> s;
			for(int p = 0; p < s.size(); p++) {
				ct[j][p + 1] = s[p];
			}
		}
		play[x][y] = true;
		for(int j = 1; j <= k;j++) {
			v %= 4;
//			cout << v << endl;
			if(v == 0) {
				if(ct[x][y+1] == 'x' || y == m) {
					v++;
					continue;
				} else {
					y++;
					play[x][y] = true;
					continue;
				}
			}if(v == 1) {
				if(ct[x+1][y] == 'x' || x == n) {
					v++;
					continue;
				} else {
					x++;
					play[x][y] = true;
					continue;
				}
			}if(v == 2) {
				if(ct[x][y-1] == 'x' || y == 1) {
					v++;
					continue;
				} else {
					y--;
					play[x][y] = true;
					continue;
				}
			}if(v == 3) {
				if(ct[x-1][y] == 'x' || x == 1) {
					v++;
					continue;
				} else {
					x--;
					play[x][y] = true;
					continue;
				}
			}
		}
		for(int j = 1; j <= n;j++) {
			for(int p = 1; p <= m; p++) {
				if(play[j][p] == true) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
